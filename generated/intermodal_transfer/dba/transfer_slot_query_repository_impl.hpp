#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "transfer_slot_query_repository.hpp"
#include <cstdint>
#include <optional>
#include <stdexcept>
#include <string>
#include <vector>

namespace intermodal_transfer {

/// pqxx-based query repository implementation for TransferSlot aggregate.
/// Uses direct parameterised SQL — no stored procedures (ADR 20260120).
template<typename Connection>
class TransferSlotQueryRepositoryImpl : public TransferSlotQueryRepository {
public:
    explicit TransferSlotQueryRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto find_by_id(const TransferSlot::Id& id) -> std::optional<TransferSlot> override {
        auto tx = conn_.begin();
        auto result = tx.exec_params("SELECT id, id, reference, container_id, transport_mode, scheduled_at, status FROM intermodal_transfer.transfer_slot WHERE id = $1", id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<TransferSlot> override {
        auto tx = conn_.begin();
        auto result = tx.exec("SELECT id, id, reference, container_id, transport_mode, scheduled_at, status FROM intermodal_transfer.transfer_slot ORDER BY id");
        tx.commit();
        auto out = std::vector<TransferSlot>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
    }

    [[nodiscard]] auto count() -> std::int64_t override {
        auto tx = conn_.begin();
        auto result = tx.exec("SELECT COUNT(*) FROM intermodal_transfer.transfer_slot");
        tx.commit();
        return result[0][0].as<std::int64_t>();
    }

private:
    Connection& conn_;

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
};

} // namespace intermodal_transfer
