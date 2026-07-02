-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:1738fee07056f3a5
--  context: IntermodalTransfer, entity: TruckVisit, operation: update

UPDATE intermodal_transfer.truck_visit SET truck_plate = $2, carrier_name = $3, slot_id = $4, arrived_at = $5, departed_at = $6 WHERE id = $1