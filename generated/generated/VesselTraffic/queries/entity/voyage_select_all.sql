-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:50bfe30da166f884
--  context: VesselTraffic, entity: Voyage, operation: select_all

SELECT id, vessel_id, berth_id, voyage_number, eta, ata, etd, atd, cargo_category, status FROM vessel_traffic.voyage ORDER BY id