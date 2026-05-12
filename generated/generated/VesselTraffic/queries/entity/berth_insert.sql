-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:9f174be4db14798a
--  context: VesselTraffic, entity: Berth, operation: insert

INSERT INTO vessel_traffic.berth (id, id, code, name, max_loa_metres, max_draft_metres, max_beam_metres, has_crane_access, has_reefer_plugs, is_active) VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10) RETURNING id