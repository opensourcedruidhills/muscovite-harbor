-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:97cf75e780298968
--  context: IntermodalTransfer, entity: BargeBooking, operation: insert

INSERT INTO intermodal_transfer.barge_booking (id, id, barge_name, capacity_teu, departure_at, status) VALUES ($1, $2, $3, $4, $5, $6) RETURNING id