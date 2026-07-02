-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:9b34a50c94e46710
--  context: VesselTraffic, entity: TideWindow, operation: update

UPDATE vessel_traffic.tide_window SET berth_id = $2, tide_height_metres = $3, available_draft = $4 WHERE id = $1