#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "transfer_slot.hpp"
#include "transfer_slot_query_repository.hpp"
#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace intermodal_transfer {

/// Query service for TransferSlot aggregate.
/// Handles all read operations (CQRS query side).
class TransferSlotQueryService {
public:
    explicit TransferSlotQueryService(TransferSlotQueryRepository& repository)
        : repository_{repository} {}

    [[nodiscard]] auto find_by_id(const TransferSlot::Id& id) -> std::optional<TransferSlot>;
    [[nodiscard]] auto find_all() -> std::vector<TransferSlot>;
    [[nodiscard]] auto count() -> std::int64_t;

private:
    TransferSlotQueryRepository& repository_;
};

} // namespace intermodal_transfer
