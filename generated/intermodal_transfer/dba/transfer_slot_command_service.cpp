// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "transfer_slot_command_service.hpp"

namespace intermodal_transfer {

auto TransferSlotCommandService::create(const TransferSlot& entity) -> void {
    repository_.save(entity);
}

auto TransferSlotCommandService::update(const TransferSlot& entity) -> void {
    repository_.save(entity);
}

auto TransferSlotCommandService::remove(const TransferSlot::Id& id) -> void {
    repository_.remove(id);
}

} // namespace intermodal_transfer
