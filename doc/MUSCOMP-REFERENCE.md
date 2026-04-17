# muscomp CLI Reference

muscomp is the Muscovite DSL compiler. It reads `.mus` project files and `.ddd`
domain model files and generates code for 8+ targets.

## Installation

muscomp is available as a Conan tool package:

```python
# In your conanfile.py
def build_requirements(self):
    self.tool_requires("muscomp/[>=2.25.0]")
```

After `conan install`, muscomp is available in your build environment.

## Basic Usage

```bash
# Full generation (all targets configured in project.mus)
muscomp --project project.mus --cpp-dba --grpc --postgres --cmake \
        --qt-frontend both --output generated/

# Force complete regeneration
muscomp --project project.mus --full --output generated/

# Lint only (parse + validate, no code generation) — fast (~2s)
muscomp --project project.mus --lint-only

# Parse only (no validation or generation)
muscomp --project project.mus --parse-only

# Dry run (preview what would be generated)
muscomp --project project.mus --dry-run

# Scaffold a new project
muscomp --create my-project --from /path/to/source.mus --create-dir /path/to/output
```

## All Flags

### Input/Output

| Flag | Type | Description |
|------|------|-------------|
| `-p, --project` | `FILE` | Path to `project.mus` file (required for generation) |
| `-o, --output` | `DIR` | Override output directory (default: from project.mus `OUTPUT` field) |
| `--grammar` | `FILE` | Path to PEG grammar file (default: embedded) |

### Code Generation Targets

| Flag | Description |
|------|-------------|
| `--cpp-dba` | Generate C++ database access layer |
| `--cpp-dba-test` | Generate C++ DBA unit tests |
| `--grpc` | Generate gRPC service definitions + server code |
| `--grpc-test` | Generate gRPC service tests |
| `--postgres` | Generate PostgreSQL migrations (Sqitch) |
| `--cmake` | Generate CMakeLists.txt for the project |
| `--docs` | Generate documentation (Glossary + Fact Base) |
| `--search` | Generate OpenSearch schema for `@searchable` fields |
| `--messaging` | Generate NATS subject schema + outbox relay |
| `--tlaplus` | Generate TLA+ saga specifications |
| `--test-data` | Generate test seed data (SQL INSERT fixtures) |
| `--proto-ir` | Generate proto3 IR schema from domain model |
| `--qt-frontend` | `widgets`, `qml`, `both`, or `none` — Qt frontend type |
| `--qt-test` | Generate Qt frontend tests |

### Generation Modes

| Flag | Description |
|------|-------------|
| `--full` | Force full regeneration (ignore incremental cache) |
| `--fresh` | Delete output directory before generation (greenfield only) |
| `--force-fresh` | Force `--fresh` even with existing artifacts |
| `--dry-run` | Preview what would be generated without writing files |
| `--lint-only` | Parse and validate without generating — fast quality check |
| `--parse-only` | Parse only, no validation or generation |
| `--incremental` | `auto` (default), `full`, or `dry-run` |
| `--force-regen-stubs` | Force sidecar stub regeneration (overwrites hand-written stubs!) |

### Validation and Diagnostics

| Flag | Description |
|------|-------------|
| `--validate-output` | Validate syntax of generated SQL, Proto, CMake files |
| `--validate-sql-dir DIR` | Standalone: validate all `.sql` files in directory |
| `--skip-verify` | Skip verification step |
| `--emit-ir` | Write debug IR file alongside output |
| `--explain` | Verbose decision logging during generation |
| `--stats` | Print model metrics summary after generation |
| `--json` | Output diagnostics in JSON format |

### PostgreSQL Pipeline

| Flag | Description |
|------|-------------|
| `--pg-catalog` | Use catalog-based PostgreSQL pipeline (new) |
| `--pg-shadow` | Run dual-path generation and compare outputs |
| `--diff-from REF` | Git ref to parse old `.ddd` from for catalog diff |
| `--migration-plan` | Generate migration planning from `MIGRATION_STREAM` definitions |

### Planning and Lifecycle

| Flag | Description |
|------|-------------|
| `--plan` | Generate Kanban planning from domain model |
| `--plan-json` | Export planning output as JSON |
| `--plan-simulate` | Show projected timeline simulation |
| `--plan-diff` | Show delta against existing `.plan` file |
| `--lifecycle` | Generate lifecycle scheme + feature flag artifacts |
| `--ops-lifecycle` | Generate ops lifecycle artifacts |
| `--otel-conventions` | Generate OTel convention YAML + C++ instrumentation header |
| `--bridge` | Generate bridge adapter stubs + sync dashboard |

### Scaffolding

| Flag | Description |
|------|-------------|
| `--create NAME` | Scaffold a new consumer project with given name |
| `--create-dir DIR` | Output directory for `--create` |
| `--from PATH` | Source `.mus` project file or `.ddd` directory for `--create` |

### Reference Generation

| Flag | Description |
|------|-------------|
| `--generate-dsl-reference` | Generate `DSL.md` reference documentation |
| `--generate-project-dsl-reference` | Generate `PROJECT-DSL.md` reference documentation |
| `--generate-template-dsl-reference` | Generate `TEMPLATE-DSL.md` reference documentation |
| `--reference-output FILE` | Output file path for reference documentation |

### Other

| Flag | Description |
|------|-------------|
| `--plugin-dir DIR` | Directory for plugin `.so` files (env: `MUSCOMP_PLUGIN_DIR`) |
| `--version` | Display version information |
| `-h, --help` | Print help message |

## Common Workflows

### After editing `.ddd` files

```bash
# 1. Lint first (catches syntax/semantic errors fast)
muscomp --project project.mus --lint-only

# 2. Regenerate
muscomp --project project.mus --cpp-dba --grpc --postgres --cmake \
        --qt-frontend both --output generated/

# 3. Build
cmake --build --preset debug
```

### After editing `project.mus`

```bash
# Regenerate everything (project-level changes affect all targets)
muscomp --project project.mus --full --output generated/
```

### Debugging generation issues

```bash
# Verbose logging shows every decision
muscomp --project project.mus --explain --cpp-dba --output generated/

# Emit IR for inspection
muscomp --project project.mus --emit-ir --output generated/

# Validate generated SQL syntax
muscomp --project project.mus --validate-output --postgres --output generated/
```

## Environment Variables

| Variable | Purpose |
|----------|---------|
| `MUSCOMP_PLUGIN_DIR` | Directory to scan for plugin `.so` files |
| `MUSCOMP_TEMPLATE_DIR` | Override template-project directory for `--create` |

## Exit Codes

| Code | Meaning |
|------|---------|
| 0 | Success |
| 1 | Generation error (parse failure, validation error, I/O error) |
| 2 | Invalid arguments |
