-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:87bac41bcfd33370
--  context: spatial, entity: Region, operation: insert

INSERT INTO spatial.region (id, name, boundary, center) VALUES ($1, $2, $3, $4) RETURNING id