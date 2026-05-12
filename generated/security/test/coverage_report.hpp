#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <fstream>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

namespace security {

/// Generates a JSON coverage summary for all entities.
inline auto generate_json_coverage_report(
    const std::string& output_path,
    const std::vector<std::pair<std::string, double>>& results) -> bool {
    auto ofs = std::ofstream{output_path};
    if (!ofs.is_open()) { return false; }
    ofs << "{\n  \"context\": \"security\",\n  \"entities\": [\n";
    for (std::size_t i = 0; i < results.size(); ++i) {
        ofs << "    {\"name\": \"" << results[i].first
            << "\", \"coverage_pct\": " << results[i].second << "}";
        if (i + 1 < results.size()) { ofs << ","; }
        ofs << "\n";
    }
    ofs << "  ]\n}\n";
    return true;
}

/// Generates an HTML coverage summary report.
inline auto generate_html_coverage_report(
    const std::string& output_path,
    const std::vector<std::pair<std::string, double>>& results) -> bool {
    auto ofs = std::ofstream{output_path};
    if (!ofs.is_open()) { return false; }
    ofs << "<!DOCTYPE html>\n<html><head>\n";
    ofs << "<title>Coverage Report: security</title>\n";
    ofs << "<style>table{border-collapse:collapse}td,th{border:1px solid #ccc;padding:8px}</style>\n";
    ofs << "</head><body>\n";
    ofs << "<h1>Coverage Report: security</h1>\n";
    ofs << "<table><tr><th>Entity</th><th>Coverage %</th><th>Status</th></tr>\n";
    for (const auto& [name, pct] : results) {
        auto status = (pct >= 80.0) ? "PASS" : "FAIL";
        auto color = (pct >= 80.0) ? "green" : "red";
        ofs << "<tr><td>" << name << "</td><td>" << pct
            << "</td><td style=\"color:" << color << "\">"
            << status << "</td></tr>\n";
    }
    ofs << "</table></body></html>\n";
    return true;
}

} // namespace security
