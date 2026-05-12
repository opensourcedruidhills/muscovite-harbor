-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:955410cd586b108d
--  context: security, entity: AuditLogEntry, operation: insert

INSERT INTO security.audit_log_entry (id, timestamp, actor, action, resource, details) VALUES ($1, $2, $3, $4, $5, $6) RETURNING id