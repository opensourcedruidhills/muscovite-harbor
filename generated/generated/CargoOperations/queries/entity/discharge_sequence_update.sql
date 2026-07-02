-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:c760dbb1c490096d
--  context: CargoOperations, entity: DischargeSequence, operation: update

UPDATE cargo_operations.discharge_sequence SET load_plan_id = $2, container_id = $3, sequence_order = $4, crane_id = $5 WHERE id = $1