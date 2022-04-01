#ifndef __LIBS_API__
#define __LIBS_API__
#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus
	typedef void *CScapInspector;
	typedef void *CScapEvent;
	typedef void *CScapThreadInfo;
	typedef void *CScapFDInfo;

	CScapInspector ScapInspNew(void);
	void ScapInspFree(CScapInspector);
	int ScapInspNext(CScapInspector, CScapEvent *);
	void ScapInspHostAndPortResolve(CScapInspector, int);
	int ScapInspOpen(CScapInspector, char *);
	void ScapInspClose(CScapInspector);

	unsigned long ScapEvGetTS(CScapEvent);
	unsigned long ScapEvGetNum(CScapEvent ev);
	short ScapEvGetCPUID(CScapEvent ev);
	unsigned short ScapEvGetType(CScapEvent ev);
	unsigned short ScapEvGetFlags(CScapEvent ev);
	unsigned short ScapEvGetDirection(CScapEvent ev);
	const char *ScapEvGetName(CScapEvent ev);
	long ScapEvGetTID(CScapEvent ev);
	CScapThreadInfo ScapEvGetThreadInfo(CScapEvent ev, int queryOS);

	const char *ScapTInfoGetProc(CScapThreadInfo);
	const char *ScapTInfoGetExe(CScapThreadInfo);
	const char *ScapTInfoGetCWD(CScapThreadInfo);
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
	const char *ScapTInfoGetContainerId(CScapThreadInfo ti);
	int ScapTInfoGetArgsLen(CScapThreadInfo ti);
	const char *ScapTInfoGetArgs(CScapThreadInfo ti, int i);

	char ScapFDInfoGetCharType(CScapFDInfo fd);
	const char *ScapFDInfoGetName(CScapFDInfo fd);
	int ScapFDInfoIsUnixSock(CScapFDInfo fd);
	int ScapFDInfoIsIPv4Sock(CScapFDInfo fd);
	int ScapFDInfoIsIPv6Sock(CScapFDInfo fd);
	int ScapFDInfoIsUDPSock(CScapFDInfo fd);
	int ScapFDInfoIsTCPSock(CScapFDInfo fd);
	int ScapFDInfoIsPipe(CScapFDInfo fd);
	int ScapFDInfoIsFile(CScapFDInfo fd);
	int ScapFDInfoIsDirectory(CScapFDInfo fd);
	unsigned short ScapFDInfoGetServPort(CScapFDInfo fd);
	unsigned short ScapFDInfoGetL4Proto(CScapFDInfo fd);
	int ScapFDInfoIsRoleServer(CScapFDInfo fd);
	int ScapFDInfoIsRoleClient(CScapFDInfo fd);
	int ScapFDInfoIsRoleNone(CScapFDInfo fd);
	int ScapFDInfoIsSocketConnected(CScapFDInfo fd);
	int ScapFDInfoIsCloned(CScapFDInfo fd);
	const char *ScapFDInfoGetOldName(CScapFDInfo fd);
	unsigned int ScapFDInfoGetSIPv4(CScapFDInfo fd);
	unsigned int ScapFDInfoGetDIPv4(CScapFDInfo fd);
	unsigned short ScapFDInfoGetSPortv4(CScapFDInfo fd);
	unsigned short ScapFDInfoGetDPortv4(CScapFDInfo fd);
	unsigned char ScapFDInfoGetProtov4(CScapFDInfo fd);
	void *ScapFDInfoGetSIPv6(CScapFDInfo fd);
	void *ScapFDInfoGetDIPv6(CScapFDInfo fd);
	unsigned short ScapFDInfoGetDPortv6(CScapFDInfo fd);
	unsigned short ScapFDInfoGetSPortv6(CScapFDInfo fd);
	unsigned char ScapFDInfoGetProtov6(CScapFDInfo fd);

#ifdef __cplusplus
}
#endif //__cplusplus
#endif //__LIBS_API__
