#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "pallet.hpp"
#include "pallet_command_service.hpp"
#include "pallet_query_service.hpp"
#include "parcel.hpp"
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace cargo_decomposition {

/// Domain service for Pallet aggregate.
/// Orchestrates three-tier validation pipeline and delegates to
/// CommandService (writes) and QueryService (reads).
class PalletDomainService {
public:
    explicit PalletDomainService(PalletCommandService& command_service, PalletQueryService& query_service)
        : command_service_{command_service}
        , query_service_{query_service} {}

    // Command operations (write side)
    auto create(const Pallet& entity) -> void;
    auto update(const Pallet& entity) -> void;
    auto remove(const Pallet::Id& id) -> void;

    // Query operations (read side — pass-through)
    [[nodiscard]] auto find_by_id(const Pallet::Id& id) -> std::optional<Pallet>;
    [[nodiscard]] auto find_all() -> std::vector<Pallet>;

    // Parcel child entity operations
    auto add_parcel(const Pallet::Id& parent_id, const Parcel& child) -> void;
    auto remove_parcel(const Pallet::Id& parent_id, const Parcel::Id& child_id) -> void;

private:
    PalletCommandService& command_service_;
    PalletQueryService& query_service_;
};

} // namespace cargo_decomposition
