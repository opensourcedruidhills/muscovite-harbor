-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:b83d9a3aa53648b6
--  context: security, entity: AuditLogEntry, operation: select_by_id

SELECT id, timestamp, actor, action, resource, details FROM security.audit_log_entry WHERE id = $1