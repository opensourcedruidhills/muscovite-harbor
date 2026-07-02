-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:6158334d8fe78f00
--  context: VesselTraffic, entity: Voyage, operation: insert

INSERT INTO vessel_traffic.voyage (id, vessel_id, berth_id, voyage_number, eta, ata, etd, atd, cargo_category, status) VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10) RETURNING id