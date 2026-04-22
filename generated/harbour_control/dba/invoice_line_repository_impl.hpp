#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "invoice_line.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace harbour_control {

/// Concrete CRTP repository implementation for InvoiceLine.
/// Satisfies RepositoryBase<InvoiceLineRepositoryImpl<C>, InvoiceLine> contract.
/// Uses parameterised SQL (pqxx) — no stored procedures (ADR 20260120).
template<typename Connection>
class InvoiceLineRepositoryImpl {
public:
    explicit InvoiceLineRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto build_select_by_id_query() const -> std::string {
        return "SELECT id, id, vessel_id, service_type, amount, currency, issued_at FROM harbour_control.invoice_line WHERE id = $1";
    }

    [[nodiscard]] auto build_insert_query() const -> std::string {
        return "INSERT INTO harbour_control.invoice_line (id, id, vessel_id, service_type, amount, currency, issued_at) VALUES ($1, $2, $3, $4, $5, $6, $7) RETURNING id";
    }

    [[nodiscard]] auto build_update_query() const -> std::string {
        return "UPDATE harbour_control.invoice_line SET id = $2, vessel_id = $3, service_type = $4, amount = $5, currency = $6, issued_at = $7 WHERE id = $1";
    }

    [[nodiscard]] auto build_delete_query() const -> std::string {
        return "DELETE FROM harbour_control.invoice_line WHERE id = $1";
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> InvoiceLine {
        return InvoiceLine{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .vessel_id = row[2].as<std::string>(),
            .service_type = row[3].as<std::string>(),
            .amount = row[4].as<std::string>(),
            .currency = row[5].as<std::string>(),
            .issued_at = row[6].as<std::string>(),
        };
    }

    auto save(const InvoiceLine& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_insert_query(), entity.id, entity.id, entity.vessel_id, entity.service_type, entity.amount, entity.currency, entity.issued_at);
        tx.commit();
    }

    auto update(const InvoiceLine& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_update_query(), entity.id, entity.id, entity.vessel_id, entity.service_type, entity.amount, entity.currency, entity.issued_at);
        if (result.affected_rows() == 0) {
            throw std::runtime_error("InvoiceLine not found: " + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(build_delete_query(), id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<InvoiceLine> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(build_select_by_id_query(), id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

private:
    Connection& conn_;
};

} // namespace harbour_control
