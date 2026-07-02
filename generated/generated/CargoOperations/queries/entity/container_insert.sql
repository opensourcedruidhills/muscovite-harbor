-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:d0d7a3b13e239981
--  context: CargoOperations, entity: Container, operation: insert

INSERT INTO cargo_operations.container (id, container_number, size_category, hazmat_class, voyage_id, yard_slot_id, status) VALUES ($1, $2, $3, $4, $5, $6, $7) RETURNING id