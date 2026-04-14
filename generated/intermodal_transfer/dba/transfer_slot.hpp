#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <boost/uuid/uuid.hpp>
#include <string>
#include <string>

namespace intermodal_transfer {

/// A time slot for container transfer to outbound transport
struct TransferSlot {
    using Id = boost::uuids::uuid;

    Id id{};
    boost::uuids::uuid id{};
    SlotReference reference{};
    boost::uuids::uuid container_id{};
    std::string transport_mode{};
    muscovite::dba::Timestamp scheduled_at{};
    std::string status{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_id() const noexcept -> const boost::uuids::uuid& { return id; }
    [[nodiscard]] auto get_reference() const noexcept -> const SlotReference& { return reference; }
    [[nodiscard]] auto get_container_id() const noexcept -> const boost::uuids::uuid& { return container_id; }
    [[nodiscard]] auto get_transport_mode() const noexcept -> const std::string& { return transport_mode; }
    [[nodiscard]] auto get_scheduled_at() const noexcept -> const muscovite::dba::Timestamp& { return scheduled_at; }
    [[nodiscard]] auto get_status() const noexcept -> const std::string& { return status; }
};

} // namespace intermodal_transfer
