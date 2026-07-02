-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:55586a020c796a0a
--  context: VesselTraffic, entity: TugBooking, operation: update

UPDATE vessel_traffic.tug_booking SET voyage_id = $2, tug_name = $3, bollard_pull_t = $4, is_confirmed = $5 WHERE id = $1