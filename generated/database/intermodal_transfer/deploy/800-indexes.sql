-- Deploy: intermodal_transfer/indexes

BEGIN;

SET search_path TO intermodal_transfer, public;

CREATE INDEX IF NOT EXISTS idx_truck_visits_truck_visit_id ON truck_visits (truck_visit_id);

COMMIT;
