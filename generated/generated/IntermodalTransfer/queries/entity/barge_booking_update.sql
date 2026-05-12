-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:e5437025713d0662
--  context: IntermodalTransfer, entity: BargeBooking, operation: update

UPDATE intermodal_transfer.barge_booking SET id = $2, barge_name = $3, capacity_teu = $4, departure_at = $5, status = $6 WHERE id = $1