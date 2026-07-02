-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:19e5815555aafceb
--  context: CargoDecomposition, entity: DeliveryUnit, operation: update

UPDATE cargo_decomposition.delivery_unit SET tracking_number = $2, destination = $3, carrier = $4, dispatched_at = $5 WHERE id = $1