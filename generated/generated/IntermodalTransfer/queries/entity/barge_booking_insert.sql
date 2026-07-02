-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:ea6aea9a0f340113
--  context: IntermodalTransfer, entity: BargeBooking, operation: insert

INSERT INTO intermodal_transfer.barge_booking (id, barge_name, capacity_teu, departure_at, status) VALUES ($1, $2, $3, $4, $5) RETURNING id