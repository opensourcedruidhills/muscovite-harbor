#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <boost/uuid/uuid.hpp>
#include <cstdint>
#include <string>

namespace harbour_control {

/// Hazmat handling permit issued by port authority
struct HazmatPermit {
    using Id = boost::uuids::uuid;

    Id id{};
    boost::uuids::uuid id{};
    PermitNumber permit_number{};
    boost::uuids::uuid vessel_id{};
    std::int32_t imo_class{};
    muscovite::dba::Decimal quantity_kg{};
    bool approved{};
    muscovite::dba::Timestamp valid_from{};
    muscovite::dba::Timestamp valid_until{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_id() const noexcept -> const boost::uuids::uuid& { return id; }
    [[nodiscard]] auto get_permit_number() const noexcept -> const PermitNumber& { return permit_number; }
    [[nodiscard]] auto get_vessel_id() const noexcept -> const boost::uuids::uuid& { return vessel_id; }
    [[nodiscard]] auto get_imo_class() const noexcept -> std::int32_t { return imo_class; }
    [[nodiscard]] auto get_quantity_kg() const noexcept -> const muscovite::dba::Decimal& { return quantity_kg; }
    [[nodiscard]] auto get_approved() const noexcept -> bool { return approved; }
    [[nodiscard]] auto get_valid_from() const noexcept -> const muscovite::dba::Timestamp& { return valid_from; }
    [[nodiscard]] auto get_valid_until() const noexcept -> const muscovite::dba::Timestamp& { return valid_until; }
};

} // namespace harbour_control
