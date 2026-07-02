-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:37feabc4beda2417
--  context: CargoOperations, entity: Container, operation: select_by_id

SELECT id, container_number, size_category, hazmat_class, voyage_id, yard_slot_id, status FROM cargo_operations.container WHERE id = $1