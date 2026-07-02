-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:f938f8bc833b40ee
--  context: IntermodalTransfer, entity: BargeBooking, operation: select_by_id

SELECT id, barge_name, capacity_teu, departure_at, status FROM intermodal_transfer.barge_booking WHERE id = $1