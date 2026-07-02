-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:f1ee850821363789
--  context: CargoOperations, entity: Crane, operation: select_by_id

SELECT id, name, crane_type, max_lift_kg, is_active FROM cargo_operations.crane WHERE id = $1