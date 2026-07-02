-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:e8cf674d18f36602
--  context: HarbourControl, entity: HazmatPermit, operation: update

UPDATE harbour_control.hazmat_permit SET permit_number = $2, vessel_id = $3, imo_class = $4, quantity_kg = $5, approved = $6, valid_from = $7, valid_until = $8 WHERE id = $1