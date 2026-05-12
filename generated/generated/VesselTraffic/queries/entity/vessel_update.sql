-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:c6019c1977dfcfed
--  context: VesselTraffic, entity: Vessel, operation: update

UPDATE vessel_traffic.vessel SET id = $2, imo_number = $3, mmsi = $4, call_sign = $5, name = $6, vessel_type = $7, flag_state = $8, is_active = $9 WHERE id = $1