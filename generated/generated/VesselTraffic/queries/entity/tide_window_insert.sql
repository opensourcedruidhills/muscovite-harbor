-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:f894c387a20fce62
--  context: VesselTraffic, entity: TideWindow, operation: insert

INSERT INTO vessel_traffic.tide_window (id, id, berth_id, tide_height_metres, available_draft) VALUES ($1, $2, $3, $4, $5) RETURNING id