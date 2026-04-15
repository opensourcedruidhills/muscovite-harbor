#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <boost/uuid/uuid.hpp>
#include <muscovite/dba/timestamp.hpp>
#include <string>
#include <string>

namespace cargo_operations {

/// Plan for loading/discharging containers for a voyage
struct LoadPlan {
    using Id = boost::uuids::uuid;

    Id id{};
    boost::uuids::uuid voyage_id{};
    muscovite::dba::Timestamp created_at{};
    std::string status{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_voyage_id() const noexcept -> const boost::uuids::uuid& { return voyage_id; }
    [[nodiscard]] auto get_created_at() const noexcept -> const muscovite::dba::Timestamp& { return created_at; }
    [[nodiscard]] auto get_status() const noexcept -> const std::string& { return status; }
};

} // namespace cargo_operations
