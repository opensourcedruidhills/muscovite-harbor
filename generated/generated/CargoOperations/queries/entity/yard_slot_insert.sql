-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:879b28f85811f512
--  context: CargoOperations, entity: YardSlot, operation: insert

INSERT INTO cargo_operations.yard_slot (id, id, code, max_weight_kg, max_tier, has_power, is_occupied) VALUES ($1, $2, $3, $4, $5, $6, $7) RETURNING id