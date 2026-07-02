-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:35d8faa2aa5a91d3
--  context: CargoOperations, entity: Crane, operation: update

UPDATE cargo_operations.crane SET name = $2, crane_type = $3, max_lift_kg = $4, is_active = $5 WHERE id = $1