-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:157f0c13195ca4e0
--  context: CargoOperations, entity: Crane, operation: select_by_id

SELECT id, id, name, crane_type, max_lift_kg, is_active FROM cargo_operations.crane WHERE id = $1