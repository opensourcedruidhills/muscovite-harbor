-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:2532d6bc7522f162
--  context: security, entity: AccessControlEntry, operation: insert

INSERT INTO security.access_control_entry (id, principal, resource, permission, effect) VALUES ($1, $2, $3, $4, $5) RETURNING id