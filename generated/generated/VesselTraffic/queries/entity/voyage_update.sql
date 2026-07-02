-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:6538f132d0db3dac
--  context: VesselTraffic, entity: Voyage, operation: update

UPDATE vessel_traffic.voyage SET vessel_id = $2, berth_id = $3, voyage_number = $4, eta = $5, ata = $6, etd = $7, atd = $8, cargo_category = $9, status = $10 WHERE id = $1