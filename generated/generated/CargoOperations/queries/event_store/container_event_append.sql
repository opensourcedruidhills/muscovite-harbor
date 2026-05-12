-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:fb6b824a8fa2dd49
--  context: CargoOperations, aggregate: Container, operation: event_append

INSERT INTO cargo_operations.container_events (id, aggregate_id, event_type, payload, sequence_number, created_at) VALUES (uuidv7(), $1, $2, $3, $4, NOW()) RETURNING id, created_at