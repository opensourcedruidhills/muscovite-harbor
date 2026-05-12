-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:8808a59b3ca17cc6
--  context: spatial, entity: SpatialProjection, operation: insert

INSERT INTO spatial.spatial_projection (id, name, srid, definition) VALUES ($1, $2, $3, $4) RETURNING id