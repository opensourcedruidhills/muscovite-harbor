# muscovite-harbor

A [Muscovite](https://github.com/opensourcedruidhills/muscovite) consumer project.
Generated code is produced by `muscomp` from the DSL source files.

## Prerequisites

| Tool | Version | Purpose |
|------|---------|---------|
| **muscomp** | ≥ 2.25.0 | Muscovite DSL compiler |
| **Conan 2** | ≥ 2.0 | C++ package manager |
| **CMake** | ≥ 3.25 | Build system (with Ninja) |
| **GCC** | ≥ 15 | C++23 compiler (or Clang ≥ 19) |
| **Docker** | Latest | PostgreSQL and NATS services |
| **Sqitch** | Latest | Database migration tool |

## Quick Start

```bash
# 1. Install Conan dependencies (brings in muscovite framework + muscomp compiler)
conan install --profile conan_profiles/debug .

# 2. Generate code from DSL
muscomp --project project.mus --cpp-dba --grpc --postgres --cmake \
        --qt-frontend both --docs --output generated/

# 3. Build
cmake --preset debug
cmake --build --preset debug

# 4. Start infrastructure
docker compose up -d

# 5. Deploy database
cd generated/database && sqitch deploy db:pg:muscovite-harbor
```

## Project Structure

```
project.mus              # Project configuration (databases, outputs, deployment)
contexts/                # Domain models (.ddd files) — THE source of truth
generated/               # All generated code (DO NOT EDIT)
  src/                   # C++ DBA + gRPC server
  database/              # PostgreSQL Sqitch migrations
  proto/                 # Protobuf definitions
  qt/                    # Qt Widgets + QML frontends
  doc/                   # Generated documentation
  docker-compose.yml     # Docker service definitions
  deployment-profiles/   # Environment configs (dev/qa/prod)
doc/                     # Reference documentation
  ARCHITECTURE.md        # Design principles
  DSL-QUICK-REFERENCE.md # .ddd syntax reference
  PROJECT-DSL-REFERENCE.md  # .mus syntax reference
  TYPE-MAPPINGS.md       # DSL → SQL → C++ → Proto → Qt type table
  MUSCOMP-REFERENCE.md   # Full CLI reference
  INFRASTRUCTURE.md      # Docker/services guide
.github/
  copilot-instructions.md  # AI agent instructions
  prompts/               # AI agent skills
conanfile.py             # Conan recipe (depends on muscovite + muscomp)
CMakeLists.txt           # Top-level CMake
```

## Key Concepts

### Never Edit Generated Code

Everything in `generated/` is produced by muscomp from the DSL. To change
generated output, edit the `.ddd` or `.mus` source files and regenerate:

```bash
muscomp --project project.mus --lint-only          # validate first
muscomp --project project.mus --full --output generated/  # regenerate
```

### DSL Files

| File | Format | Purpose |
|------|--------|---------|
| `project.mus` | Project DSL | Databases, frontends, capabilities, deployment |
| `contexts/*.ddd` | Domain DSL | Entities, aggregates, events, commands, sagas |

See `doc/DSL-QUICK-REFERENCE.md` and `doc/PROJECT-DSL-REFERENCE.md`.

### Type Safety

Types are preserved across the entire stack: DSL → PostgreSQL → C++ → Proto → Qt.
Unknown types cause generation to **fail**. See `doc/TYPE-MAPPINGS.md`.

### PEG Grammar

The PEG grammar (`muscovite.peg`) is the canonical definition of valid DSL syntax.
It is shipped with the muscomp Conan package. Read it before editing DSL files.

## Regenerating After DSL Changes

```bash
# 1. Lint (fast — catches errors before generation)
muscomp --project project.mus --lint-only

# 2. Regenerate
muscomp --project project.mus --full --output generated/

# 3. Build
cmake --build --preset debug

# 4. Test
ctest --preset debug --output-on-failure
```

## Infrastructure

See `doc/INFRASTRUCTURE.md` for Docker commands, health checks, and troubleshooting.

```bash
docker compose up -d     # Start PostgreSQL + NATS
docker compose down      # Stop
docker compose logs -f   # View logs
```

## Documentation

| Document | What it covers |
|----------|---------------|
| `doc/ARCHITECTURE.md` | Design principles and red lines |
| `doc/DSL-QUICK-REFERENCE.md` | .ddd syntax with examples |
| `doc/PROJECT-DSL-REFERENCE.md` | .mus configuration reference |
| `doc/TYPE-MAPPINGS.md` | Complete type mapping table |
| `doc/MUSCOMP-REFERENCE.md` | All muscomp CLI flags |
| `doc/INFRASTRUCTURE.md` | Docker, env vars, troubleshooting |

## License

Dual-licensed under AGPL-3.0 and Commercial. See [LICENSE](LICENSE).
