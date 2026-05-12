-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:07e00b3ae62f873f
--  context: security, entity: AuditLogEntry, operation: update

UPDATE security.audit_log_entry SET timestamp = $2, actor = $3, action = $4, resource = $5, details = $6 WHERE id = $1