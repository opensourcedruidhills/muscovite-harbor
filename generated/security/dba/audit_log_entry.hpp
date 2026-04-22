#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <muscovite/dba/timestamp.hpp>
#include <string>

namespace security {

/// Immutable audit trail entry recording who did what to which resource.
struct AuditLogEntry {
    using Id = std::string;

    Id id{};
    muscovite::dba::Timestamp timestamp{};
    std::string actor{};
    std::string action{};
    std::string resource{};
    std::string details{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_timestamp() const noexcept -> const muscovite::dba::Timestamp& { return timestamp; }
    [[nodiscard]] auto get_actor() const noexcept -> const std::string& { return actor; }
    [[nodiscard]] auto get_action() const noexcept -> const std::string& { return action; }
    [[nodiscard]] auto get_resource() const noexcept -> const std::string& { return resource; }
    [[nodiscard]] auto get_details() const noexcept -> const std::string& { return details; }
};

} // namespace security
