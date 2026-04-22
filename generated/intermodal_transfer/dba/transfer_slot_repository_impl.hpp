#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "transfer_slot.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace intermodal_transfer {

/// Concrete CRTP repository implementation for TransferSlot.
/// Satisfies RepositoryBase<TransferSlotRepositoryImpl<C>, TransferSlot> contract.
/// Uses parameterised SQL (pqxx) — no stored procedures (ADR 20260120).
template<typename Connection>
class TransferSlotRepositoryImpl {
public:
    explicit TransferSlotRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto build_select_by_id_query() const -> std::string {
        return "SELECT id, id, reference, container_id, transport_mode, scheduled_at, status FROM intermodal_transfer.transfer_slot WHERE id = $1";
    }

    [[nodiscard]] auto build_insert_query() const -> std::string {
        return "INSERT INTO intermodal_transfer.transfer_slot (id, id, reference, container_id, transport_mode, scheduled_at, status) VALUES ($1, $2, $3, $4, $5, $6, $7) RETURNING id";
    }

    [[nodiscard]] auto build_update_query() const -> std::string {
        return "UPDATE intermodal_transfer.transfer_slot SET id = $2, reference = $3, container_id = $4, transport_mode = $5, scheduled_at = $6, status = $7 WHERE id = $1";
    }

    [[nodiscard]] auto build_delete_query() const -> std::string {
        return "DELETE FROM intermodal_transfer.transfer_slot WHERE id = $1";
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> TransferSlot {
        return TransferSlot{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .reference = row[2].as<std::string>(),
            .container_id = row[3].as<std::string>(),
            .transport_mode = row[4].as<std::string>(),
            .scheduled_at = row[5].as<std::string>(),
            .status = row[6].as<std::string>(),
        };
    }

    auto save(const TransferSlot& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_insert_query(), entity.id, entity.id, entity.reference, entity.container_id, entity.transport_mode, entity.scheduled_at, entity.status);
        tx.commit();
    }

    auto update(const TransferSlot& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_update_query(), entity.id, entity.id, entity.reference, entity.container_id, entity.transport_mode, entity.scheduled_at, entity.status);
        if (result.affected_rows() == 0) {
            throw std::runtime_error("TransferSlot not found: " + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_delete_query(), id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<TransferSlot> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_select_by_id_query(), id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

private:
    Connection& conn_;
};

} // namespace intermodal_transfer
