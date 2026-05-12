-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:d74069c0565e3f39
--  context: HarbourControl, entity: InvoiceLine, operation: update

UPDATE harbour_control.invoice_line SET id = $2, vessel_id = $3, service_type = $4, amount = $5, currency = $6, issued_at = $7 WHERE id = $1