-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:58f227cecc9c269f
--  context: security, entity: User, operation: insert

INSERT INTO security.user (id, username, email, password_hash, is_active) VALUES ($1, $2, $3, $4, $5) RETURNING id