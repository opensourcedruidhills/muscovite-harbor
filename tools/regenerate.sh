#!/usr/bin/env bash
# SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
# Copyright (c) 2026 Johannes Lochmann
#
# Regenerate all muscomp output from the DSL model.
# Run this after editing .ddd or .mus files.
#
# Prerequisites: muscomp must be on PATH or MUSCOMP_BIN set.
# The generated output is checked in (ADR-004), so commit the diff.

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"

MUSCOMP="${MUSCOMP_BIN:-muscomp}"

if ! command -v "$MUSCOMP" &>/dev/null; then
    echo "ERROR: muscomp not found. Set MUSCOMP_BIN or add muscomp to PATH." >&2
    echo "       muscomp is a dev-time tool — not needed for building." >&2
    exit 1
fi

echo "=== Regenerating harbor from DSL ==="
echo "  muscomp: $($MUSCOMP --version 2>/dev/null || echo "$MUSCOMP")"
echo "  project: $PROJECT_ROOT/project.mus"
echo ""

cd "$PROJECT_ROOT"

# Lint first
echo "--- Lint check ---"
"$MUSCOMP" --project project.mus --lint-only

# Full regeneration
echo ""
echo "--- Full generation ---"
"$MUSCOMP" --project project.mus --cpp-dba --cpp-dba-test --grpc --qt-frontend widgets --postgres --docs --test-data --full

# Show what changed
echo ""
echo "--- Generated diff ---"
git --no-pager diff --stat generated/ || true

echo ""
echo "Done. Review the diff, then: git add generated/ && git commit"
