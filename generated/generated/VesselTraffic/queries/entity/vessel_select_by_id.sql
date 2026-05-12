-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:8adb4dd94570be45
--  context: VesselTraffic, entity: Vessel, operation: select_by_id

SELECT id, id, imo_number, mmsi, call_sign, name, vessel_type, flag_state, is_active FROM vessel_traffic.vessel WHERE id = $1