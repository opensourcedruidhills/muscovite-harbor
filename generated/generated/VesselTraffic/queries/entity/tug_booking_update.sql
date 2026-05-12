-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:64d6384210119efa
--  context: VesselTraffic, entity: TugBooking, operation: update

UPDATE vessel_traffic.tug_booking SET id = $2, voyage_id = $3, tug_name = $4, bollard_pull_t = $5, is_confirmed = $6 WHERE id = $1