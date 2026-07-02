-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:fead8481de44d9c8
--  context: CargoOperations, entity: LoadPlan, operation: insert

INSERT INTO cargo_operations.load_plan (id, voyage_id, created_at, status) VALUES ($1, $2, $3, $4) RETURNING id