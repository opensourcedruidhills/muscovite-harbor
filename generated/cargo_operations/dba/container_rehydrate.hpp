// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
//
// GENERATED FILE — DO NOT EDIT

#pragma once

#include "container.hpp"
#include "container_event_store.hpp"
#include "container_apply.hpp"
#include <span>

namespace cargo_operations {

inline auto Container::rehydrate(std::span<const ContainerEventVariant> events) -> Container {
    Container entity;
    for (const auto& event : events) { entity.apply(event); }
    return entity;
}

} // namespace cargo_operations
