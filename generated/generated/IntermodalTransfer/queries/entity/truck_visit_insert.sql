-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:a3e02cf5db009f8f
--  context: IntermodalTransfer, entity: TruckVisit, operation: insert

INSERT INTO intermodal_transfer.truck_visit (id, id, truck_plate, carrier_name, slot_id, arrived_at, departed_at) VALUES ($1, $2, $3, $4, $5, $6, $7) RETURNING id