-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:ae96c658717f991f
--  context: VesselTraffic, entity: Voyage, operation: insert

INSERT INTO vessel_traffic.voyage (id, id, vessel_id, berth_id, voyage_number, eta, ata, etd, atd, cargo_category, status) VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11) RETURNING id