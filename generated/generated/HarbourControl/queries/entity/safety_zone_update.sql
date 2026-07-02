-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:814da878927b9201
--  context: HarbourControl, entity: SafetyZone, operation: update

UPDATE harbour_control.safety_zone SET zone_code = $2, zone_name = $3, security_level = $4, max_hazmat_class = $5, is_restricted = $6 WHERE id = $1