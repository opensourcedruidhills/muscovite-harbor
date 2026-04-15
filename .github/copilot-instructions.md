# Muscovite Harbor — Copilot Instructions

Muscovite Harbor is a **standalone consumer** of the Muscovite DSL toolchain.
All domain modeling is done in `.mus` and `.ddd` files, compiled by `muscomp`.
The Muscovite framework and all resources come exclusively from Conan — no
access to the muscovite source repository is needed.

## Muscovite Resources (via Conan)

After `conan install` + `cmake --preset debug`, these CMake cache variables
point to resources inside the Conan package:

| CMake Variable | Contents | Use For |
|----------------|----------|---------|
| `MUSCOVITE_GRAMMAR_DIR` | `muscovite.peg` | **Read this before editing .ddd files** |
| `MUSCOVITE_DOC_DIR` | `GROUND-TRUTH.md`, `IR-CHEATSHEET.md` | IR naming conventions, type mappings |
| `MUSCOVITE_TOOLS_DIR` | `lint-ddd.sh` | Relocatable DSL linter |
| `MUSCOVITE_MUSCOMP_DIR` | `muscomp` binary | DSL compiler (dev-time only) |

To read the grammar file on disk:

```bash
# Extract path from CMake cache
GRAMMAR_DIR=$(cmake --preset debug -N -L 2>/dev/null | grep MUSCOVITE_GRAMMAR_DIR | cut -d= -f2)
cat "$GRAMMAR_DIR/muscovite.peg"

# Or find it via Conan cache
CONAN_PKG=$(conan cache path muscovite/2.24.0)
cat "$CONAN_PKG/share/muscovite/grammar/muscovite.peg"
```

### Lint (after any .ddd/.mus change)

```bash
tools/lint.sh project.mus
# Or use the Conan-shipped lint tool directly:
LINT=$(cmake --preset debug -N -L 2>/dev/null | grep MUSCOVITE_TOOLS_DIR | cut -d= -f2)
"$LINT/lint-ddd.sh" project.mus
```

### Regenerate (requires muscomp on PATH or MUSCOMP_BIN set)

```bash
tools/regenerate.sh
```

## Rules

1. **DSL is the source of truth** — never hand-edit generated code (ADR-001)
2. **Fix the generator, not the output** — if generated code is wrong, fix the DSL or muscomp
3. **Generated code is committed** — PRs that change .ddd/.mus MUST include regenerated output (ADR-004)
4. **Build without muscomp** — CI only needs C++ toolchain + Conan
5. **GitHub Milestones for iterations** — no local planning files
6. **SPDX headers** — all source files need dual-license header (AGPL-3.0 + Commercial)
7. **ADRs for decisions** — document in `doc/adr/NNN-title.md`

## Bounded Contexts (6)

| Context | File | Key Constructs |
|---------|------|----------------|
| VesselTraffic | `contexts/vessel-traffic.ddd` | StateMachine, Bitemporal, Projections, Concurrency, Seed |
| CargoOperations | `contexts/cargo-operations.ddd` | EVENT_SOURCED, SourcedEvents, DECIDE/EMIT, Policy, Modules |
| PassengerTerminal | `contexts/passenger-terminal.ddd` | UseCase, UserStory, StoryMap, Qt widgets+QML |
| IntermodalTransfer | `contexts/intermodal-transfer.ddd` | Saga, Flow, FeatureFlag, LifecycleScheme, WorkStream |
| CargoDecomposition | `contexts/cargo-decomposition.ddd` | Mapping, LegacyView, LegacyProcedure, Instruct |
| HarbourControl | `contexts/harbour-control.ddd` | ForeignContext+ACL, ViewEntity, Fishbone, Deployment |

## Build

```bash
conan install --profile conan_profiles/debug .
cmake --preset debug && cmake --build --preset debug
ctest --preset debug
```

## Common DSL Grammar Pitfalls

These are patterns that frequently cause parse errors:

- **SEED** is an EntityClause (inside entity), not a ContextItem. Syntax: `SEED "label" { (val, ...) }`
- **INSTRUCT** is an EntityClause — must be inside an entity body
- **RELATIONSHIPS** / **BITEMPORAL** — EntityClause only, not context-level
- **State machine GUARD** takes a STRING: `GUARD "condition"`
- **EMIT in DECIDE** uses `:` — `EMIT Name(key: value)`
- **INVOKE in Policy/Saga** uses `=` with STRING — `INVOKE Name(key = "value")`
- **Repository method params** use space: `name TYPE` (not `name: TYPE`)
- **Wardley stages**: only GENESIS, CUSTOM, PRODUCT, COMMODITY
- **ALERT WHEN** (not CONDITION): `WHEN "expression";`
- **Saga ON COMPLETED/FAILED** go after the `}` closing the steps block
