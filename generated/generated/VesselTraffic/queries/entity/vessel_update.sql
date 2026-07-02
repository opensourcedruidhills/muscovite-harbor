-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:20ff8ec2173be5a6
--  context: VesselTraffic, entity: Vessel, operation: update

UPDATE vessel_traffic.vessel SET imo_number = $2, mmsi = $3, call_sign = $4, name = $5, vessel_type = $6, flag_state = $7, is_active = $8 WHERE id = $1