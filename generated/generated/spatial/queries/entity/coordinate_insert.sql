-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:3351a56190b7bc5c
--  context: spatial, entity: Coordinate, operation: insert

INSERT INTO spatial.coordinate (id, latitude, longitude, altitude, srid) VALUES ($1, $2, $3, $4, $5) RETURNING id