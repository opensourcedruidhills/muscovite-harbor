-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:e58ab6f11cc72e81
--  context: CargoDecomposition, entity: DeliveryUnit, operation: select_by_id

SELECT id, tracking_number, destination, carrier, dispatched_at FROM cargo_decomposition.delivery_unit WHERE id = $1