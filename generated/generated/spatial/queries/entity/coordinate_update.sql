-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:bc136b776d2665e5
--  context: spatial, entity: Coordinate, operation: update

UPDATE spatial.coordinate SET latitude = $2, longitude = $3, altitude = $4, srid = $5 WHERE id = $1