# Skill: Infrastructure Management

Use this skill for starting, stopping, monitoring Docker services, and managing
the local development environment.

## Starting Services

```bash
# All services
docker compose up -d

# Individual
docker compose up -d postgres
docker compose up -d nats
```

## Stopping Services

```bash
# Stop all (preserves data)
docker compose down

# Stop and destroy data
docker compose down -v
```

## Health Checks

```bash
# Overview
docker compose ps

# PostgreSQL
docker compose exec postgres pg_isready

# NATS
curl -s http://localhost:8222/healthz

# NATS JetStream status
curl -s http://localhost:8222/jsz | jq .streams_count

# NATS connections
curl -s http://localhost:8222/connz | jq .num_connections
```

## Viewing Logs

```bash
# Follow all logs
docker compose logs -f

# Specific service, last 100 lines
docker compose logs --tail 100 -f postgres
docker compose logs --tail 100 -f nats
```

## Database Operations

```bash
# Connect to PostgreSQL
docker compose exec postgres psql -U $POSTGRES_USER -d $POSTGRES_DB

# List schemas
docker compose exec postgres psql -U $POSTGRES_USER -d $POSTGRES_DB \
  -c "SELECT schema_name FROM information_schema.schemata WHERE schema_name NOT LIKE 'pg_%' AND schema_name != 'information_schema';"

# List tables in a schema
docker compose exec postgres psql -U $POSTGRES_USER -d $POSTGRES_DB \
  -c "SELECT tablename FROM pg_tables WHERE schemaname = 'my_schema';"

# Run Sqitch migrations
cd generated/database && sqitch deploy db:pg:$POSTGRES_DB
cd generated/database && sqitch verify db:pg:$POSTGRES_DB
cd generated/database && sqitch status db:pg:$POSTGRES_DB
```

## Environment Setup

```bash
# Copy development profile
cp generated/deployment-profiles/dev.env.example .env

# Edit with your local settings
$EDITOR .env

# Verify variables are loaded
docker compose config
```

## Troubleshooting

### Port conflicts

```bash
# Check what's using a port
sudo lsof -i :5432   # PostgreSQL
sudo lsof -i :4222   # NATS

# Change ports in .env
echo "POSTGRES_PORT=5433" >> .env
echo "NATS_PORT=4223" >> .env
```

### Container won't start

```bash
# Check container status and exit code
docker compose ps -a

# Inspect failed container
docker compose logs <service>

# Force recreate
docker compose up -d --force-recreate <service>
```

### Database schema missing

```bash
# Re-run schema init
docker compose exec postgres psql -U $POSTGRES_USER -d $POSTGRES_DB \
  -f /docker-entrypoint-initdb.d/01-schemas.sql

# Or recreate from scratch
docker compose down -v
docker compose up -d
cd generated/database && sqitch deploy db:pg:$POSTGRES_DB
```

### Full reset

```bash
docker compose down -v              # Destroy everything
docker compose up -d                # Recreate
cd generated/database
sqitch deploy db:pg:$POSTGRES_DB    # Reapply migrations
```
