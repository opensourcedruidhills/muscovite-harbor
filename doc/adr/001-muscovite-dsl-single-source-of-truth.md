# ADR-001: Muscovite DSL as Single Source of Truth

**Status:** Accepted
**Date:** 2026-04-12
**Context:** Project inception

## Decision

All domain modeling, database schema, API definitions, and UI scaffolding for Muscovite Harbor
are defined exclusively in Muscovite DSL files (`.mus` project configuration, `.ddd` domain contexts).

Generated code (C++, SQL, Proto, QML) MUST NOT be hand-edited. If the output is wrong,
the generator or the DSL model is fixed — never the generated artifact.

## Rationale

- **Single source of truth** eliminates drift between schema, API, and UI
- **Reproducible builds** — `muscomp` regenerates all targets from DSL
- **Semantic diff migrations** — schema changes are derived, not hand-written
- **Type safety** — the compiler catches domain inconsistencies at DSL level

## Consequences

- All team members must learn Muscovite DSL syntax
- No hand-written ALTER TABLE or manual proto edits
- CI/CD must include `muscomp --lint-only` as a quality gate
- Generated directory is gitignored; CI regenerates from DSL
