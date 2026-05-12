#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace cargo_operations {

/// Unified DBA struct for Container.
struct Container {
    boost::uuids::uuid id{};
    boost::uuids::uuid id{};
    ContainerNumber container_number{};
    std::string size_category{};
    std::string hazmat_class{};
    boost::uuids::uuid voyage_id{};
    boost::uuids::uuid yard_slot_id{};
    std::string status{};

    /// Construct from a database row (stub — implementation in .cpp).
    // static auto from_row(const pqxx::row& row) -> Container;

    /// Try to construct; returns nullopt on missing required field.
    // static auto try_from(const pqxx::row& row) -> std::optional<Container>;
};

} // namespace cargo_operations
