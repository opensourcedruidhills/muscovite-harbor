// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <doctest/doctest.h>
#include <string>

// Edge-case tests for constrained fields in VesselTraffic

SCENARIO("Edge case: Vessel.name @NOT_EMPTY=") {
    GIVEN("field name with @NOT_EMPTY = ") {
        WHEN("the constraint is evaluated") {
            THEN("it should enforce the constraint") {
                // CHECK(validate_not_empty(value, ));
            }
        }
    }
}

SCENARIO("Edge case: Berth.name @NOT_EMPTY=") {
    GIVEN("field name with @NOT_EMPTY = ") {
        WHEN("the constraint is evaluated") {
            THEN("it should enforce the constraint") {
                // CHECK(validate_not_empty(value, ));
            }
        }
    }
}

SCENARIO("Edge case: Berth.max_loa_metres @MIN=10") {
    GIVEN("field max_loa_metres with @MIN = 10") {
        WHEN("the constraint is evaluated") {
            THEN("it should enforce the constraint") {
                // CHECK(validate_min(value, 10));
            }
        }
    }
}

SCENARIO("Edge case: Berth.max_loa_metres @MAX=500") {
    GIVEN("field max_loa_metres with @MAX = 500") {
        WHEN("the constraint is evaluated") {
            THEN("it should enforce the constraint") {
                // CHECK(validate_max(value, 500));
            }
        }
    }
}

SCENARIO("Edge case: Berth.max_draft_metres @MIN=1") {
    GIVEN("field max_draft_metres with @MIN = 1") {
        WHEN("the constraint is evaluated") {
            THEN("it should enforce the constraint") {
                // CHECK(validate_min(value, 1));
            }
        }
    }
}

SCENARIO("Edge case: Berth.max_draft_metres @MAX=25") {
    GIVEN("field max_draft_metres with @MAX = 25") {
        WHEN("the constraint is evaluated") {
            THEN("it should enforce the constraint") {
                // CHECK(validate_max(value, 25));
            }
        }
    }
}

SCENARIO("Edge case: Berth.max_beam_metres @MIN=5") {
    GIVEN("field max_beam_metres with @MIN = 5") {
        WHEN("the constraint is evaluated") {
            THEN("it should enforce the constraint") {
                // CHECK(validate_min(value, 5));
            }
        }
    }
}

SCENARIO("Edge case: Berth.max_beam_metres @MAX=80") {
    GIVEN("field max_beam_metres with @MAX = 80") {
        WHEN("the constraint is evaluated") {
            THEN("it should enforce the constraint") {
                // CHECK(validate_max(value, 80));
            }
        }
    }
}

SCENARIO("Edge case: Voyage.voyage_number @NOT_EMPTY=") {
    GIVEN("field voyage_number with @NOT_EMPTY = ") {
        WHEN("the constraint is evaluated") {
            THEN("it should enforce the constraint") {
                // CHECK(validate_not_empty(value, ));
            }
        }
    }
}

SCENARIO("Edge case: PilotAssignment.pilot_name @NOT_EMPTY=") {
    GIVEN("field pilot_name with @NOT_EMPTY = ") {
        WHEN("the constraint is evaluated") {
            THEN("it should enforce the constraint") {
                // CHECK(validate_not_empty(value, ));
            }
        }
    }
}

SCENARIO("Edge case: TugBooking.tug_name @NOT_EMPTY=") {
    GIVEN("field tug_name with @NOT_EMPTY = ") {
        WHEN("the constraint is evaluated") {
            THEN("it should enforce the constraint") {
                // CHECK(validate_not_empty(value, ));
            }
        }
    }
}

SCENARIO("Edge case: TugBooking.bollard_pull_t @MIN=5") {
    GIVEN("field bollard_pull_t with @MIN = 5") {
        WHEN("the constraint is evaluated") {
            THEN("it should enforce the constraint") {
                // CHECK(validate_min(value, 5));
            }
        }
    }
}

SCENARIO("Edge case: TugBooking.bollard_pull_t @MAX=200") {
    GIVEN("field bollard_pull_t with @MAX = 200") {
        WHEN("the constraint is evaluated") {
            THEN("it should enforce the constraint") {
                // CHECK(validate_max(value, 200));
            }
        }
    }
}

SCENARIO("Edge case: TideWindow.tide_height_metres @MIN=-2") {
    GIVEN("field tide_height_metres with @MIN = -2") {
        WHEN("the constraint is evaluated") {
            THEN("it should enforce the constraint") {
                // CHECK(validate_min(value, -2));
            }
        }
    }
}

SCENARIO("Edge case: TideWindow.tide_height_metres @MAX=15") {
    GIVEN("field tide_height_metres with @MAX = 15") {
        WHEN("the constraint is evaluated") {
            THEN("it should enforce the constraint") {
                // CHECK(validate_max(value, 15));
            }
        }
    }
}

SCENARIO("Edge case: TideWindow.available_draft @MIN=0") {
    GIVEN("field available_draft with @MIN = 0") {
        WHEN("the constraint is evaluated") {
            THEN("it should enforce the constraint") {
                // CHECK(validate_min(value, 0));
            }
        }
    }
}
