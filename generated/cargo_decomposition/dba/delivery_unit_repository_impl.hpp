#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "delivery_unit.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace cargo_decomposition {

/// Concrete CRTP repository implementation for DeliveryUnit.
/// Satisfies RepositoryBase<DeliveryUnitRepositoryImpl<C>, DeliveryUnit> contract.
/// Uses parameterised SQL (pqxx) — no stored procedures (ADR 20260120).
template<typename Connection>
class DeliveryUnitRepositoryImpl {
public:
    explicit DeliveryUnitRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto build_select_by_id_query() const -> std::string {
        return "SELECT id, id, tracking_number, destination, carrier, dispatched_at FROM cargo_decomposition.delivery_unit WHERE id = $1";
    }

    [[nodiscard]] auto build_insert_query() const -> std::string {
        return "INSERT INTO cargo_decomposition.delivery_unit (id, id, tracking_number, destination, carrier, dispatched_at) VALUES ($1, $2, $3, $4, $5, $6) RETURNING id";
    }

    [[nodiscard]] auto build_update_query() const -> std::string {
        return "UPDATE cargo_decomposition.delivery_unit SET id = $2, tracking_number = $3, destination = $4, carrier = $5, dispatched_at = $6 WHERE id = $1";
    }

    [[nodiscard]] auto build_delete_query() const -> std::string {
        return "DELETE FROM cargo_decomposition.delivery_unit WHERE id = $1";
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

    auto save(const DeliveryUnit& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_insert_query(), entity.id, entity.id, entity.tracking_number, entity.destination, entity.carrier, entity.dispatched_at);
        tx.commit();
    }

    auto update(const DeliveryUnit& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_update_query(), entity.id, entity.id, entity.tracking_number, entity.destination, entity.carrier, entity.dispatched_at);
        if (result.affected_rows() == 0) {
            throw std::runtime_error("DeliveryUnit not found: " + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_delete_query(), id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<DeliveryUnit> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_select_by_id_query(), id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

private:
    Connection& conn_;
};

} // namespace cargo_decomposition
