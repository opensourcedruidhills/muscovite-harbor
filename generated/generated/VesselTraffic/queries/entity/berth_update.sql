-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:bcfb00496b1e5bb0
--  context: VesselTraffic, entity: Berth, operation: update

UPDATE vessel_traffic.berth SET id = $2, code = $3, name = $4, max_loa_metres = $5, max_draft_metres = $6, max_beam_metres = $7, has_crane_access = $8, has_reefer_plugs = $9, is_active = $10 WHERE id = $1