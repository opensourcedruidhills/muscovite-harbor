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
        (void)tx.exec_params1(
            "INSERT INTO cargo_operations.container_events "
            "(id, aggregate_id, event_type, payload, sequence_number, created_at) "
            "VALUES (uuidv7(), $1, $2, $3, $4, NOW()) RETURNING id, created_at",
            aggregate_id, event_type, payload, expected_version + 1);
        tx.commit();
    }

    [[nodiscard]] auto load_snapshot(const std::string& aggregate_id) -> std::optional<Container> override {
        pqxx::read_transaction tx{conn_};
        auto result = tx.exec_params(
            "SELECT id, id, container_number, size_category, hazmat_class, voyage_id, yard_slot_id, status FROM cargo_operations.containers "
            "WHERE id = $1 LIMIT 1",
            aggregate_id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        const auto& row = result[0];
        return Container{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .container_number = row[2].as<std::string>(),
            .size_category = row[3].as<std::string>(),
            .hazmat_class = row[4].as<std::string>(),
            .voyage_id = row[5].as<std::string>(),
            .yard_slot_id = row[6].as<std::string>(),
            .status = row[7].as<std::string>(),
        };
    }

    [[nodiscard]] auto load_events(const std::string& aggregate_id, std::int64_t from_version) -> std::vector<std::string> override {
        pqxx::read_transaction tx{conn_};
        auto result = tx.exec_params(
            "SELECT payload FROM cargo_operations.container_events "
            "WHERE aggregate_id = $1 AND sequence_number > $2 ORDER BY sequence_number",
            aggregate_id, from_version);
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
