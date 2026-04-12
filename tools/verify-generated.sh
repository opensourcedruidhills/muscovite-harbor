#!/usr/bin/env bash
# SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
# Copyright (c) 2026 Johannes Lochmann
#
# Verify that checked-in generated code matches the current DSL model.
# Used in CI to catch PRs where .ddd/.mus changed but generated/ wasn't updated.
#
# Exit 0 = generated code is up to date
# Exit 1 = generated code is stale (diff found)

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"

MUSCOMP="${MUSCOMP_BIN:-muscomp}"

if ! command -v "$MUSCOMP" &>/dev/null; then
    echo "SKIP: muscomp not available — cannot verify generated code freshness." >&2
    echo "      This is expected in CI environments without muscomp." >&2
    exit 0
fi

cd "$PROJECT_ROOT"

# Regenerate to a temp location and compare
"$MUSCOMP" --project project.mus --cpp-dba --cpp-dba-test --grpc --qt-frontend widgets --test --full

if git diff --quiet generated/; then
    echo "OK: generated code matches DSL model."
    exit 0
else
    echo "FAIL: generated code is stale. Run tools/regenerate.sh and commit." >&2
    git --no-pager diff --stat generated/
    exit 1
fi
