-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:04fdbcae0bb571d7
--  context: CargoOperations, entity: Container, operation: select_all

SELECT id, container_number, size_category, hazmat_class, voyage_id, yard_slot_id, status FROM cargo_operations.container ORDER BY id