-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:32701ad6779f7234
--  context: VesselTraffic, entity: Vessel, operation: select_all

SELECT id, imo_number, mmsi, call_sign, name, vessel_type, flag_state, is_active FROM vessel_traffic.vessel ORDER BY id