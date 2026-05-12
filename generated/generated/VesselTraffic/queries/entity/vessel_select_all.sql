-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:8a5e49f603a48a2d
--  context: VesselTraffic, entity: Vessel, operation: select_all

SELECT id, id, imo_number, mmsi, call_sign, name, vessel_type, flag_state, is_active FROM vessel_traffic.vessel ORDER BY id