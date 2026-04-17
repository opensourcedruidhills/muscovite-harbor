# Copilot Instructions for muscovite-harbor

This is a **Muscovite consumer project**. All code in `generated/` is produced by
`muscomp` from the DSL source files (`project.mus` + `contexts/*.ddd`).

---

## Iron Rules

1. **Never edit `generated/`** — fix the `.ddd`/`.mus` source and regenerate.
2. **SPDX headers on every hand-written file**:
   `SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial`
3. **Unknown types cause generation FAIL** — only use types from `doc/TYPE-MAPPINGS.md`.
4. **No implicit foreign keys** — every FK requires explicit `RELATIONSHIPS {}` block.
5. **C++23 only** — no raw loops, no C-style casts, no `new`/`delete`.

---

## Before Editing DSL Files

**Read the PEG grammar first.** The grammar is the canonical syntax definition.
Location: `share/muscomp/grammar/muscovite.peg` (shipped with muscomp Conan package).

References:
- `doc/DSL-QUICK-REFERENCE.md` — .ddd construct examples
- `doc/PROJECT-DSL-REFERENCE.md` — .mus configuration reference
- `doc/TYPE-MAPPINGS.md` — complete type mapping table (DSL → SQL → C++ → Proto → Qt)

---

## Build Commands

```bash
# Install dependencies (muscovite framework + muscomp compiler)
conan install --profile conan_profiles/debug .

# Lint DSL (fast validation, ~2s)
muscomp --project project.mus --lint-only

# Regenerate all targets
muscomp --project project.mus --cpp-dba --grpc --postgres --cmake \
        --qt-frontend both --docs --search --messaging --tlaplus \
        --test-data --output generated/

# Force full regeneration (when incremental is stale)
muscomp --project project.mus --full --output generated/

# Build C++
cmake --preset debug
cmake --build --preset debug

# Run tests
ctest --preset debug --output-on-failure
```

---

## Infrastructure

```bash
docker compose up -d              # Start PostgreSQL + NATS
docker compose down               # Stop (preserves data)
docker compose down -v            # Stop + destroy data
docker compose logs -f postgres   # View logs

# Database migrations
cd generated/database
sqitch deploy db:pg:muscovite-harbor
sqitch verify db:pg:muscovite-harbor
```

See `doc/INFRASTRUCTURE.md` for health checks, troubleshooting, and deployment profiles.

---

## muscomp CLI Reference

Full reference: `doc/MUSCOMP-REFERENCE.md`

Key flags:

| Flag | Purpose |
|------|---------|
| `--project FILE` | Path to `project.mus` (required) |
| `--output DIR` | Output directory |
| `--lint-only` | Parse + validate, no generation (~2s) |
| `--full` | Force complete regeneration |
| `--dry-run` | Preview without writing |
| `--cpp-dba` | Generate C++ database access |
| `--grpc` | Generate gRPC services |
| `--postgres` | Generate PostgreSQL migrations |
| `--cmake` | Generate CMakeLists.txt |
| `--qt-frontend {widgets\|qml\|both\|none}` | Qt frontend type |
| `--docs` | Generate documentation |
| `--search` | Generate OpenSearch schema |
| `--messaging` | Generate NATS messaging |
| `--tlaplus` | Generate TLA+ specifications |
| `--test-data` | Generate SQL test fixtures |
| `--explain` | Verbose decision logging |
| `--emit-ir` | Write debug IR file |

---

## Type System

**Strict policy**: Unknown types → generation FAIL. No silent fallbacks.

Common types (full table in `doc/TYPE-MAPPINGS.md`):

| DSL Type | PostgreSQL | C++ |
|----------|------------|-----|
| UUID | `UUID` | `boost::uuids::uuid` |
| String, TEXT | `TEXT` | `std::string` |
| Integer, INT | `INTEGER` | `std::int32_t` |
| BigInteger, BIGINT | `BIGINT` | `std::int64_t` |
| Decimal, NUMERIC | `NUMERIC` | `muscovite::dba::Decimal` |
| Boolean | `BOOLEAN` | `bool` |
| Date | `DATE` | `muscovite::dba::Date` |
| DateTime, TIMESTAMPTZ | `TIMESTAMPTZ` | `muscovite::dba::Timestamp` |
| Email, Phone, URL | `TEXT` (DOMAIN) | `std::string` |
| Point, Polygon | `GEOGRAPHY(*)` | `std::string` (WKT) |

---

## Database Conventions

- All PKs named `id`, type `UUID`
- All strings as `TEXT` (never `VARCHAR`)
- All datetime as `TIMESTAMPTZ` (never `TIMESTAMP`)
- No JSONB for domain entity fields
- Use `LOOKUP_TABLE` for enumerations (never PostgreSQL ENUM or CHECK)
- FKs require explicit `RELATIONSHIPS {}` (never inferred from `_id` naming)
- Deploy via Sqitch only (never hand-write `ALTER TABLE`)

---

## Architecture Principles

See `doc/ARCHITECTURE.md` for the full set.

Key principles:
1. **The Model Is the System** — `.ddd` is canonical, generated code is projection
2. **Explicit Over Implicit** — nothing inferred from naming
3. **Type Safety Spans the Stack** — DSL → SQL → C++ → Proto → Qt
4. **Layers Never Collapse** — Generator (L0) → Framework (L1) → Generated (L2)
5. **Quality Is Binary** — pass or fail, never warn

---

## Skills

Available skills in `.github/prompts/`:

| Skill | When to use |
|-------|-------------|
| `skill-regenerate` | After any `.ddd`/`.mus` edit |
| `skill-add-entity` | Adding entities, VOs, aggregates, commands, events |
| `skill-modify-dsl` | Any DSL syntax changes (master reference) |
| `skill-infrastructure` | Docker start/stop/monitor/troubleshoot |
| `skill-debug-build` | Conan, CMake, C++, linker failures |

---

## Project Layout

```
project.mus              # Project configuration
contexts/                # Domain models (.ddd files)
generated/               # Generated code (DO NOT EDIT)
doc/                     # Reference documentation
.github/prompts/         # AI agent skills
conanfile.py             # Conan recipe
CMakeLists.txt           # Build configuration
```

## Conan Dependency Chain

`conan install` brings in:
- **muscovite** framework (dba, server, grpc, messaging, search libraries)
- **muscomp** compiler (as `tool_requires` — available for code generation)
- All transitive dependencies (Boost, gRPC, Protobuf, spdlog, etc.)

The PEG grammar is shipped in the muscomp package at `share/muscomp/grammar/muscovite.peg`.
