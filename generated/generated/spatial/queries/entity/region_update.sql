-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:e5d362017005ea62
--  context: spatial, entity: Region, operation: update

UPDATE spatial.region SET name = $2, boundary = $3, center = $4 WHERE id = $1