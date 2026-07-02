-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:1d27e1824ead1b17
--  context: HarbourControl, entity: InvoiceLine, operation: select_by_id

SELECT id, vessel_id, service_type, amount, currency, issued_at FROM harbour_control.invoice_line WHERE id = $1