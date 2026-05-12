// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace passenger_terminal {

auto GateRepositoryImpl::find_by_id(pqxx::work& tx, const std::string& id)
    -> std::optional<Gate> {
    auto rows = tx.exec_params(kSelectById, id);
    if (rows.empty()) { return std::nullopt; }
    return Gate::from_row(rows.front());
}

auto GateRepositoryImpl::find_all(pqxx::work& tx) -> std::vector<Gate> {
    auto rows = tx.exec(kSelectAll);
    auto result = std::vector<Gate>{};
    result.reserve(rows.size());
    for (const auto& row : rows) {
        result.push_back(Gate::from_row(row));
    }
    return result;
}

auto GateRepositoryImpl::count(pqxx::work& tx) -> std::size_t {
    auto rows = tx.exec("SELECT count(*) FROM gates");
    return rows.front()[0].as<std::size_t>();
}

} // namespace passenger_terminal
