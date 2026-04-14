#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "parcel.hpp"
#include "parcel_command_repository.hpp"
#include <memory>
#include <string>

namespace cargo_decomposition {

/// Command service for Parcel aggregate.
/// Handles all write operations (CQRS command side).
class ParcelCommandService {
public:
    explicit ParcelCommandService(ParcelCommandRepository& repository)
        : repository_{repository} {}

    auto create(const Parcel& entity) -> void;
    auto update(const Parcel& entity) -> void;
    auto remove(const Parcel::Id& id) -> void;

private:
    ParcelCommandRepository& repository_;
};

} // namespace cargo_decomposition
