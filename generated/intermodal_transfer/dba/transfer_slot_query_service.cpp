// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "transfer_slot_query_service.hpp"

namespace intermodal_transfer {

auto TransferSlotQueryService::find_by_id(const TransferSlot::Id& id) -> std::optional<TransferSlot> {
    return repository_.find_by_id(id);
}

auto TransferSlotQueryService::find_all() -> std::vector<TransferSlot> {
    return repository_.find_all();
}

auto TransferSlotQueryService::count() -> std::int64_t {
    return repository_.count();
}

} // namespace intermodal_transfer
