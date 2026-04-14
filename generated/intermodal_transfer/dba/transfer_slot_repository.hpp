#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "transfer_slot.hpp"
#include <optional>
#include <vector>

namespace intermodal_transfer {

/// Repository interface for TransferSlot aggregate.
class TransferSlotRepository {
public:
    using TransferSlots = std::vector<TransferSlot>;

    virtual ~TransferSlotRepository() = default;

    [[nodiscard]] virtual auto find_by_id(const TransferSlot::Id& id) -> std::optional<TransferSlot> = 0;
    virtual auto save(const TransferSlot& entity) -> void = 0;
    virtual auto remove(const TransferSlot::Id& id) -> void = 0;
    [[nodiscard]] virtual auto find_all() -> TransferSlots = 0;
};

} // namespace intermodal_transfer
