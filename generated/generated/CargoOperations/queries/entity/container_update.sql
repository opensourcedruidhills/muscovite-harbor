-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:75203ec89c96ba30
--  context: CargoOperations, entity: Container, operation: update

UPDATE cargo_operations.container SET container_number = $2, size_category = $3, hazmat_class = $4, voyage_id = $5, yard_slot_id = $6, status = $7 WHERE id = $1