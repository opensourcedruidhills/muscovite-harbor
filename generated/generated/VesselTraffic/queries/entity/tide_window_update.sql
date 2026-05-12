-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:933e5773c7cf2131
--  context: VesselTraffic, entity: TideWindow, operation: update

UPDATE vessel_traffic.tide_window SET id = $2, berth_id = $3, tide_height_metres = $4, available_draft = $5 WHERE id = $1