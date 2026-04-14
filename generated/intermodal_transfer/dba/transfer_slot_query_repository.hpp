#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "transfer_slot.hpp"
#include <cstdint>
#include <optional>
#include <vector>

namespace intermodal_transfer {

/// Query-side repository interface for TransferSlot aggregate.
/// Handles read operations (CQRS query side).
class TransferSlotQueryRepository {
public:
    virtual ~TransferSlotQueryRepository() = default;

    [[nodiscard]] virtual auto find_by_id(const TransferSlot::Id& id) -> std::optional<TransferSlot> = 0;
    [[nodiscard]] virtual auto find_all() -> std::vector<TransferSlot> = 0;
    [[nodiscard]] virtual auto count() -> std::int64_t = 0;
};

} // namespace intermodal_transfer
