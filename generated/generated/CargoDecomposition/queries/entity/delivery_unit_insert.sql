-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:c6732d1e33b80c43
--  context: CargoDecomposition, entity: DeliveryUnit, operation: insert

INSERT INTO cargo_decomposition.delivery_unit (id, id, tracking_number, destination, carrier, dispatched_at) VALUES ($1, $2, $3, $4, $5, $6) RETURNING id