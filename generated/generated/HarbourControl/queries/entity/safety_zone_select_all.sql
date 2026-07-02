-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:5a123381c3208e44
--  context: HarbourControl, entity: SafetyZone, operation: select_all

SELECT id, zone_code, zone_name, security_level, max_hazmat_class, is_restricted FROM harbour_control.safety_zone ORDER BY id