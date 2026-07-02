#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "transfer_slot_command_repository.hpp"
#include "intermodal_transfer_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>

namespace intermodal_transfer {

class DbaOperationSpan {
public:
    explicit DbaOperationSpan(std::string_view operation) : operation_{operation} {}
    auto set_status_ok() noexcept -> void {}
    auto set_error(std::string_view /*message*/) noexcept -> void {}
private:
    std::string_view operation_;
};

/// pqxx-based command repository implementation for TransferSlot aggregate.
/// Uses embedded SQL constants from intermodal_transfer_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class TransferSlotCommandRepositoryImpl : public TransferSlotCommandRepository {
public:
    explicit TransferSlotCommandRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const TransferSlot& entity) -> void override {
        DbaOperationSpan span("TransferSlotCommandRepositoryImpl::save");
        auto tx = conn_.begin();
        tx.exec_params(queries::TransferSlotUpsert,
            entity.id, entity.reference, entity.container_id, entity.transport_mode, entity.scheduled_at, entity.status);
        tx.commit();
        span.set_status_ok();
    }

    auto update(const TransferSlot& entity) -> void override {
        DbaOperationSpan span("TransferSlotCommandRepositoryImpl::update");
        auto tx = conn_.begin();
        tx.exec_params(queries::TransferSlotUpdate,
            entity.id, entity.reference, entity.container_id, entity.transport_mode, entity.scheduled_at, entity.status);
        tx.commit();
        span.set_status_ok();
    }

    auto remove(const TransferSlot::Id& id) -> void override {
        DbaOperationSpan span("TransferSlotCommandRepositoryImpl::remove");
        auto tx = conn_.begin();
        tx.exec_params(queries::TransferSlotDelete, id);
        tx.commit();
        span.set_status_ok();
    }

    [[nodiscard]] auto find_by_id(const TransferSlot::Id& id) -> std::optional<TransferSlot> override {
        DbaOperationSpan span("TransferSlotCommandRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::TransferSlotSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        const auto& row = result[0];
        auto entity = TransferSlot{
            .id = row[0].as<std::string>(),
            .reference = row[1].as<std::string>(),
            .container_id = row[2].as<boost::uuids::uuid>(),
            .transport_mode = row[3].as<std::string>(),
            .scheduled_at = row[4].as<muscovite::dba::Timestamp>(),
            .status = row[5].as<std::string>(),
        };
        span.set_status_ok();
        return entity;
    }

private:
    Connection& conn_;
;

} // namespace intermodal_transfer
