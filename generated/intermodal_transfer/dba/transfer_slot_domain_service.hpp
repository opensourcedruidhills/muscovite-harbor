#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "transfer_slot.hpp"
#include "transfer_slot_command_service.hpp"
#include "transfer_slot_query_service.hpp"
#include "truck_visit.hpp"
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace intermodal_transfer {

/// Domain service for TransferSlot aggregate.
/// Orchestrates three-tier validation pipeline and delegates to
/// CommandService (writes) and QueryService (reads).
class TransferSlotDomainService {
public:
    explicit TransferSlotDomainService(TransferSlotCommandService& command_service, TransferSlotQueryService& query_service)
        : command_service_{command_service}
        , query_service_{query_service} {}

    // Command operations (write side)
    auto create(const TransferSlot& entity) -> void;
    auto update(const TransferSlot& entity) -> void;
    auto remove(const TransferSlot::Id& id) -> void;

    // Query operations (read side — pass-through)
    [[nodiscard]] auto find_by_id(const TransferSlot::Id& id) -> std::optional<TransferSlot>;
    [[nodiscard]] auto find_all() -> std::vector<TransferSlot>;

    // TruckVisit child entity operations
    auto add_truck_visit(const TransferSlot::Id& parent_id, const TruckVisit& child) -> void;
    auto remove_truck_visit(const TransferSlot::Id& parent_id, const TruckVisit::Id& child_id) -> void;

private:
    TransferSlotCommandService& command_service_;
    TransferSlotQueryService& query_service_;
};

} // namespace intermodal_transfer
