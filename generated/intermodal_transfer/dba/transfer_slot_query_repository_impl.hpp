#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "transfer_slot_query_repository.hpp"
#include "intermodal_transfer_queries.hpp"
#include <cstdint>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

namespace intermodal_transfer {

class DbaOperationSpan {
public:
    explicit DbaOperationSpan(std::string_view operation) : operation_{operation} {}
    auto set_status_ok() noexcept -> void {}
    auto set_error(std::string_view /*message*/) noexcept -> void {}
private:
    std::string_view operation_;
};

/// pqxx-based query repository implementation for TransferSlot aggregate.
/// Uses embedded SQL constants from intermodal_transfer_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class TransferSlotQueryRepositoryImpl : public TransferSlotQueryRepository {
public:
    explicit TransferSlotQueryRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto find_by_id(const TransferSlot::Id& id) -> std::optional<TransferSlot> override {
        DbaOperationSpan span("TransferSlotQueryRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::TransferSlotSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        auto mapped = map_row(result[0]);
        span.set_status_ok();
        return mapped;
    }

    [[nodiscard]] auto find_all() -> std::vector<TransferSlot> override {
        DbaOperationSpan span("TransferSlotQueryRepositoryImpl::find_all");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::TransferSlotSelectAll);
        tx.commit();
        auto out = std::vector<TransferSlot>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        span.set_status_ok();
        return out;
    }

    [[nodiscard]] auto count() -> std::int64_t override {
        DbaOperationSpan span("TransferSlotQueryRepositoryImpl::count");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::TransferSlotCount);
        tx.commit();
        auto total = result[0][0].as<std::int64_t>();
        span.set_status_ok();
        return total;
    }

private:
    Connection& conn_;

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> TransferSlot {
        return TransferSlot{
            .id = row[0].as<std::string>(),
            .id = row[1].as<boost::uuids::uuid>(),
            .reference = row[2].as<std::string>(),
            .container_id = row[3].as<boost::uuids::uuid>(),
            .transport_mode = row[4].as<std::string>(),
            .scheduled_at = row[5].as<muscovite::dba::Timestamp>(),
            .status = row[6].as<std::string>(),
        };
    }
;

} // namespace intermodal_transfer
