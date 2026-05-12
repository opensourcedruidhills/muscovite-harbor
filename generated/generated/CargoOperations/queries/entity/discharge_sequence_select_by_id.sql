-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:d9ca642b21416852
--  context: CargoOperations, entity: DischargeSequence, operation: select_by_id

SELECT id, id, load_plan_id, container_id, sequence_order, crane_id FROM cargo_operations.discharge_sequence WHERE id = $1