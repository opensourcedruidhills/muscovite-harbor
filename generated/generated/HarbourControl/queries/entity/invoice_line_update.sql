-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:352c3a692cef79dc
--  context: HarbourControl, entity: InvoiceLine, operation: update

UPDATE harbour_control.invoice_line SET vessel_id = $2, service_type = $3, amount = $4, currency = $5, issued_at = $6 WHERE id = $1