-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:8b51839b8c1a3fcf
--  context: CargoOperations, entity: Crane, operation: insert

INSERT INTO cargo_operations.crane (id, id, name, crane_type, max_lift_kg, is_active) VALUES ($1, $2, $3, $4, $5, $6) RETURNING id