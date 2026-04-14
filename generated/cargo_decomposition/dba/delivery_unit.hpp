#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <boost/uuid/uuid.hpp>
#include <string>
#include <string>

namespace cargo_decomposition {

/// Last-mile delivery unit dispatched from terminal
struct DeliveryUnit {
    using Id = boost::uuids::uuid;

    Id id{};
    boost::uuids::uuid id{};
    TrackingNumber tracking_number{};
    std::string destination{};
    std::string carrier{};
    muscovite::dba::Timestamp dispatched_at{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_id() const noexcept -> const boost::uuids::uuid& { return id; }
    [[nodiscard]] auto get_tracking_number() const noexcept -> const TrackingNumber& { return tracking_number; }
    [[nodiscard]] auto get_destination() const noexcept -> const std::string& { return destination; }
    [[nodiscard]] auto get_carrier() const noexcept -> const std::string& { return carrier; }
    [[nodiscard]] auto get_dispatched_at() const noexcept -> const muscovite::dba::Timestamp& { return dispatched_at; }
};

} // namespace cargo_decomposition
