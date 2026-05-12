-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:d856d1e1de344c36
--  context: CargoDecomposition, entity: DeliveryUnit, operation: select_by_id

SELECT id, id, tracking_number, destination, carrier, dispatched_at FROM cargo_decomposition.delivery_unit WHERE id = $1