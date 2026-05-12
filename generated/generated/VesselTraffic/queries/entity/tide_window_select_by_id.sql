-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:46a2ac175de7d8af
--  context: VesselTraffic, entity: TideWindow, operation: select_by_id

SELECT id, id, berth_id, tide_height_metres, available_draft FROM vessel_traffic.tide_window WHERE id = $1