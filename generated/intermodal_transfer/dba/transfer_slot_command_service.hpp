#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "transfer_slot.hpp"
#include "transfer_slot_command_repository.hpp"
#include <memory>
#include <string>

namespace intermodal_transfer {

/// Command service for TransferSlot aggregate.
/// Handles all write operations (CQRS command side).
class TransferSlotCommandService {
public:
    explicit TransferSlotCommandService(TransferSlotCommandRepository& repository)
        : repository_{repository} {}

    auto create(const TransferSlot& entity) -> void;
    auto update(const TransferSlot& entity) -> void;
    auto remove(const TransferSlot::Id& id) -> void;

private:
    TransferSlotCommandRepository& repository_;
};

} // namespace intermodal_transfer
