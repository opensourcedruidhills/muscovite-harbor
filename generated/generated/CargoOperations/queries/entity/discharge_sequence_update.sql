-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:74491099ca4e5cd7
--  context: CargoOperations, entity: DischargeSequence, operation: update

UPDATE cargo_operations.discharge_sequence SET id = $2, load_plan_id = $3, container_id = $4, sequence_order = $5, crane_id = $6 WHERE id = $1