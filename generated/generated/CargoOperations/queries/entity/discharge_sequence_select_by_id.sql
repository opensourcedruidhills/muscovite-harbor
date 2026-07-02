-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:ab3dd9fbed86ab59
--  context: CargoOperations, entity: DischargeSequence, operation: select_by_id

SELECT id, load_plan_id, container_id, sequence_order, crane_id FROM cargo_operations.discharge_sequence WHERE id = $1