// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace vessel_traffic {

auto VesselRepositoryImpl::find_by_id(pqxx::work& tx, const std::string& id)
    -> std::optional<Vessel> {
    auto rows = tx.exec_params(kSelectById, id);
    if (rows.empty()) { return std::nullopt; }
    return Vessel::from_row(rows.front());
}

auto VesselRepositoryImpl::find_all(pqxx::work& tx) -> std::vector<Vessel> {
    auto rows = tx.exec(kSelectAll);
    auto result = std::vector<Vessel>{};
    result.reserve(rows.size());
    for (const auto& row : rows) {
        result.push_back(Vessel::from_row(row));
    }
    return result;
}

auto VesselRepositoryImpl::count(pqxx::work& tx) -> std::size_t {
    auto rows = tx.exec("SELECT count(*) FROM vessels");
    return rows.front()[0].as<std::size_t>();
}

} // namespace vessel_traffic
