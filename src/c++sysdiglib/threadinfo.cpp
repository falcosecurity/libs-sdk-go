#include <sinsp.h>
#define __STDC_FORMAT_MACROS
#include "sysdig.h"

const char* ScapTInfoGetProc(CScapThreadInfo ti){
	sinsp_threadinfo* threadinfo = (sinsp_threadinfo*)ti;
	return threadinfo->get_comm().c_str();
}

const char* ScapTInfoGetExe(CScapThreadInfo ti){
	sinsp_threadinfo* threadinfo = (sinsp_threadinfo*)ti;
	return threadinfo->get_exe().c_str();
}
const char* ScapTInfoGetCWD(CScapThreadInfo ti){
	sinsp_threadinfo* threadinfo = (sinsp_threadinfo*)ti;
	return threadinfo->get_cwd().c_str();
}
CScapThreadInfo ScapTInfoGetMainThread(CScapThreadInfo ti){
	sinsp_threadinfo* threadinfo = (sinsp_threadinfo*)ti;
	return threadinfo->get_main_thread();
}
CScapThreadInfo ScapTInfoGetParentThread(CScapThreadInfo ti){
	sinsp_threadinfo* threadinfo = (sinsp_threadinfo*)ti;
	return threadinfo->get_parent_thread();
}
long ScapTInfoGetTid(CScapThreadInfo ti) {
	sinsp_threadinfo* threadinfo = (sinsp_threadinfo*)ti;
	return threadinfo->m_tid;
}

long ScapTInfoGetPid(CScapThreadInfo ti) {
	sinsp_threadinfo* threadinfo = (sinsp_threadinfo*)ti;
	return threadinfo->m_pid;
}
long ScapTInfoGetPPid(CScapThreadInfo ti) {
	sinsp_threadinfo* threadinfo = (sinsp_threadinfo*)ti;
	return threadinfo->m_ptid;
}
long ScapTInfoGetVTid(CScapThreadInfo ti) {
	sinsp_threadinfo* threadinfo = (sinsp_threadinfo*)ti;
	return threadinfo->m_vtid;
}
long ScapTInfoGetVPid(CScapThreadInfo ti) {
	sinsp_threadinfo* threadinfo = (sinsp_threadinfo*)ti;
	return threadinfo->m_vpid;
}
long ScapTInfoGetVPGid(CScapThreadInfo ti) {
	sinsp_threadinfo* threadinfo = (sinsp_threadinfo*)ti;
	return threadinfo->m_vpgid;
}
long ScapTInfoGetUid(CScapThreadInfo ti) {
	sinsp_threadinfo* threadinfo = (sinsp_threadinfo*)ti;
	return threadinfo->m_uid;
}
long ScapTInfoGetGid(CScapThreadInfo ti) {
	sinsp_threadinfo* threadinfo = (sinsp_threadinfo*)ti;
	return threadinfo->m_gid;
}

const char* ScapTInfoGetContainerId(CScapThreadInfo ti) {
	sinsp_threadinfo* threadinfo = (sinsp_threadinfo*)ti;
	return threadinfo->m_container_id.c_str();
}

int ScapTInfoGetArgsLen(CScapThreadInfo ti) {
	sinsp_threadinfo* threadinfo = (sinsp_threadinfo*)ti;
	return threadinfo->m_args.size();
}

const char* ScapTInfoGetArgs(CScapThreadInfo ti, int i) {
	sinsp_threadinfo* threadinfo = (sinsp_threadinfo*)ti;
	if (i >= 0 && i < threadinfo->m_args.size()) {
		return threadinfo->m_args.at(i).c_str();
	}
	return NULL;
}




