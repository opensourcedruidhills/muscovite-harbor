-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:55a655a82219dc06
--  context: CargoOperations, entity: Container, operation: select_by_id

SELECT id, id, container_number, size_category, hazmat_class, voyage_id, yard_slot_id, status FROM cargo_operations.container WHERE id = $1