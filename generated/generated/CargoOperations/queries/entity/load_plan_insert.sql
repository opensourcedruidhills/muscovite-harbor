-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:26fc60c0097672ac
--  context: CargoOperations, entity: LoadPlan, operation: insert

INSERT INTO cargo_operations.load_plan (id, id, voyage_id, created_at, status) VALUES ($1, $2, $3, $4, $5) RETURNING id