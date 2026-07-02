-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:4a74eec0fd06259d
--  context: VesselTraffic, entity: Berth, operation: select_all

SELECT id, code, name, max_loa_metres, max_draft_metres, max_beam_metres, has_crane_access, has_reefer_plugs, is_active FROM vessel_traffic.berth ORDER BY id