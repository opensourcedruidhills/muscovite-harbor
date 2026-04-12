// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2026 Johannes Lochmann

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include "version.hpp"

SCENARIO("harbor version is set") {
    GIVEN("the harbor binary") {
        THEN("version string is non-empty") {
            CHECK(std::string_view{harbor::kVersion}.size() > 0);
        }
        THEN("version follows semver") {
            auto v = std::string_view{harbor::kVersion};
            CHECK(v.find('.') != std::string_view::npos);
        }
    }
}
