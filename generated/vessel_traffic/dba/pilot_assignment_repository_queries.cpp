// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace vessel_traffic {

auto PilotAssignmentRepositoryImpl::find_by_id(pqxx::work& tx, const std::string& id)
    -> std::optional<PilotAssignment> {
    auto rows = tx.exec_params(kSelectById, id);
    if (rows.empty()) { return std::nullopt; }
    return PilotAssignment::from_row(rows.front());
}

auto PilotAssignmentRepositoryImpl::find_all(pqxx::work& tx) -> std::vector<PilotAssignment> {
    auto rows = tx.exec(kSelectAll);
    auto result = std::vector<PilotAssignment>{};
    result.reserve(rows.size());
    for (const auto& row : rows) {
        result.push_back(PilotAssignment::from_row(row));
    }
    return result;
}

auto PilotAssignmentRepositoryImpl::count(pqxx::work& tx) -> std::size_t {
    auto rows = tx.exec("SELECT count(*) FROM pilot_assignments");
    return rows.front()[0].as<std::size_t>();
}

} // namespace vessel_traffic
