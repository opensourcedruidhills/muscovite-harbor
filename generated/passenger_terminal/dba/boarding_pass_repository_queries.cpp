// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace passenger_terminal {

auto BoardingPassRepositoryImpl::find_by_id(pqxx::work& tx, const std::string& id)
    -> std::optional<BoardingPass> {
    auto rows = tx.exec_params(kSelectById, id);
    if (rows.empty()) { return std::nullopt; }
    return BoardingPass::from_row(rows.front());
}

auto BoardingPassRepositoryImpl::find_all(pqxx::work& tx) -> std::vector<BoardingPass> {
    auto rows = tx.exec(kSelectAll);
    auto result = std::vector<BoardingPass>{};
    result.reserve(rows.size());
    for (const auto& row : rows) {
        result.push_back(BoardingPass::from_row(row));
    }
    return result;
}

auto BoardingPassRepositoryImpl::count(pqxx::work& tx) -> std::size_t {
    auto rows = tx.exec("SELECT count(*) FROM boarding_passs");
    return rows.front()[0].as<std::size_t>();
}

} // namespace passenger_terminal
