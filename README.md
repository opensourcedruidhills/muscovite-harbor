# Muscovite Harbor

A [Muscovite](https://github.com/opensourcedruidhills/muscovite) consumer project — harbour operations platform demonstrating ~48/50 DSL constructs across 6 bounded contexts: vessel traffic, cargo operations, intermodal transfer, cargo decomposition, passenger terminal, harbour control.

## Prerequisites

- **muscomp** — the Muscovite compiler (v2.25.0+)
- **Conan 2** — C++ package manager
- **CMake 3.25+** with Ninja
- **GCC 15** or Clang 19 (C++23 required)
- **Docker** (for PostgreSQL and NATS)

## Quick Start

```bash
# 1. Generate code from DSL
muscomp --project project.mus --cpp-dba --grpc --qt-frontend both \
        --postgres --cmake --docs --search --messaging --tlaplus --test-data \
        --output generated/

# 2. Install dependencies
conan install --profile conan_profiles/debug .

# 3. Build
cmake --preset debug
cmake --build --preset debug

# 4. Start services
docker compose up -d
```

Or simply run:

```bash
chmod +x generated/bootstrap.sh && ./generated/bootstrap.sh
```

## Project Structure

```
project.mus          # Project configuration (databases, outputs, deployment)
contexts/            # Domain models (.ddd files)
  cargo-decomposition.ddd
  cargo-operations.ddd
  harbour-control.ddd
  intermodal-transfer.ddd
  passenger-terminal.ddd
  vessel-traffic.ddd
generated/           # All generated code (do not edit)
  database/          # PostgreSQL migrations (catalog pipeline)
  src/               # C++ DBA + gRPC server
  qt/                # Qt Widgets + QML frontends
  proto/             # Protobuf definitions
  doc/               # Generated documentation
  search/            # OpenSearch schemas
  messaging/         # NATS subject + outbox relay
```

## Regenerating

After editing `.mus` or `.ddd` files:

```bash
muscomp --project project.mus --full --output generated/
```

## License

Dual-licensed under AGPL-3.0 and Commercial. See [LICENSE](LICENSE).
