// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace intermodal_transfer {

auto RailWagonRepositoryImpl::find_by_id(pqxx::work& tx, const std::string& id)
    -> std::optional<RailWagon> {
    auto rows = tx.exec_params(kSelectById, id);
    if (rows.empty()) { return std::nullopt; }
    return RailWagon::from_row(rows.front());
}

auto RailWagonRepositoryImpl::find_all(pqxx::work& tx) -> std::vector<RailWagon> {
    auto rows = tx.exec(kSelectAll);
    auto result = std::vector<RailWagon>{};
    result.reserve(rows.size());
    for (const auto& row : rows) {
        result.push_back(RailWagon::from_row(row));
    }
    return result;
}

auto RailWagonRepositoryImpl::count(pqxx::work& tx) -> std::size_t {
    auto rows = tx.exec("SELECT count(*) FROM rail_wagons");
    return rows.front()[0].as<std::size_t>();
}

} // namespace intermodal_transfer
