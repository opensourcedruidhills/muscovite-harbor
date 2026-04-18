#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <boost/uuid/uuid.hpp>
#include <muscovite/dba/timestamp.hpp>
#include <string>

namespace vessel_traffic {

/// A single vessel call at the harbour
struct Voyage {
    using Id = boost::uuids::uuid;

    Id id{};
    boost::uuids::uuid vessel_id{};
    boost::uuids::uuid berth_id{};
    std::string voyage_number{};
    muscovite::dba::Timestamp eta{};
    muscovite::dba::Timestamp ata{};
    muscovite::dba::Timestamp etd{};
    muscovite::dba::Timestamp atd{};
    std::string cargo_category{};
    std::string status{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_vessel_id() const noexcept -> const boost::uuids::uuid& { return vessel_id; }
    [[nodiscard]] auto get_berth_id() const noexcept -> const boost::uuids::uuid& { return berth_id; }
    [[nodiscard]] auto get_voyage_number() const noexcept -> const std::string& { return voyage_number; }
    [[nodiscard]] auto get_eta() const noexcept -> const muscovite::dba::Timestamp& { return eta; }
    [[nodiscard]] auto get_ata() const noexcept -> const muscovite::dba::Timestamp& { return ata; }
    [[nodiscard]] auto get_etd() const noexcept -> const muscovite::dba::Timestamp& { return etd; }
    [[nodiscard]] auto get_atd() const noexcept -> const muscovite::dba::Timestamp& { return atd; }
    [[nodiscard]] auto get_cargo_category() const noexcept -> const std::string& { return cargo_category; }
    [[nodiscard]] auto get_status() const noexcept -> const std::string& { return status; }
};

} // namespace vessel_traffic
