-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:42c3a49b5818b610
--  context: CargoOperations, entity: YardSlot, operation: insert

INSERT INTO cargo_operations.yard_slot (id, code, max_weight_kg, max_tier, has_power, is_occupied) VALUES ($1, $2, $3, $4, $5, $6) RETURNING id