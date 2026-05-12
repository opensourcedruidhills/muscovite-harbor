-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:8c2421d5e4f18101
--  context: CargoOperations, entity: LoadPlan, operation: select_by_id

SELECT id, id, voyage_id, created_at, status FROM cargo_operations.load_plan WHERE id = $1