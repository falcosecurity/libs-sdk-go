/*
Copyright (C) 2022 The Falco Authors.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#include <sinsp.h>
#define __STDC_FORMAT_MACROS
#include "libs.h"

unsigned long ScapEvGetTS(CScapEvent ev) {
  sinsp_evt *evt = (sinsp_evt *)ev;
  return evt->get_ts();
}
unsigned long ScapEvGetNum(CScapEvent ev) {
  sinsp_evt *evt = (sinsp_evt *)ev;
  return evt->get_num();
}
short ScapEvGetCPUID(CScapEvent ev) {
  sinsp_evt *evt = (sinsp_evt *)ev;
  return evt->get_cpuid();
}

unsigned short ScapEvGetType(CScapEvent ev) {
  sinsp_evt *evt = (sinsp_evt *)ev;
  return evt->get_type();
}
/* note this is actually an enum located in driver/ppm_events_public.h*/
unsigned short ScapEvGetFlags(CScapEvent ev) {
  sinsp_evt *evt = (sinsp_evt *)ev;
  return evt->get_info_flags();
}

unsigned short ScapEvGetDirection(CScapEvent ev) {
  sinsp_evt *evt = (sinsp_evt *)ev;
  return evt->get_direction();
}

unsigned short ScapEvGetCategory(CScapEvent ev) {
  sinsp_evt *evt = (sinsp_evt *)ev;
  return evt->get_info_category();
}

const char *ScapEvGetName(CScapEvent ev) {
  sinsp_evt *evt = (sinsp_evt *)ev;
  return evt->get_name();
}

long ScapEvGetTID(CScapEvent ev) {
  sinsp_evt *evt = (sinsp_evt *)ev;
  return evt->get_tid();
}

CScapThreadInfo ScapEvGetThreadInfo(CScapEvent ev, int queryOS) {
  sinsp_evt *evt = (sinsp_evt *)ev;
  return evt->get_thread_info((queryOS == 1));
}
