#include <sinsp.h>
#define __STDC_FORMAT_MACROS
#include "sysdig.h"

unsigned long ScapEvGetTS(CScapEvent ev) {
	sinsp_evt* evt = (sinsp_evt*)ev;
	return evt->get_ts();
}
unsigned long ScapEvGetNum(CScapEvent ev) {
	sinsp_evt* evt = (sinsp_evt*)ev;
	return evt->get_num();
}
short ScapEvGetCPUID(CScapEvent ev) {
	sinsp_evt* evt = (sinsp_evt*)ev;
	return evt->get_cpuid();
}

unsigned short ScapEvGetType(CScapEvent ev) {
	sinsp_evt* evt = (sinsp_evt*)ev;
	return evt->get_type();
}
/* note this is actually an enum located in driver/ppm_events_public.h*/
unsigned short ScapEvGetFlags(CScapEvent ev) {
	sinsp_evt* evt = (sinsp_evt*)ev;
	return evt->get_info_flags();
}

unsigned short ScapEvGetDirection(CScapEvent ev) {
	sinsp_evt* evt = (sinsp_evt*)ev;
	return evt->get_direction();
}

unsigned short ScapEvGetCategory(CScapEvent ev) {
	sinsp_evt* evt = (sinsp_evt*)ev;
	return evt->get_info_category();
}

const char* ScapEvGetName(CScapEvent ev) {
	sinsp_evt* evt = (sinsp_evt*)ev;
	return evt->get_name();
}

long ScapEvGetTID(CScapEvent ev) {
	sinsp_evt* evt = (sinsp_evt*)ev;
	return evt->get_tid();
}

