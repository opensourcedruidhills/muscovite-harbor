// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace intermodal_transfer {

auto TransferSlotRepositoryImpl::find_by_id(pqxx::work& tx, const std::string& id)
    -> std::optional<TransferSlot> {
    auto rows = tx.exec_params(kSelectById, id);
    if (rows.empty()) { return std::nullopt; }
    return TransferSlot::from_row(rows.front());
}

auto TransferSlotRepositoryImpl::find_all(pqxx::work& tx) -> std::vector<TransferSlot> {
    auto rows = tx.exec(kSelectAll);
    auto result = std::vector<TransferSlot>{};
    result.reserve(rows.size());
    for (const auto& row : rows) {
        result.push_back(TransferSlot::from_row(row));
    }
    return result;
}

auto TransferSlotRepositoryImpl::count(pqxx::work& tx) -> std::size_t {
    auto rows = tx.exec("SELECT count(*) FROM transfer_slots");
    return rows.front()[0].as<std::size_t>();
}

} // namespace intermodal_transfer
