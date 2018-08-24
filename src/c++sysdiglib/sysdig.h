#ifndef __SYSDIG_GO_LIBRARY__
#define __SYSDIG_GO_LIBRARY__
#ifdef __cplusplus
extern "C" {
#endif

	typedef void* CScapInspector;
	typedef void* CScapEvent;
 	typedef void* CScapThreadInfo;
	typedef void* CScapFDInfo;

	CScapInspector ScapInspNew(void);
	void ScapInspFree(CScapInspector);
	int ScapInspNext(CScapInspector, CScapEvent*);
	void ScapInspHostAndPortResolve(CScapInspector, int);
        int ScapInspOpen(CScapInspector, char*);
        void ScapInspClose(CScapInspector);

        unsigned long ScapEvGetTS(CScapEvent);
	unsigned long ScapEvGetNum(CScapEvent ev); 
	short ScapEvGetCPUID(CScapEvent ev); 
	unsigned short ScapEvGetType(CScapEvent ev); 
	unsigned short ScapEvGetFlags(CScapEvent ev);
	unsigned short ScapEvGetDirection(CScapEvent ev); 
	const char* ScapEvGetName(CScapEvent ev);
	long ScapEvGetTID(CScapEvent ev);

	const char* ScapTInfoGetProc(CScapThreadInfo);
	const char* ScapTInfoGetExe(CScapThreadInfo);
	const char* ScapTInfoGetCWD(CScapThreadInfo);
	CScapThreadInfo ScapTInfoGetMainThread(CScapThreadInfo ti);
	CScapThreadInfo ScapTInfoGetParentThread(CScapThreadInfo ti);
	long ScapTInfoGetTid(CScapThreadInfo ti);
	long ScapTInfoGetPid(CScapThreadInfo ti); 
	long ScapTInfoGetPPid(CScapThreadInfo ti); 
	long ScapTInfoGetVTid(CScapThreadInfo ti); 
	long ScapTInfoGetVPid(CScapThreadInfo ti); 
	long ScapTInfoGetVPGid(CScapThreadInfo ti); 
	long ScapTInfoGetUid(CScapThreadInfo ti); 
	long ScapTInfoGetGid(CScapThreadInfo ti);
	const char* ScapTInfoGetContainerId(CScapThreadInfo ti);

	int ScapTInfoGetArgsLen(CScapThreadInfo ti); 
	const char* ScapTInfoGetArgs(CScapThreadInfo ti, int i); 
	CScapThreadInfo ScapEvGetThreadInfo(CScapEvent ev, int queryOS);     

#ifdef __cplusplus
}
#endif
#endif
