// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace cargo_operations {

auto DischargeSequenceRepositoryImpl::find_by_id(pqxx::work& tx, const std::string& id)
    -> std::optional<DischargeSequence> {
    auto rows = tx.exec_params(kSelectById, id);
    if (rows.empty()) { return std::nullopt; }
    return DischargeSequence::from_row(rows.front());
}

auto DischargeSequenceRepositoryImpl::find_all(pqxx::work& tx) -> std::vector<DischargeSequence> {
    auto rows = tx.exec(kSelectAll);
    auto result = std::vector<DischargeSequence>{};
    result.reserve(rows.size());
    for (const auto& row : rows) {
        result.push_back(DischargeSequence::from_row(row));
    }
    return result;
}

auto DischargeSequenceRepositoryImpl::count(pqxx::work& tx) -> std::size_t {
    auto rows = tx.exec("SELECT count(*) FROM discharge_sequences");
    return rows.front()[0].as<std::size_t>();
}

} // namespace cargo_operations
