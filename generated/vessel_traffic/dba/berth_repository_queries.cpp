// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace vessel_traffic {

auto BerthRepositoryImpl::find_by_id(pqxx::work& tx, const std::string& id)
    -> std::optional<Berth> {
    auto rows = tx.exec_params(kSelectById, id);
    if (rows.empty()) { return std::nullopt; }
    return Berth::from_row(rows.front());
}

auto BerthRepositoryImpl::find_all(pqxx::work& tx) -> std::vector<Berth> {
    auto rows = tx.exec(kSelectAll);
    auto result = std::vector<Berth>{};
    result.reserve(rows.size());
    for (const auto& row : rows) {
        result.push_back(Berth::from_row(row));
    }
    return result;
}

auto BerthRepositoryImpl::count(pqxx::work& tx) -> std::size_t {
    auto rows = tx.exec("SELECT count(*) FROM berths");
    return rows.front()[0].as<std::size_t>();
}

} // namespace vessel_traffic
