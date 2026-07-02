-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:c4fb00dba4f4f874
--  context: VesselTraffic, entity: TideWindow, operation: select_all

SELECT id, berth_id, tide_height_metres, available_draft FROM vessel_traffic.tide_window ORDER BY id