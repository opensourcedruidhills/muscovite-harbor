-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:2d213e0e55635c54
--  context: VesselTraffic, entity: Vessel, operation: insert

INSERT INTO vessel_traffic.vessel (id, id, imo_number, mmsi, call_sign, name, vessel_type, flag_state, is_active) VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9) RETURNING id