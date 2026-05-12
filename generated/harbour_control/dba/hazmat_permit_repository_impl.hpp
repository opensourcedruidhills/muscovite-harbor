#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "hazmat_permit.hpp"
#include "harbour_control_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace harbour_control {

/// Concrete CRTP repository implementation for HazmatPermit.
/// Satisfies RepositoryBase<HazmatPermitRepositoryImpl<C>, HazmatPermit> contract.
/// Uses embedded SQL constants from harbour_control_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class HazmatPermitRepositoryImpl {
public:
    explicit HazmatPermitRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const HazmatPermit& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::HazmatPermitInsert, entity.id, entity.id, entity.permit_number, entity.vessel_id, entity.imo_class, entity.quantity_kg, entity.approved, entity.valid_from, entity.valid_until);
        tx.commit();
    }

    auto update(const HazmatPermit& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::HazmatPermitUpdate, entity.id, entity.id, entity.permit_number, entity.vessel_id, entity.imo_class, entity.quantity_kg, entity.approved, entity.valid_from, entity.valid_until);
        if (result.affected_rows() == 0) {
            throw std::runtime_error(HazmatPermit not found:  + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::HazmatPermitDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<HazmatPermit> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::HazmatPermitSelectById, id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<HazmatPermit> {
        auto tx = conn_.begin();
        auto result = tx.exec(queries::HazmatPermitSelectAll);
        tx.commit();
        auto out = std::vector<HazmatPermit>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> HazmatPermit {
        return HazmatPermit{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .permit_number = row[2].as<std::string>(),
            .vessel_id = row[3].as<std::string>(),
            .imo_class = row[4].as<std::string>(),
            .quantity_kg = row[5].as<std::string>(),
            .approved = row[6].as<std::string>(),
            .valid_from = row[7].as<std::string>(),
            .valid_until = row[8].as<std::string>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace harbour_control
