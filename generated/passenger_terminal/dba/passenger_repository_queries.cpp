// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace passenger_terminal {

auto PassengerRepositoryImpl::find_by_id(pqxx::work& tx, const std::string& id)
    -> std::optional<Passenger> {
    auto rows = tx.exec_params(kSelectById, id);
    if (rows.empty()) { return std::nullopt; }
    return Passenger::from_row(rows.front());
}

auto PassengerRepositoryImpl::find_all(pqxx::work& tx) -> std::vector<Passenger> {
    auto rows = tx.exec(kSelectAll);
    auto result = std::vector<Passenger>{};
    result.reserve(rows.size());
    for (const auto& row : rows) {
        result.push_back(Passenger::from_row(row));
    }
    return result;
}

auto PassengerRepositoryImpl::count(pqxx::work& tx) -> std::size_t {
    auto rows = tx.exec("SELECT count(*) FROM passengers");
    return rows.front()[0].as<std::size_t>();
}

} // namespace passenger_terminal
