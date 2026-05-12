// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace harbour_control {

auto PortCallRepositoryImpl::find_by_id(pqxx::work& tx, const std::string& id)
    -> std::optional<PortCall> {
    auto rows = tx.exec_params(kSelectById, id);
    if (rows.empty()) { return std::nullopt; }
    return PortCall::from_row(rows.front());
}

auto PortCallRepositoryImpl::find_all(pqxx::work& tx) -> std::vector<PortCall> {
    auto rows = tx.exec(kSelectAll);
    auto result = std::vector<PortCall>{};
    result.reserve(rows.size());
    for (const auto& row : rows) {
        result.push_back(PortCall::from_row(row));
    }
    return result;
}

auto PortCallRepositoryImpl::count(pqxx::work& tx) -> std::size_t {
    auto rows = tx.exec("SELECT count(*) FROM port_calls");
    return rows.front()[0].as<std::size_t>();
}

} // namespace harbour_control
