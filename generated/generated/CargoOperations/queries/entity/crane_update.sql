-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:213a0d2dd069cd05
--  context: CargoOperations, entity: Crane, operation: update

UPDATE cargo_operations.crane SET id = $2, name = $3, crane_type = $4, max_lift_kg = $5, is_active = $6 WHERE id = $1