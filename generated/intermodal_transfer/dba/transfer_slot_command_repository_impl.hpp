#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "transfer_slot_command_repository.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace intermodal_transfer {

/// pqxx-based command repository implementation for TransferSlot aggregate.
/// Uses direct parameterised SQL — no stored procedures (ADR 20260120).
template<typename Connection>
class TransferSlotCommandRepositoryImpl : public TransferSlotCommandRepository {
public:
    explicit TransferSlotCommandRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const TransferSlot& entity) -> void override {
        auto tx = conn_.begin();
        tx.exec_params("INSERT INTO intermodal_transfer.transfer_slot (id, id, reference, container_id, transport_mode, scheduled_at, status) VALUES ($1, $2, $3, $4, $5, $6, $7) ON CONFLICT (id) DO UPDATE SET id = $2, reference = $3, container_id = $4, transport_mode = $5, scheduled_at = $6, status = $7",
            entity.id, entity.id, entity.reference, entity.container_id, entity.transport_mode, entity.scheduled_at, entity.status);
        tx.commit();
    }

    auto remove(const TransferSlot::Id& id) -> void override {
        auto tx = conn_.begin();
        tx.exec_params("DELETE FROM intermodal_transfer.transfer_slot WHERE id = $1", id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const TransferSlot::Id& id) -> std::optional<TransferSlot> override {
        auto tx = conn_.begin();
        auto result = tx.exec_params("SELECT id, id, reference, container_id, transport_mode, scheduled_at, status FROM intermodal_transfer.transfer_slot WHERE id = $1", id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        const auto& row = result[0];
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
};

} // namespace intermodal_transfer
