-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:3d43a7268d985ff4
--  context: CargoOperations, entity: Container, operation: update

UPDATE cargo_operations.container SET id = $2, container_number = $3, size_category = $4, hazmat_class = $5, voyage_id = $6, yard_slot_id = $7, status = $8 WHERE id = $1