-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:e1ea2d34785af38a
--  context: HarbourControl, entity: InvoiceLine, operation: select_by_id

SELECT id, id, vessel_id, service_type, amount, currency, issued_at FROM harbour_control.invoice_line WHERE id = $1