-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:0b23d0fd8dda75f0
--  context: VesselTraffic, entity: Berth, operation: select_by_id

SELECT id, id, code, name, max_loa_metres, max_draft_metres, max_beam_metres, has_crane_access, has_reefer_plugs, is_active FROM vessel_traffic.berth WHERE id = $1