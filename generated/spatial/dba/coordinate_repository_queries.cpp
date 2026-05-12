// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace spatial {

auto CoordinateRepositoryImpl::find_by_id(pqxx::work& tx, const std::string& id)
    -> std::optional<Coordinate> {
    auto rows = tx.exec_params(kSelectById, id);
    if (rows.empty()) { return std::nullopt; }
    return Coordinate::from_row(rows.front());
}

auto CoordinateRepositoryImpl::find_all(pqxx::work& tx) -> std::vector<Coordinate> {
    auto rows = tx.exec(kSelectAll);
    auto result = std::vector<Coordinate>{};
    result.reserve(rows.size());
    for (const auto& row : rows) {
        result.push_back(Coordinate::from_row(row));
    }
    return result;
}

auto CoordinateRepositoryImpl::count(pqxx::work& tx) -> std::size_t {
    auto rows = tx.exec("SELECT count(*) FROM coordinates");
    return rows.front()[0].as<std::size_t>();
}

} // namespace spatial
