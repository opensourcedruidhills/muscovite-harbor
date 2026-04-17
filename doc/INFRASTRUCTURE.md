# Infrastructure Guide

## Services

This project uses Docker Compose for local infrastructure.
The generated `docker-compose.yml` defines the required services.

### PostgreSQL

- **Image**: `postgres:16-alpine`
- **Port**: 5432 (configurable via `POSTGRES_PORT`)
- **Health check**: `pg_isready`
- **Data volume**: `pgdata` (persistent across restarts)

Schemas are auto-created by `docker/init-schemas.sql` (one schema per bounded context).

### NATS (JetStream)

- **Image**: `nats:2-alpine`
- **Client port**: 4222 (configurable via `NATS_PORT`)
- **Monitor port**: 8222 (configurable via `NATS_MONITOR_PORT`)
- **JetStream**: Enabled by default (required for Outbox pattern)

## Docker Commands

```bash
# Start all services
docker compose up -d

# Start individual service
docker compose up -d postgres
docker compose up -d nats

# Stop all services
docker compose down

# Stop and remove volumes (destroys data)
docker compose down -v

# View logs
docker compose logs -f postgres
docker compose logs -f nats

# Check health
docker compose ps
```

## Health Checks

```bash
# PostgreSQL
docker compose exec postgres pg_isready -U muscovite-harbor

# NATS
curl -s http://localhost:8222/healthz

# NATS JetStream streams
curl -s http://localhost:8222/jsz | jq .

# NATS connections
curl -s http://localhost:8222/connz | jq .
```

## Environment Configuration

Environment variables are defined in `.env` (not committed) or
`generated/deployment-profiles/*.env.example` (committed as templates).

### Deployment Profiles

| Profile | File | Purpose |
|---------|------|---------|
| Development | `generated/deployment-profiles/dev.env.example` | Local development |
| QA | `generated/deployment-profiles/qa.env.example` | Testing/staging |
| Production | `generated/deployment-profiles/prod.env.example` | Production deployment |

Copy the appropriate profile:

```bash
cp generated/deployment-profiles/dev.env.example .env
# Edit .env with your local settings
```

### Key Environment Variables

| Variable | Default | Description |
|----------|---------|-------------|
| `POSTGRES_DB` | `muscovite-harbor` | PostgreSQL database name |
| `POSTGRES_USER` | `muscovite-harbor` | PostgreSQL user |
| `POSTGRES_PASSWORD` | `changeme` | PostgreSQL password (**change in production**) |
| `POSTGRES_PORT` | `5432` | PostgreSQL host port |
| `NATS_PORT` | `4222` | NATS client port |
| `NATS_MONITOR_PORT` | `8222` | NATS monitoring port |

## Database Operations

### Connect via psql

```bash
# Via Docker
docker compose exec postgres psql -U muscovite-harbor -d muscovite-harbor

# Direct connection
psql -h localhost -p 5432 -U muscovite-harbor -d muscovite-harbor
```

### Sqitch Migrations

Generated migrations are in `generated/database/`. Deploy with Sqitch:

```bash
cd generated/database
sqitch deploy db:pg:muscovite-harbor
sqitch verify db:pg:muscovite-harbor
sqitch status db:pg:muscovite-harbor

# Revert last change
sqitch revert --to @HEAD^ db:pg:muscovite-harbor
```

## Troubleshooting

### PostgreSQL won't start

```bash
# Check logs
docker compose logs postgres

# Common: port already in use
sudo lsof -i :5432
# Change POSTGRES_PORT in .env if needed
```

### NATS connection refused

```bash
# Check if running
docker compose ps nats

# Check logs
docker compose logs nats

# Verify JetStream enabled
curl -s http://localhost:8222/jsz
```

### Schema not found

```bash
# Re-run init script
docker compose exec postgres psql -U muscovite-harbor -d muscovite-harbor \
  -f /docker-entrypoint-initdb.d/01-schemas.sql
```

### Rebuild from scratch

```bash
docker compose down -v           # Remove containers + volumes
docker compose up -d             # Recreate everything
cd generated/database && sqitch deploy db:pg:muscovite-harbor
```
