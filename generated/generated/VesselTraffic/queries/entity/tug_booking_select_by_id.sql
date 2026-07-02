-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:92ae883976073610
--  context: VesselTraffic, entity: TugBooking, operation: select_by_id

SELECT id, voyage_id, tug_name, bollard_pull_t, is_confirmed FROM vessel_traffic.tug_booking WHERE id = $1