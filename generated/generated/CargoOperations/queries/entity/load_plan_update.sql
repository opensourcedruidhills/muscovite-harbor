-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:9da87556a9b4d21a
--  context: CargoOperations, entity: LoadPlan, operation: update

UPDATE cargo_operations.load_plan SET voyage_id = $2, created_at = $3, status = $4 WHERE id = $1