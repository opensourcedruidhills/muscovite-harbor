// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace cargo_operations {

auto ContainerRepositoryImpl::find_by_id(pqxx::work& tx, const std::string& id)
    -> std::optional<Container> {
    auto rows = tx.exec_params(kSelectById, id);
    if (rows.empty()) { return std::nullopt; }
    return Container::from_row(rows.front());
}

auto ContainerRepositoryImpl::find_all(pqxx::work& tx) -> std::vector<Container> {
    auto rows = tx.exec(kSelectAll);
    auto result = std::vector<Container>{};
    result.reserve(rows.size());
    for (const auto& row : rows) {
        result.push_back(Container::from_row(row));
    }
    return result;
}

auto ContainerRepositoryImpl::count(pqxx::work& tx) -> std::size_t {
    auto rows = tx.exec("SELECT count(*) FROM containers");
    return rows.front()[0].as<std::size_t>();
}

} // namespace cargo_operations
