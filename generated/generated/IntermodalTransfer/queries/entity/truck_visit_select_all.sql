-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:a5d25ebf16e31f30
--  context: IntermodalTransfer, entity: TruckVisit, operation: select_all

SELECT id, truck_plate, carrier_name, slot_id, arrived_at, departed_at FROM intermodal_transfer.truck_visit ORDER BY id