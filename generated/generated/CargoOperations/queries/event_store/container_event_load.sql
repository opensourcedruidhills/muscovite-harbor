-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:8fa88b3b585baf25
--  context: CargoOperations, aggregate: Container, operation: event_load

SELECT payload, created_at FROM cargo_operations.container_events WHERE aggregate_id = $1 AND sequence_number > $2 ORDER BY created_at, sequence_number
