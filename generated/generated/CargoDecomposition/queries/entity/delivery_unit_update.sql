-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:7215d62fb8a5f1c5
--  context: CargoDecomposition, entity: DeliveryUnit, operation: update

UPDATE cargo_decomposition.delivery_unit SET id = $2, tracking_number = $3, destination = $4, carrier = $5, dispatched_at = $6 WHERE id = $1