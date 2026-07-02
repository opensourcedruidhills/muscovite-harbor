#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "pallet.hpp"
#include "cargo_decomposition_queries.hpp"
#include <algorithm>
#include <iterator>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>

namespace cargo_decomposition {

class DbaOperationSpan {
public:
    explicit DbaOperationSpan(std::string_view operation) : operation_{operation} {}
    auto set_status_ok() noexcept -> void {}
    auto set_error(std::string_view /*message*/) noexcept -> void {}
private:
    std::string_view operation_;
};

/// Concrete CRTP repository implementation for Pallet.
/// Satisfies RepositoryBase<PalletRepositoryImpl<C>, Pallet> contract.
/// Uses embedded SQL constants from cargo_decomposition_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class PalletRepositoryImpl {
public:
    explicit PalletRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const Pallet& entity) -> void {
        DbaOperationSpan span("PalletRepositoryImpl::save");
        auto tx = conn_.begin();
        tx.exec_params(queries::PalletInsert, entity.id, entity.pallet_id, entity.container_id, entity.weight_kg, entity.length_cm, entity.width_cm, entity.height_cm, entity.hs_code);
        tx.commit();
        span.set_status_ok();
    }

    auto update(const Pallet& entity) -> void {
        DbaOperationSpan span("PalletRepositoryImpl::update");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::PalletUpdate, entity.id, entity.pallet_id, entity.container_id, entity.weight_kg, entity.length_cm, entity.width_cm, entity.height_cm, entity.hs_code);
        if (result.affected_rows() == 0) {
            span.set_error("not found");
            throw std::runtime_error("Pallet not found: " + entity.id);
        }
        tx.commit();
        span.set_status_ok();
    }

    auto remove(const std::string& id) -> void {
        DbaOperationSpan span("PalletRepositoryImpl::remove");
        auto tx = conn_.begin();
        tx.exec_params(queries::PalletDelete, id);
        tx.commit();
        span.set_status_ok();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<Pallet> {
        DbaOperationSpan span("PalletRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::PalletSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        auto mapped = map_row(result[0]);
        span.set_status_ok();
        return mapped;
    }

    [[nodiscard]] auto find_all() -> std::vector<Pallet> {
        DbaOperationSpan span("PalletRepositoryImpl::find_all");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::PalletSelectAll);
        tx.commit();
        auto out = std::vector<Pallet>{ };
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        span.set_status_ok();
        return out;
    }

    /// Filter all entities by a domain specification (in-memory).
    template<typename Spec>
    [[nodiscard]] auto filter_by_spec(const Spec& spec) const -> std::vector<Pallet> {
        auto all = find_all();
        auto result = std::vector<Pallet>{};
        std::copy_if(all.begin(), all.end(), std::back_inserter(result),
                     [&spec](const Pallet& e) { return spec.is_satisfied_by(e); });
        return result;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> Pallet {
        return Pallet{
            .id = row[0].as<std::string>(),
            .pallet_id = row[1].as<std::string>(),
            .container_id = row[2].as<boost::uuids::uuid>(),
            .weight_kg = row[3].as<muscovite::dba::Decimal>(),
            .length_cm = row[4].as<muscovite::dba::Decimal>(),
            .width_cm = row[5].as<muscovite::dba::Decimal>(),
            .height_cm = row[6].as<muscovite::dba::Decimal>(),
            .hs_code = row[7].as<std::string>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace cargo_decomposition
