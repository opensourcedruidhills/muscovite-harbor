-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:2653d76215922ef1
--  context: VesselTraffic, entity: Berth, operation: update

UPDATE vessel_traffic.berth SET code = $2, name = $3, max_loa_metres = $4, max_draft_metres = $5, max_beam_metres = $6, has_crane_access = $7, has_reefer_plugs = $8, is_active = $9 WHERE id = $1