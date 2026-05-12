-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:8a6d121cfd9fbe34
--  context: HarbourControl, entity: SafetyZone, operation: update

UPDATE harbour_control.safety_zone SET id = $2, zone_code = $3, zone_name = $4, security_level = $5, max_hazmat_class = $6, is_restricted = $7 WHERE id = $1