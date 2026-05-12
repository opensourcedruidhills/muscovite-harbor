-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:59b8602cde0b9acc
--  context: CargoOperations, entity: Container, operation: insert

INSERT INTO cargo_operations.container (id, id, container_number, size_category, hazmat_class, voyage_id, yard_slot_id, status) VALUES ($1, $2, $3, $4, $5, $6, $7, $8) RETURNING id