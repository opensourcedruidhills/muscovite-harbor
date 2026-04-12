# ADR-004: Generated Artifacts Are Checked In

**Status:** Accepted
**Date:** 2026-04-12
**Context:** Consumer project independence from muscomp toolchain at build time

## Decision

All muscomp-generated artifacts (C++ sources, SQL migrations, Proto definitions,
QML files, CMake modules) are **committed to the repository** and treated as
first-class source files.

This is the defining distinction from Muscovite's own example projects (hello-world,
self-model) where `generated/` is gitignored and regenerated on every build.

## Rationale

- **Build-time independence** — the harbor project builds with only the C++ toolchain
  and Conan dependencies. muscomp is not required at build time.
- **Deployable as-is** — CI/CD clones the repo, runs `conan install && cmake --build`,
  and gets a working binary. No muscomp installation needed.
- **Auditable diffs** — generated code changes are visible in PRs, making it easy to
  review what a DSL change actually produces.
- **Reproducibility** — the exact generated code that was tested is what gets deployed.
  No risk of muscomp version skew between dev and CI environments.
- **Onboarding** — new developers can build and run the project without understanding
  the Muscovite DSL or installing muscomp.

## Workflow

```
┌─────────────────────────────────────────────────────┐
│  Developer workstation (has muscomp)                │
│                                                     │
│  1. Edit .ddd/.mus files                           │
│  2. muscomp --project project.mus --full           │
│  3. Review generated/ diff                         │
│  4. git add generated/ && git commit               │
└─────────────────────────────────────────────────────┘
         │
         ▼
┌─────────────────────────────────────────────────────┐
│  CI / Production (no muscomp needed)                │
│                                                     │
│  1. git clone                                      │
│  2. conan install --profile conan_profiles/debug . │
│  3. cmake --preset debug && cmake --build --preset │
│  4. ctest --preset debug                           │
└─────────────────────────────────────────────────────┘
```

## muscomp as Dev-Time Tool

muscomp is needed **only** when changing the domain model:
- It is NOT a build dependency
- It is NOT listed in conanfile.py
- It is NOT invoked by CMakeLists.txt
- It is invoked manually or via a convenience script (`tools/regenerate.sh`)

## Consequences

- `generated/` is NOT in `.gitignore` — it is committed and tracked
- PRs that change `.ddd`/`.mus` files MUST include the regenerated output
- A CI lint step can optionally verify that generated code matches DSL
  (run muscomp and check for uncommitted diffs)
- The `MUSCOMP_VERSION` file records which muscomp version produced the
  current generated output, for traceability
