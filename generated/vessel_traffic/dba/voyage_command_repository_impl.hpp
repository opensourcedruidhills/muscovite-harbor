#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "voyage_command_repository.hpp"
#include "vessel_traffic_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>

namespace vessel_traffic {

class DbaOperationSpan {
public:
    explicit DbaOperationSpan(std::string_view operation) : operation_{operation} {}
    auto set_status_ok() noexcept -> void {}
    auto set_error(std::string_view /*message*/) noexcept -> void {}
private:
    std::string_view operation_;
};

/// pqxx-based command repository implementation for Voyage aggregate.
/// Uses embedded SQL constants from vessel_traffic_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class VoyageCommandRepositoryImpl : public VoyageCommandRepository {
public:
    explicit VoyageCommandRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const Voyage& entity) -> void override {
        DbaOperationSpan span("VoyageCommandRepositoryImpl::save");
        auto tx = conn_.begin();
        tx.exec_params(queries::VoyageUpsert,
            entity.id, entity.vessel_id, entity.berth_id, entity.voyage_number, entity.eta, entity.ata, entity.etd, entity.atd, entity.cargo_category, entity.status);
        tx.commit();
        span.set_status_ok();
    }

    auto update(const Voyage& entity) -> void override {
        DbaOperationSpan span("VoyageCommandRepositoryImpl::update");
        auto tx = conn_.begin();
        tx.exec_params(queries::VoyageUpdate,
            entity.id, entity.vessel_id, entity.berth_id, entity.voyage_number, entity.eta, entity.ata, entity.etd, entity.atd, entity.cargo_category, entity.status);
        tx.commit();
        span.set_status_ok();
    }

    auto remove(const Voyage::Id& id) -> void override {
        DbaOperationSpan span("VoyageCommandRepositoryImpl::remove");
        auto tx = conn_.begin();
        tx.exec_params(queries::VoyageDelete, id);
        tx.commit();
        span.set_status_ok();
    }

    [[nodiscard]] auto find_by_id(const Voyage::Id& id) -> std::optional<Voyage> override {
        DbaOperationSpan span("VoyageCommandRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::VoyageSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        const auto& row = result[0];
        auto entity = Voyage{
            .id = row[0].as<std::string>(),
            .vessel_id = row[1].as<boost::uuids::uuid>(),
            .berth_id = row[2].as<boost::uuids::uuid>(),
            .voyage_number = row[3].as<std::string>(),
            .eta = row[4].as<muscovite::dba::Timestamp>(),
            .ata = row[5].as<muscovite::dba::Timestamp>(),
            .etd = row[6].as<muscovite::dba::Timestamp>(),
            .atd = row[7].as<muscovite::dba::Timestamp>(),
            .cargo_category = row[8].as<std::string>(),
            .status = row[9].as<std::string>(),
        };
        span.set_status_ok();
        return entity;
    }

private:
    Connection& conn_;
;

} // namespace vessel_traffic
