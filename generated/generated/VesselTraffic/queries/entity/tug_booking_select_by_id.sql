-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:d4539f3382b7dae7
--  context: VesselTraffic, entity: TugBooking, operation: select_by_id

SELECT id, id, voyage_id, tug_name, bollard_pull_t, is_confirmed FROM vessel_traffic.tug_booking WHERE id = $1