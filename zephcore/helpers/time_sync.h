/*
 * SPDX-License-Identifier: Apache-2.0
 * Track which source last set the RTC for UI display.
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

enum time_sync_source {
	TIME_SYNC_NONE = 0,
	TIME_SYNC_GPS,
	TIME_SYNC_APP,
	TIME_SYNC_WIFI,
	TIME_SYNC_CLI,
};

/** Record a successful RTC set from @p src. */
void time_sync_report(enum time_sync_source src);

/** Label for System > Info > Time. GPS authority wins while gps_has_time_sync(). */
const char *time_sync_display_label(void);

#ifdef __cplusplus
}
#endif
