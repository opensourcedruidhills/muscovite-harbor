#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <functional>
#include <string>

namespace vessel_traffic {

/// Specification concept — any type with is_satisfied_by(), name(), description().
template<typename T, typename Entity>
concept Specification = requires(const T& spec, const Entity& entity) {
    { spec.is_satisfied_by(entity) } -> std::same_as<bool>;
    { spec.name() } -> std::same_as<std::string>;
    { spec.description() } -> std::same_as<std::string>;
};

/// Composite specification using std::function predicate.
template<typename Entity>
class CompositeSpecification {
public:
    explicit CompositeSpecification(std::string spec_name, std::function<bool(const Entity&)> pred)
        : name_{std::move(spec_name)}, predicate_{std::move(pred)} {}

    [[nodiscard]] auto is_satisfied_by(const Entity& entity) const -> bool { return predicate_(entity); }
    [[nodiscard]] auto name() const -> std::string { return name_; }
    [[nodiscard]] auto description() const -> std::string { return "Composite: " + name_; }

    /// Logical AND composition.
    auto operator&&(const CompositeSpecification& other) const -> CompositeSpecification {
        auto lhs = predicate_;
        auto rhs = other.predicate_;
        return CompositeSpecification{name_ + " AND " + other.name_,
            [lhs, rhs](const Entity& e) { return lhs(e) && rhs(e); }};
    }

    /// Logical OR composition.
    auto operator||(const CompositeSpecification& other) const -> CompositeSpecification {
        auto lhs = predicate_;
        auto rhs = other.predicate_;
        return CompositeSpecification{name_ + " OR " + other.name_,
            [lhs, rhs](const Entity& e) { return lhs(e) || rhs(e); }};
    }

    /// Logical NOT.
    auto operator!() const -> CompositeSpecification {
        auto pred = predicate_;
        return CompositeSpecification{"NOT " + name_,
            [pred](const Entity& e) { return !pred(e); }};
    }

private:
    std::string name_;
    std::function<bool(const Entity&)> predicate_;
};

/// Find berths matching vessel requirements within a time window
class AvailableBerthsSpec {
public:
    [[nodiscard]] auto is_satisfied_by(const Berth& entity) const -> bool;
    [[nodiscard]] auto name() const -> std::string { return "AvailableBerths"; }
    [[nodiscard]] auto description() const -> std::string { return ""; }
    [[nodiscard]] auto sql_where() const -> std::string { return "max_draft_metres >= min_draft AND max_loa_metres >= min_loa AND is_active = TRUE"; }
};

/// Find voyages with ETA in given range
class VesselsByETASpec {
public:
    [[nodiscard]] auto is_satisfied_by(const Voyage& entity) const -> bool;
    [[nodiscard]] auto name() const -> std::string { return "VesselsByETA"; }
    [[nodiscard]] auto description() const -> std::string { return ""; }
    [[nodiscard]] auto sql_where() const -> std::string { return "eta BETWEEN from_eta AND to_eta AND status != 'DEPARTED'"; }
};

} // namespace vessel_traffic
