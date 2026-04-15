# Muscovite Harbor — Agent Operations Guide

Muscovite Harbor is a **standalone consumer** of the Muscovite framework.
Everything needed to build and work on this project comes from Conan.
No access to the muscovite source repo is required.

## Build (no muscomp needed)

```bash
conan install --profile conan_profiles/debug .
cmake --preset debug
cmake --build --preset debug
ctest --preset debug
```

## Muscovite Resources (from Conan package)

After `cmake --preset debug`, the following CMake variables point to
resources inside the Conan cache — use them, never hardcode paths.

| CMake Variable | Contents |
|----------------|----------|
| `MUSCOVITE_GRAMMAR_DIR` | `muscovite.peg` — PEG grammar (authoritative DSL syntax reference) |
| `MUSCOVITE_DOC_DIR` | `GROUND-TRUTH.md`, `IR-CHEATSHEET.md` — IR naming/types |
| `MUSCOVITE_TOOLS_DIR` | `lint-ddd.sh` — relocatable DSL linter |
| `MUSCOVITE_MUSCOMP_DIR` | `muscomp` binary (if installed) |

To find the actual path on disk (for reading the grammar):

```bash
cmake --preset debug -N -L 2>/dev/null | grep MUSCOVITE_GRAMMAR_DIR
# Or: locate the Conan package cache directly
conan cache path muscovite/2.24.0
```

## DSL Editing Workflow

1. **Read the PEG grammar first** (see `MUSCOVITE_GRAMMAR_DIR/muscovite.peg`)
2. Edit `.ddd` or `.mus` files
3. Lint: `tools/lint.sh project.mus` (requires muscomp on PATH or MUSCOMP_BIN)
4. Regenerate: `tools/regenerate.sh`
5. Build and test
6. Commit DSL changes AND generated output together

## Regenerate (requires muscomp)

muscomp is a dev-time tool, NOT a build dependency. Install it separately
(see https://github.com/opensourcedruidhills/muscovite for build instructions).

```bash
tools/regenerate.sh
git add generated/ && git commit -m "regen: update generated code"
```

## Bounded Contexts

| Context | File | Domain |
|---------|------|--------|
| VesselTraffic | `contexts/vessel-traffic.ddd` | Vessel scheduling, AIS tracking, berth allocation |
| CargoOperations | `contexts/cargo-operations.ddd` | Event-sourced cargo manifests, bill of lading |
| PassengerTerminal | `contexts/passenger-terminal.ddd` | Check-in, boarding, passenger management |
| IntermodalTransfer | `contexts/intermodal-transfer.ddd` | Modal transfers, sagas, feature flags |
| CargoDecomposition | `contexts/cargo-decomposition.ddd` | Legacy integration, cargo breakdown |
| HarbourControl | `contexts/harbour-control.ddd` | Port authority, foreign context ACL |

## Key Rules

1. **DSL is source of truth** — never hand-edit files in `generated/`
2. **Fix the generator, not the output** — if generated code is wrong, fix the DSL or muscomp
3. **Generated code is committed** — PRs that change .ddd/.mus MUST include regenerated output
4. **Build without muscomp** — CI only needs C++ toolchain + Conan
5. **SPDX headers** — dual-licensed AGPL-3.0 + Commercial on all files

## Version Files

| File | Purpose |
|------|---------|
| `HARBOR_VERSION` | Project version (semver) |
| `MUSCOMP_VERSION` | muscomp version that produced `generated/` |

