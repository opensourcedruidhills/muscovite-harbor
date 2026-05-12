#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "transfer_slot.hpp"
#include "intermodal_transfer_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace intermodal_transfer {

/// Concrete CRTP repository implementation for TransferSlot.
/// Satisfies RepositoryBase<TransferSlotRepositoryImpl<C>, TransferSlot> contract.
/// Uses embedded SQL constants from intermodal_transfer_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class TransferSlotRepositoryImpl {
public:
    explicit TransferSlotRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const TransferSlot& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::TransferSlotInsert, entity.id, entity.id, entity.reference, entity.container_id, entity.transport_mode, entity.scheduled_at, entity.status);
        tx.commit();
    }

    auto update(const TransferSlot& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::TransferSlotUpdate, entity.id, entity.id, entity.reference, entity.container_id, entity.transport_mode, entity.scheduled_at, entity.status);
        if (result.affected_rows() == 0) {
            throw std::runtime_error(TransferSlot not found:  + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::TransferSlotDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<TransferSlot> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::TransferSlotSelectById, id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<TransferSlot> {
        auto tx = conn_.begin();
        auto result = tx.exec(queries::TransferSlotSelectAll);
        tx.commit();
        auto out = std::vector<TransferSlot>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
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

private:
    Connection& conn_;
;

} // namespace intermodal_transfer
