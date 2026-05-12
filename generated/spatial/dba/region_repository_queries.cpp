// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace spatial {

auto RegionRepositoryImpl::find_by_id(pqxx::work& tx, const std::string& id)
    -> std::optional<Region> {
    auto rows = tx.exec_params(kSelectById, id);
    if (rows.empty()) { return std::nullopt; }
    return Region::from_row(rows.front());
}

auto RegionRepositoryImpl::find_all(pqxx::work& tx) -> std::vector<Region> {
    auto rows = tx.exec(kSelectAll);
    auto result = std::vector<Region>{};
    result.reserve(rows.size());
    for (const auto& row : rows) {
        result.push_back(Region::from_row(row));
    }
    return result;
}

auto RegionRepositoryImpl::count(pqxx::work& tx) -> std::size_t {
    auto rows = tx.exec("SELECT count(*) FROM regions");
    return rows.front()[0].as<std::size_t>();
}

} // namespace spatial
