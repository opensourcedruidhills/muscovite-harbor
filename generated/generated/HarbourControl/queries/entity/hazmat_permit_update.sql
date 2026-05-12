-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:dba61a857946fd01
--  context: HarbourControl, entity: HazmatPermit, operation: update

UPDATE harbour_control.hazmat_permit SET id = $2, permit_number = $3, vessel_id = $4, imo_class = $5, quantity_kg = $6, approved = $7, valid_from = $8, valid_until = $9 WHERE id = $1