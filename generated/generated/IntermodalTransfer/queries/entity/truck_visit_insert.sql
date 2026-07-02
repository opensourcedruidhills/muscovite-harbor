-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:92d06673dde65b65
--  context: IntermodalTransfer, entity: TruckVisit, operation: insert

INSERT INTO intermodal_transfer.truck_visit (id, truck_plate, carrier_name, slot_id, arrived_at, departed_at) VALUES ($1, $2, $3, $4, $5, $6) RETURNING id