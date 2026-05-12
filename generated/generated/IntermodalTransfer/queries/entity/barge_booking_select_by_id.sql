-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:6a667decb95f3111
--  context: IntermodalTransfer, entity: BargeBooking, operation: select_by_id

SELECT id, id, barge_name, capacity_teu, departure_at, status FROM intermodal_transfer.barge_booking WHERE id = $1