-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:6aeb8abaa4d6353e
--  context: IntermodalTransfer, entity: TruckVisit, operation: update

UPDATE intermodal_transfer.truck_visit SET id = $2, truck_plate = $3, carrier_name = $4, slot_id = $5, arrived_at = $6, departed_at = $7 WHERE id = $1