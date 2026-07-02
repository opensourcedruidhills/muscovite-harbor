-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:86584b2db556041e
--  context: VesselTraffic, entity: TideWindow, operation: insert

INSERT INTO vessel_traffic.tide_window (id, berth_id, tide_height_metres, available_draft) VALUES ($1, $2, $3, $4) RETURNING id