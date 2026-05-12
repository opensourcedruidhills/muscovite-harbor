-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:8ba91c7c4791d761
--  context: CargoOperations, aggregate: Container, operation: event_load

SELECT payload FROM cargo_operations.container_events WHERE aggregate_id = $1 AND sequence_number > $2 ORDER BY sequence_number