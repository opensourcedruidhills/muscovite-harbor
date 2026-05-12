-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:b73114290a002693
--  context: security, entity: AccessControlEntry, operation: update

UPDATE security.access_control_entry SET principal = $2, resource = $3, permission = $4, effect = $5 WHERE id = $1