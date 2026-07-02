-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:bdccf2cdff889c08
--  context: IntermodalTransfer, entity: TruckVisit, operation: select_by_id

SELECT id, truck_plate, carrier_name, slot_id, arrived_at, departed_at FROM intermodal_transfer.truck_visit WHERE id = $1