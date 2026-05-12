-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:39a8c211669ea273
--  context: VesselTraffic, entity: Voyage, operation: select_by_id

SELECT id, id, vessel_id, berth_id, voyage_number, eta, ata, etd, atd, cargo_category, status FROM vessel_traffic.voyage WHERE id = $1