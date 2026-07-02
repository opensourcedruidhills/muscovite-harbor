#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "parcel_command_repository.hpp"
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

/// pqxx-based command repository implementation for Parcel aggregate.
/// Uses embedded SQL constants from cargo_decomposition_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class ParcelCommandRepositoryImpl : public ParcelCommandRepository {
public:
    explicit ParcelCommandRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const Parcel& entity) -> void override {
        DbaOperationSpan span("ParcelCommandRepositoryImpl::save");
        auto tx = conn_.begin();
        tx.exec_params(queries::ParcelUpsert,
            entity.id, entity.tracking_number, entity.pallet_id, entity.weight_kg, entity.hs_code, entity.description);
        tx.commit();
        span.set_status_ok();
    }

    auto update(const Parcel& entity) -> void override {
        DbaOperationSpan span("ParcelCommandRepositoryImpl::update");
        auto tx = conn_.begin();
        tx.exec_params(queries::ParcelUpdate,
            entity.id, entity.tracking_number, entity.pallet_id, entity.weight_kg, entity.hs_code, entity.description);
        tx.commit();
        span.set_status_ok();
    }

    auto remove(const Parcel::Id& id) -> void override {
        DbaOperationSpan span("ParcelCommandRepositoryImpl::remove");
        auto tx = conn_.begin();
        tx.exec_params(queries::ParcelDelete, id);
        tx.commit();
        span.set_status_ok();
    }

    [[nodiscard]] auto find_by_id(const Parcel::Id& id) -> std::optional<Parcel> override {
        DbaOperationSpan span("ParcelCommandRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::ParcelSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        const auto& row = result[0];
        auto entity = Parcel{
            .id = row[0].as<std::string>(),
            .tracking_number = row[1].as<std::string>(),
            .pallet_id = row[2].as<boost::uuids::uuid>(),
            .weight_kg = row[3].as<muscovite::dba::Decimal>(),
            .hs_code = row[4].as<std::string>(),
            .description = row[5].as<std::string>(),
        };
        span.set_status_ok();
        return entity;
    }

private:
    Connection& conn_;
;

} // namespace cargo_decomposition
