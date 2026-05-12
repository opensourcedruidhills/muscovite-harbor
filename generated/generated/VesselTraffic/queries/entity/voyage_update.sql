-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:4312c8766d48ec32
--  context: VesselTraffic, entity: Voyage, operation: update

UPDATE vessel_traffic.voyage SET id = $2, vessel_id = $3, berth_id = $4, voyage_number = $5, eta = $6, ata = $7, etd = $8, atd = $9, cargo_category = $10, status = $11 WHERE id = $1