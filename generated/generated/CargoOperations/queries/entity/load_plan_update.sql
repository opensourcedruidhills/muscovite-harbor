-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:3663d46dc4081c13
--  context: CargoOperations, entity: LoadPlan, operation: update

UPDATE cargo_operations.load_plan SET id = $2, voyage_id = $3, created_at = $4, status = $5 WHERE id = $1