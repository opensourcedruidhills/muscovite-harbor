// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann

#pragma once

#include <cstdint>
#include <optional>
#include <string>
#include <vector>

namespace muscovite_harbor::search {

// ── Pagination ──────────────────────────────────────────────────

struct PaginationParams {
    std::int32_t page_size = 20;
    std::string page_token;
};

struct PaginationResult {
    std::string next_page_token;
    std::int32_t total_count = 0;
    std::int32_t current_page = 0;
    std::int32_t total_pages = 0;

    [[nodiscard]] auto has_next_page() const -> bool {
        return !next_page_token.empty();
    }
};

/// Compute pagination metadata from offset and total.
[[nodiscard]] inline auto compute_pagination(
    std::int32_t offset,
    std::int32_t page_size,
    std::int32_t total_count) -> PaginationResult {
    auto result = PaginationResult{};
    result.total_count = total_count;
    result.current_page = (page_size > 0) ? (offset / page_size) : 0;
    result.total_pages = (page_size > 0) ? ((total_count + page_size - 1) / page_size) : 0;
    if (offset + page_size < total_count) {
        result.next_page_token = std::to_string(offset + page_size);
    }
    return result;
}

// ── Highlight / Snippet ────────────────────────────────────────

struct Highlight {
    std::string field;
    std::vector<std::string> fragments;
};

/// Extract a snippet from text around the first occurrence of query.
[[nodiscard]] inline auto extract_snippet(
    const std::string& text,
    const std::string& query,
    std::size_t context_chars = 80) -> std::string {
    if (query.empty() || text.empty()) return text.substr(0, context_chars * 2);
    auto pos = text.find(query);
    if (pos == std::string::npos) return text.substr(0, context_chars * 2);
    auto start = (pos > context_chars) ? pos - context_chars : std::size_t{0};
    auto end = std::min(text.size(), pos + query.size() + context_chars);
    auto snippet = std::string{};
    if (start > 0) snippet += "...";
    snippet += text.substr(start, end - start);
    if (end < text.size()) snippet += "...";
    return snippet;
}

/// Wrap occurrences of query in text with highlight markers.
[[nodiscard]] inline auto highlight_text(
    const std::string& text,
    const std::string& query,
    const std::string& pre_tag = "<em>",
    const std::string& post_tag = "</em>") -> std::string {
    if (query.empty()) return text;
    auto result = std::string{};
    std::size_t pos = 0;
    while (pos < text.size()) {
        auto found = text.find(query, pos);
        if (found == std::string::npos) {
            result += text.substr(pos);
            break;
        }
        result += text.substr(pos, found - pos);
        result += pre_tag + query + post_tag;
        pos = found + query.size();
    }
    return result;
}

// ── Result formatting ──────────────────────────────────────────

struct SearchResult {
    std::string id;
    std::string entity_type;
    std::string context;
    double score = 0.0;
    std::vector<Highlight> highlights;
};

struct FormattedSearchResponse {
    std::vector<SearchResult> results;
    PaginationResult pagination;
    std::int64_t took_ms = 0;
};

/// Format a score as a human-readable relevance percentage.
[[nodiscard]] inline auto format_score(double score, double max_score = 1.0) -> std::string {
    if (max_score <= 0.0) return "0%";
    auto pct = static_cast<int>((score / max_score) * 100.0);
    return std::to_string(pct) + "%";
}

} // namespace muscovite_harbor::search

