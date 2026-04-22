#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "voyage_query_repository.hpp"
#include <cstdint>
#include <optional>
#include <stdexcept>
#include <string>
#include <vector>

namespace vessel_traffic {

/// pqxx-based query repository implementation for Voyage aggregate.
/// Uses direct parameterised SQL — no stored procedures (ADR 20260120).
template<typename Connection>
class VoyageQueryRepositoryImpl : public VoyageQueryRepository {
public:
    explicit VoyageQueryRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto find_by_id(const Voyage::Id& id) -> std::optional<Voyage> override {
        auto tx = conn_.begin();
        auto result = tx.exec_params("SELECT id, id, vessel_id, berth_id, voyage_number, eta, ata, etd, atd, cargo_category, status FROM vessel_traffic.voyage WHERE id = $1", id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<Voyage> override {
        auto tx = conn_.begin();
        auto result = tx.exec("SELECT id, id, vessel_id, berth_id, voyage_number, eta, ata, etd, atd, cargo_category, status FROM vessel_traffic.voyage ORDER BY id");
        tx.commit();
        auto out = std::vector<Voyage>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
    }

    [[nodiscard]] auto count() -> std::int64_t override {
        auto tx = conn_.begin();
        auto result = tx.exec("SELECT COUNT(*) FROM vessel_traffic.voyage");
        tx.commit();
        return result[0][0].as<std::int64_t>();
    }

    [[nodiscard]] auto find_by_vessels_by_eta(const muscovite::dba::Timestamp& from_eta, const muscovite::dba::Timestamp& to_eta) -> std::vector<Voyage> override {
        auto tx = conn_.begin();
        auto result = tx.exec_params("SELECT id, id, vessel_id, berth_id, voyage_number, eta, ata, etd, atd, cargo_category, status FROM vessel_traffic.voyage WHERE from_eta = $1 AND to_eta = $2", from_eta, to_eta);
        tx.commit();
        auto out = std::vector<Voyage>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
    }

private:
    Connection& conn_;

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> Voyage {
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
};

} // namespace vessel_traffic
