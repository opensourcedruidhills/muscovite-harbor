-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:74c7994fb39545d8
--  context: VesselTraffic, entity: TugBooking, operation: select_all

SELECT id, voyage_id, tug_name, bollard_pull_t, is_confirmed FROM vessel_traffic.tug_booking ORDER BY id