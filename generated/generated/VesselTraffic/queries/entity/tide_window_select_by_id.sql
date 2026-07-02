-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:d4bf8fe6d805f7cc
--  context: VesselTraffic, entity: TideWindow, operation: select_by_id

SELECT id, berth_id, tide_height_metres, available_draft FROM vessel_traffic.tide_window WHERE id = $1