-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:b9e7212f18b83530
--  context: CargoDecomposition, entity: DeliveryUnit, operation: insert

INSERT INTO cargo_decomposition.delivery_unit (id, tracking_number, destination, carrier, dispatched_at) VALUES ($1, $2, $3, $4, $5) RETURNING id