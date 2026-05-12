-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:726ed59f11bbf93b
--  context: spatial, entity: Coordinate, operation: select_by_id

SELECT id, latitude, longitude, altitude, srid FROM spatial.coordinate WHERE id = $1