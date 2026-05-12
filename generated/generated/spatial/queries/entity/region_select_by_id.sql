-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:34a25c2085a50da6
--  context: spatial, entity: Region, operation: select_by_id

SELECT id, name, boundary, center FROM spatial.region WHERE id = $1