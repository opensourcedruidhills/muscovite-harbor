// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace vessel_traffic {

auto TideWindowRepositoryImpl::find_by_id(pqxx::work& tx, const std::string& id)
    -> std::optional<TideWindow> {
    auto rows = tx.exec_params(kSelectById, id);
    if (rows.empty()) { return std::nullopt; }
    return TideWindow::from_row(rows.front());
}

auto TideWindowRepositoryImpl::find_all(pqxx::work& tx) -> std::vector<TideWindow> {
    auto rows = tx.exec(kSelectAll);
    auto result = std::vector<TideWindow>{};
    result.reserve(rows.size());
    for (const auto& row : rows) {
        result.push_back(TideWindow::from_row(row));
    }
    return result;
}

auto TideWindowRepositoryImpl::count(pqxx::work& tx) -> std::size_t {
    auto rows = tx.exec("SELECT count(*) FROM tide_windows");
    return rows.front()[0].as<std::size_t>();
}

} // namespace vessel_traffic
