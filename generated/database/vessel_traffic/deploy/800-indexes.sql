-- Deploy: vessel_traffic/indexes

BEGIN;

SET search_path TO vessel_traffic, public;

CREATE INDEX IF NOT EXISTS idx_voyages_voyage_id ON voyages (voyage_id);
CREATE INDEX IF NOT EXISTS idx_voyages_voyage_id ON voyages (voyage_id);
CREATE INDEX IF NOT EXISTS idx_pilot_assignments_pilot_assignment_id ON pilot_assignments (pilot_assignment_id);
CREATE INDEX IF NOT EXISTS idx_tug_bookings_tug_booking_id ON tug_bookings (tug_booking_id);
CREATE INDEX IF NOT EXISTS idx_tide_windows_tide_window_id ON tide_windows (tide_window_id);

COMMIT;
