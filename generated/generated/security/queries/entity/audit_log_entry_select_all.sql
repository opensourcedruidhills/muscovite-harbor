-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:586f9744282aa826
--  context: security, entity: AuditLogEntry, operation: select_all

SELECT id, timestamp, actor, action, resource, details FROM security.audit_log_entry ORDER BY id