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

const char *ScapTInfoGetProc(CScapThreadInfo ti) {
  sinsp_threadinfo *threadinfo = (sinsp_threadinfo *)ti;
  return threadinfo->get_comm().c_str();
}

const char *ScapTInfoGetExe(CScapThreadInfo ti) {
  sinsp_threadinfo *threadinfo = (sinsp_threadinfo *)ti;
  return threadinfo->get_exe().c_str();
}

const char *ScapTInfoGetCWD(CScapThreadInfo ti) {
  sinsp_threadinfo *threadinfo = (sinsp_threadinfo *)ti;
  return threadinfo->get_cwd().c_str();
}

CScapThreadInfo ScapTInfoGetMainThread(CScapThreadInfo ti) {
  sinsp_threadinfo *threadinfo = (sinsp_threadinfo *)ti;
  return threadinfo->get_main_thread();
}

CScapThreadInfo ScapTInfoGetParentThread(CScapThreadInfo ti) {
  sinsp_threadinfo *threadinfo = (sinsp_threadinfo *)ti;
  return threadinfo->get_parent_thread();
}

long ScapTInfoGetTid(CScapThreadInfo ti) {
  sinsp_threadinfo *threadinfo = (sinsp_threadinfo *)ti;
  return threadinfo->m_tid;
}

long ScapTInfoGetPid(CScapThreadInfo ti) {
  sinsp_threadinfo *threadinfo = (sinsp_threadinfo *)ti;
  return threadinfo->m_pid;
}

long ScapTInfoGetPPid(CScapThreadInfo ti) {
  sinsp_threadinfo *threadinfo = (sinsp_threadinfo *)ti;
  return threadinfo->m_ptid;
}

long ScapTInfoGetVTid(CScapThreadInfo ti) {
  sinsp_threadinfo *threadinfo = (sinsp_threadinfo *)ti;
  return threadinfo->m_vtid;
}

long ScapTInfoGetVPid(CScapThreadInfo ti) {
  sinsp_threadinfo *threadinfo = (sinsp_threadinfo *)ti;
  return threadinfo->m_vpid;
}

long ScapTInfoGetVPGid(CScapThreadInfo ti) {
  sinsp_threadinfo *threadinfo = (sinsp_threadinfo *)ti;
  return threadinfo->m_vpgid;
}

long ScapTInfoGetUid(CScapThreadInfo ti) {
  sinsp_threadinfo *threadinfo = (sinsp_threadinfo *)ti;
  return threadinfo->m_uid;
}

long ScapTInfoGetGid(CScapThreadInfo ti) {
  sinsp_threadinfo *threadinfo = (sinsp_threadinfo *)ti;
  return threadinfo->m_gid;
}

const char *ScapTInfoGetContainerId(CScapThreadInfo ti) {
  sinsp_threadinfo *threadinfo = (sinsp_threadinfo *)ti;
  return threadinfo->m_container_id.c_str();
}

int ScapTInfoGetArgsLen(CScapThreadInfo ti) {
  sinsp_threadinfo *threadinfo = (sinsp_threadinfo *)ti;
  return threadinfo->m_args.size();
}

const char *ScapTInfoGetArgs(CScapThreadInfo ti, int i) {
  sinsp_threadinfo *threadinfo = (sinsp_threadinfo *)ti;
  if (i >= 0 && i < threadinfo->m_args.size()) {
    return threadinfo->m_args.at(i).c_str();
  }
  return NULL;
}
