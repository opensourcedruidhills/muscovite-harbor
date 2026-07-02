-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:5ad3fe65ee0a666e
--  context: IntermodalTransfer, entity: BargeBooking, operation: update

UPDATE intermodal_transfer.barge_booking SET barge_name = $2, capacity_teu = $3, departure_at = $4, status = $5 WHERE id = $1