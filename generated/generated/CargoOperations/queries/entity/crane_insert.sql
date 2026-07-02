-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:7dd742d803abe798
--  context: CargoOperations, entity: Crane, operation: insert

INSERT INTO cargo_operations.crane (id, name, crane_type, max_lift_kg, is_active) VALUES ($1, $2, $3, $4, $5) RETURNING id