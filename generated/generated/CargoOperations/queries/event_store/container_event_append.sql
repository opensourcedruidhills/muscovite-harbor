-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:01c362bae8c5ebff
--  context: CargoOperations, aggregate: Container, operation: event_append

WITH idempotency_guard AS (INSERT INTO cargo_operations.idempotency_keys (id, key, response, created_at, expires_at) VALUES (uuidv7(), $5, NULL, NOW(), NOW() + interval '1 day') ON CONFLICT (key) DO UPDATE SET response = EXCLUDED.response RETURNING key) INSERT INTO cargo_operations.container_events (id, aggregate_id, event_type, payload, sequence_number, created_at) SELECT uuidv7(), $1, $2, $3, $4, NOW() FROM idempotency_guard RETURNING id, created_at
