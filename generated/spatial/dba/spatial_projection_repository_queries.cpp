// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace spatial {

auto SpatialProjectionRepositoryImpl::find_by_id(pqxx::work& tx, const std::string& id)
    -> std::optional<SpatialProjection> {
    auto rows = tx.exec_params(kSelectById, id);
    if (rows.empty()) { return std::nullopt; }
    return SpatialProjection::from_row(rows.front());
}

auto SpatialProjectionRepositoryImpl::find_all(pqxx::work& tx) -> std::vector<SpatialProjection> {
    auto rows = tx.exec(kSelectAll);
    auto result = std::vector<SpatialProjection>{};
    result.reserve(rows.size());
    for (const auto& row : rows) {
        result.push_back(SpatialProjection::from_row(row));
    }
    return result;
}

auto SpatialProjectionRepositoryImpl::count(pqxx::work& tx) -> std::size_t {
    auto rows = tx.exec("SELECT count(*) FROM spatial_projections");
    return rows.front()[0].as<std::size_t>();
}

} // namespace spatial
