// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2026 Johannes Lochmann

#include <spdlog/spdlog.h>

#include "harbor/version.hpp"

auto main() -> int {
    spdlog::info("Muscovite Harbor {} ({})", harbor::kVersion, harbor::kGitSha);
    spdlog::info("Port operations management system");
    spdlog::info("Built: {}", harbor::kBuildTime);
    return 0;
}
