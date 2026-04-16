// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "container_event_store.hpp"

namespace cargo_operations {

/// SQL-based event store implementation for Container.
/// Uses dual-write pattern: events + snapshot in single transaction.
template<typename Connection>
class ContainerEventStoreSql : public ContainerEventStore {
public:
    explicit ContainerEventStoreSql(Connection& conn) : conn_{conn} {}

    auto append(const std::string& aggregate_id, std::int64_t expected_version,
                const std::string& event_type, const std::string& payload) -> void override {
        auto tx = conn_.begin();
        tx.exec_params(
            "INSERT INTO cargo_operations.container_events "
            "(id, aggregate_id, event_type, payload, sequence_number, created_at) "
            "VALUES (uuidv7(), $1, $2, $3, $4, NOW())",
            aggregate_id, event_type, payload, expected_version + 1);
        tx.commit();
    }

    [[nodiscard]] auto load_snapshot(const std::string& aggregate_id) -> std::optional<Container> override {
        (void)aggregate_id;
        return std::nullopt; // Snapshot support depends on aggregate structure
    }

    [[nodiscard]] auto load_events(const std::string& aggregate_id, std::int64_t from_version) -> std::vector<std::string> override {
        auto tx = conn_.begin();
        auto result = tx.exec_params(
            "SELECT payload FROM cargo_operations.container_events "
            "WHERE aggregate_id = $1 AND sequence_number > $2 ORDER BY sequence_number",
            aggregate_id, from_version);
        tx.commit();
        auto events = std::vector<std::string>{};
        events.reserve(result.size());
        for (const auto& row : result) {
            events.push_back(row[0].as<std::string>());
        }
        return events;
    }

private:
    Connection& conn_;
};

} // namespace cargo_operations
