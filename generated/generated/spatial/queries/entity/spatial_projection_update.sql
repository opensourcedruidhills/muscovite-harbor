-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:5714663908371a7c
--  context: spatial, entity: SpatialProjection, operation: update

UPDATE spatial.spatial_projection SET name = $2, srid = $3, definition = $4 WHERE id = $1