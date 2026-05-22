/*
 * SPDX-License-Identifier: Apache-2.0
 */

#include "time_sync.h"
#include <adapters/gps/ZephyrGPSManager.h>
#include <stdio.h>

static enum time_sync_source s_last = TIME_SYNC_NONE;

static const char *source_short_name(enum time_sync_source src)
{
	switch (src) {
	case TIME_SYNC_GPS:  return "GPS";
	case TIME_SYNC_APP:  return "App";
	case TIME_SYNC_WIFI: return "WiFi";
	case TIME_SYNC_CLI:  return "CLI";
	default:             return NULL;
	}
}

void time_sync_report(enum time_sync_source src)
{
	s_last = src;
}

const char *time_sync_display_label(void)
{
	if (gps_has_time_sync()) {
		return "GPS";
	}

	const char *src = source_short_name(s_last);
	if (!src) {
		return "None";
	}

	if (s_last != TIME_SYNC_GPS) {
		return src;
	}

	static char label[20];
	snprintf(label, sizeof(label), "Local (%s)", src);
	return label;
}
