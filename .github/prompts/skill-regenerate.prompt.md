# Skill: Regenerate from DSL

Use this skill after any change to `.mus` or `.ddd` files.

## When to use

- After editing any `.ddd` file (entity, aggregate, event, etc.)
- After editing `project.mus` (database config, capabilities, etc.)
- After pulling changes that modified DSL files
- After resolving merge conflicts in DSL files

## Procedure

### Step 1: Lint (fast validation)

```bash
muscomp --project project.mus --lint-only
```

If this fails, fix the DSL errors before proceeding. Common errors:
- Unknown type (check `doc/TYPE-MAPPINGS.md`)
- Missing `RELATIONSHIPS {}` block for foreign keys
- Duplicate `@UUID` values
- Missing `IDENTIFIED_BY` on entities

### Step 2: Regenerate

```bash
muscomp --project project.mus --cpp-dba --grpc --postgres --cmake \
        --qt-frontend both --docs --search --messaging --tlaplus \
        --test-data --output generated/
```

Use `--full` if incremental generation produces stale files:

```bash
muscomp --project project.mus --full --output generated/
```

### Step 3: Build and verify

```bash
cmake --build --preset debug
ctest --preset debug --output-on-failure
```

### Step 4: Commit

Commit DSL changes and generated output together:

```bash
git add project.mus contexts/ generated/
git commit -m "feat: <describe what changed in the domain model>"
```

## Troubleshooting

### "Unknown type" error

Check `doc/TYPE-MAPPINGS.md` for valid types. The type must be listed exactly
as shown. Common mistakes:
- `Varchar` → use `String` or `TEXT`
- `Timestamp` → use `TIMESTAMPTZ` or `DateTime`
- `Enum` → use `LOOKUP_TABLE` instead

### Stale generated files

```bash
muscomp --project project.mus --fresh --output generated/
```

**Warning**: `--fresh` deletes the entire output directory first. Only use for
greenfield or when incremental generation is broken.

### Sidecar files overwritten

Sidecar stubs are only generated on first run. If you accidentally used
`--force-regen-stubs`, check `git diff` and restore your implementations.
