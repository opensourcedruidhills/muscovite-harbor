-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:98021e5b38c9eaa5
--  context: VesselTraffic, entity: TideWindow, operation: delete

UPDATE vessel_traffic.tide_window SET valid_to = NOW() WHERE id = $1 AND valid_to = 'infinity'