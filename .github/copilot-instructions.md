# Copilot Instructions for Muscovite Harbor

This is a Muscovite consumer project. Code in `generated/` is produced by `muscomp`
from the DSL files (`project.mus` + `contexts/*.ddd`).

## Key Rules

1. **Never edit generated code** — fix the `.mus`/`.ddd` source or the muscomp generator instead.
2. **SPDX headers** — every hand-written file needs: `SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial`
3. **Regenerate after DSL changes**: `muscomp --project project.mus --full --output generated/`
4. **C++23** — no raw loops, no C-style casts.
5. **PostgreSQL conventions** — TEXT (not VARCHAR), TIMESTAMPTZ, `id` as PK.

## Build Commands

```bash
muscomp --project project.mus --full --output generated/   # regenerate
conan install --profile conan_profiles/debug .              # dependencies
cmake --preset debug && cmake --build --preset debug        # build
```
