#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "delivery_unit.hpp"
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

/// Concrete CRTP repository implementation for DeliveryUnit.
/// Satisfies RepositoryBase<DeliveryUnitRepositoryImpl<C>, DeliveryUnit> contract.
/// Uses embedded SQL constants from cargo_decomposition_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class DeliveryUnitRepositoryImpl {
public:
    explicit DeliveryUnitRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const DeliveryUnit& entity) -> void {
        DbaOperationSpan span("DeliveryUnitRepositoryImpl::save");
        auto tx = conn_.begin();
        tx.exec_params(queries::DeliveryUnitInsert, entity.id, entity.tracking_number, entity.destination, entity.carrier, entity.dispatched_at);
        tx.commit();
        span.set_status_ok();
    }

    auto update(const DeliveryUnit& entity) -> void {
        DbaOperationSpan span("DeliveryUnitRepositoryImpl::update");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::DeliveryUnitUpdate, entity.id, entity.tracking_number, entity.destination, entity.carrier, entity.dispatched_at);
        if (result.affected_rows() == 0) {
            span.set_error("not found");
            throw std::runtime_error("DeliveryUnit not found: " + entity.id);
        }
        tx.commit();
        span.set_status_ok();
    }

    auto remove(const std::string& id) -> void {
        DbaOperationSpan span("DeliveryUnitRepositoryImpl::remove");
        auto tx = conn_.begin();
        tx.exec_params(queries::DeliveryUnitDelete, id);
        tx.commit();
        span.set_status_ok();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<DeliveryUnit> {
        DbaOperationSpan span("DeliveryUnitRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::DeliveryUnitSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        auto mapped = map_row(result[0]);
        span.set_status_ok();
        return mapped;
    }

    [[nodiscard]] auto find_all() -> std::vector<DeliveryUnit> {
        DbaOperationSpan span("DeliveryUnitRepositoryImpl::find_all");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::DeliveryUnitSelectAll);
        tx.commit();
        auto out = std::vector<DeliveryUnit>{ };
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        span.set_status_ok();
        return out;
    }

    /// Filter all entities by a domain specification (in-memory).
    template<typename Spec>
    [[nodiscard]] auto filter_by_spec(const Spec& spec) const -> std::vector<DeliveryUnit> {
        auto all = find_all();
        auto result = std::vector<DeliveryUnit>{};
        std::copy_if(all.begin(), all.end(), std::back_inserter(result),
                     [&spec](const DeliveryUnit& e) { return spec.is_satisfied_by(e); });
        return result;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> DeliveryUnit {
        return DeliveryUnit{
            .id = row[0].as<std::string>(),
            .tracking_number = row[1].as<std::string>(),
            .destination = row[2].as<std::string>(),
            .carrier = row[3].as<std::string>(),
            .dispatched_at = row[4].as<muscovite::dba::Timestamp>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace cargo_decomposition
