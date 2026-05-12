-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:edc30a5810e44299
--  context: HarbourControl, entity: SafetyZone, operation: select_by_id

SELECT id, id, zone_code, zone_name, security_level, max_hazmat_class, is_restricted FROM harbour_control.safety_zone WHERE id = $1