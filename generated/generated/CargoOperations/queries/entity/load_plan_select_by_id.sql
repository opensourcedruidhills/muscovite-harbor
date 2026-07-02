-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:28e0487708a7611e
--  context: CargoOperations, entity: LoadPlan, operation: select_by_id

SELECT id, voyage_id, created_at, status FROM cargo_operations.load_plan WHERE id = $1