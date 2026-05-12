-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:c4b30e15738ad78b
--  context: CargoOperations, entity: DischargeSequence, operation: insert

INSERT INTO cargo_operations.discharge_sequence (id, id, load_plan_id, container_id, sequence_order, crane_id) VALUES ($1, $2, $3, $4, $5, $6) RETURNING id