#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "voyage_command_repository.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace vessel_traffic {

/// pqxx-based command repository implementation for Voyage aggregate.
/// Uses direct parameterised SQL — no stored procedures (ADR 20260120).
template<typename Connection>
class VoyageCommandRepositoryImpl : public VoyageCommandRepository {
public:
    explicit VoyageCommandRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const Voyage& entity) -> void override {
        auto tx = conn_.begin();
        tx.exec_params("INSERT INTO vessel_traffic.voyage (id, id, vessel_id, berth_id, voyage_number, eta, ata, etd, atd, cargo_category, status) VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11) ON CONFLICT (id) DO UPDATE SET id = $2, vessel_id = $3, berth_id = $4, voyage_number = $5, eta = $6, ata = $7, etd = $8, atd = $9, cargo_category = $10, status = $11",
            entity.id, entity.id, entity.vessel_id, entity.berth_id, entity.voyage_number, entity.eta, entity.ata, entity.etd, entity.atd, entity.cargo_category, entity.status);
        tx.commit();
    }

    auto remove(const Voyage::Id& id) -> void override {
        auto tx = conn_.begin();
        tx.exec_params("DELETE FROM vessel_traffic.voyage WHERE id = $1", id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const Voyage::Id& id) -> std::optional<Voyage> override {
        auto tx = conn_.begin();
        auto result = tx.exec_params("SELECT id, id, vessel_id, berth_id, voyage_number, eta, ata, etd, atd, cargo_category, status FROM vessel_traffic.voyage WHERE id = $1", id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        const auto& row = result[0];
        return Voyage{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .vessel_id = row[2].as<std::string>(),
            .berth_id = row[3].as<std::string>(),
            .voyage_number = row[4].as<std::string>(),
            .eta = row[5].as<std::string>(),
            .ata = row[6].as<std::string>(),
            .etd = row[7].as<std::string>(),
            .atd = row[8].as<std::string>(),
            .cargo_category = row[9].as<std::string>(),
            .status = row[10].as<std::string>(),
        };
    }

private:
    Connection& conn_;
};

} // namespace vessel_traffic
