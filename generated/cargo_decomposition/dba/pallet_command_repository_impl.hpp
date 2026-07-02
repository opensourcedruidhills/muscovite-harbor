#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "pallet_command_repository.hpp"
#include "cargo_decomposition_queries.hpp"
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

/// pqxx-based command repository implementation for Pallet aggregate.
/// Uses embedded SQL constants from cargo_decomposition_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class PalletCommandRepositoryImpl : public PalletCommandRepository {
public:
    explicit PalletCommandRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const Pallet& entity) -> void override {
        DbaOperationSpan span("PalletCommandRepositoryImpl::save");
        auto tx = conn_.begin();
        tx.exec_params(queries::PalletUpsert,
            entity.id, entity.pallet_id, entity.container_id, entity.weight_kg, entity.length_cm, entity.width_cm, entity.height_cm, entity.hs_code);
        tx.commit();
        span.set_status_ok();
    }

    auto update(const Pallet& entity) -> void override {
        DbaOperationSpan span("PalletCommandRepositoryImpl::update");
        auto tx = conn_.begin();
        tx.exec_params(queries::PalletUpdate,
            entity.id, entity.pallet_id, entity.container_id, entity.weight_kg, entity.length_cm, entity.width_cm, entity.height_cm, entity.hs_code);
        tx.commit();
        span.set_status_ok();
    }

    auto remove(const Pallet::Id& id) -> void override {
        DbaOperationSpan span("PalletCommandRepositoryImpl::remove");
        auto tx = conn_.begin();
        tx.exec_params(queries::PalletDelete, id);
        tx.commit();
        span.set_status_ok();
    }

    [[nodiscard]] auto find_by_id(const Pallet::Id& id) -> std::optional<Pallet> override {
        DbaOperationSpan span("PalletCommandRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::PalletSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        const auto& row = result[0];
        auto entity = Pallet{
            .id = row[0].as<std::string>(),
            .pallet_id = row[1].as<std::string>(),
            .container_id = row[2].as<boost::uuids::uuid>(),
            .weight_kg = row[3].as<muscovite::dba::Decimal>(),
            .length_cm = row[4].as<muscovite::dba::Decimal>(),
            .width_cm = row[5].as<muscovite::dba::Decimal>(),
            .height_cm = row[6].as<muscovite::dba::Decimal>(),
            .hs_code = row[7].as<std::string>(),
        };
        span.set_status_ok();
        return entity;
    }

private:
    Connection& conn_;
;

} // namespace cargo_decomposition
