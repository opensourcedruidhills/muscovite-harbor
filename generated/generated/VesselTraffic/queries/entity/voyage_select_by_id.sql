-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:791507eb22d54dfc
--  context: VesselTraffic, entity: Voyage, operation: select_by_id

SELECT id, vessel_id, berth_id, voyage_number, eta, ata, etd, atd, cargo_category, status FROM vessel_traffic.voyage WHERE id = $1