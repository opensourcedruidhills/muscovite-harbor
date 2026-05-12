#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "delivery_unit.hpp"
#include "cargo_decomposition_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace cargo_decomposition {

/// Concrete CRTP repository implementation for DeliveryUnit.
/// Satisfies RepositoryBase<DeliveryUnitRepositoryImpl<C>, DeliveryUnit> contract.
/// Uses embedded SQL constants from cargo_decomposition_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class DeliveryUnitRepositoryImpl {
public:
    explicit DeliveryUnitRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const DeliveryUnit& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::DeliveryUnitInsert, entity.id, entity.id, entity.tracking_number, entity.destination, entity.carrier, entity.dispatched_at);
        tx.commit();
    }

    auto update(const DeliveryUnit& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::DeliveryUnitUpdate, entity.id, entity.id, entity.tracking_number, entity.destination, entity.carrier, entity.dispatched_at);
        if (result.affected_rows() == 0) {
            throw std::runtime_error(DeliveryUnit not found:  + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::DeliveryUnitDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<DeliveryUnit> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::DeliveryUnitSelectById, id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<DeliveryUnit> {
        auto tx = conn_.begin();
        auto result = tx.exec(queries::DeliveryUnitSelectAll);
        tx.commit();
        auto out = std::vector<DeliveryUnit>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> DeliveryUnit {
        return DeliveryUnit{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .tracking_number = row[2].as<std::string>(),
            .destination = row[3].as<std::string>(),
            .carrier = row[4].as<std::string>(),
            .dispatched_at = row[5].as<std::string>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace cargo_decomposition
