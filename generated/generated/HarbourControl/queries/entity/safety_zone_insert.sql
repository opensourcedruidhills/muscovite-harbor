-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:a47958e3d356483b
--  context: HarbourControl, entity: SafetyZone, operation: insert

INSERT INTO harbour_control.safety_zone (id, id, zone_code, zone_name, security_level, max_hazmat_class, is_restricted) VALUES ($1, $2, $3, $4, $5, $6, $7) RETURNING id