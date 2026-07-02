-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:7c4ab5c28cca3538
--  context: CargoOperations, entity: DischargeSequence, operation: insert

INSERT INTO cargo_operations.discharge_sequence (id, load_plan_id, container_id, sequence_order, crane_id) VALUES ($1, $2, $3, $4, $5) RETURNING id