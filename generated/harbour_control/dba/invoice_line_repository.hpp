#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>
#include <vector>

namespace harbour_control {

/// Repository interface for InvoiceLine.
class InvoiceLineRepository {
public:
    virtual ~InvoiceLineRepository() = default;

    [[nodiscard]] virtual auto find_by_id(const std::string& id) const
        -> std::optional<InvoiceLine> = 0;

    [[nodiscard]] virtual auto find_all() const
        -> std::vector<InvoiceLine> = 0;

    virtual auto save(const InvoiceLine& entity) -> void = 0;

    virtual auto remove(const std::string& id) -> void = 0;
};

} // namespace harbour_control
