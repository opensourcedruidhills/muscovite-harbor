// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "container_validator.hpp"

namespace cargo_operations {

auto ContainerValidator::check_slot_empty(const Container& entity) -> bool {
    return yard_slot_id IS NULL;
}

auto ContainerValidator::check_weight_ok(const Container& entity) -> bool {
    return weight_kg <= 30500;
}

auto ContainerValidator::check_is_top(const Container& entity) -> bool {
    return status = 'IN_YARD';
}

} // namespace cargo_operations
