#!/usr/bin/env bash
# SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
# Copyright (c) 2026 Johannes Lochmann
#
# Lint .ddd/.mus files using muscomp --lint-only.
# Finds muscomp from: MUSCOMP_BIN > PATH.
#
# Usage: tools/lint.sh <project.mus> [--format json]

set -euo pipefail

MUSCOMP="${MUSCOMP_BIN:-muscomp}"

if ! command -v "$MUSCOMP" &>/dev/null; then
    echo "ERROR: muscomp not found. Set MUSCOMP_BIN or add muscomp to PATH." >&2
    echo "       muscomp is a dev-time tool — not needed for building." >&2
    exit 2
fi

if [[ $# -lt 1 ]]; then
    echo "Usage: tools/lint.sh <project.mus> [--format json]" >&2
    exit 2
fi

PROJECT="$1"
shift

LINT_CMD=("$MUSCOMP" --lint-only --project "$PROJECT")

for arg in "$@"; do
    case "$arg" in
        --format)  ;; # next arg is the format value
        json)      LINT_CMD+=(--json) ;;
        text)      ;; # default
        *)         LINT_CMD+=("$arg") ;;
    esac
done

exec "${LINT_CMD[@]}"
