-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:de57a58fe7ff5275
--  context: IntermodalTransfer, entity: TruckVisit, operation: select_by_id

SELECT id, id, truck_plate, carrier_name, slot_id, arrived_at, departed_at FROM intermodal_transfer.truck_visit WHERE id = $1