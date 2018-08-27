#include <sinsp.h>
#define __STDC_FORMAT_MACROS
#include "sysdig.h"
#include "fdinfo.h"


char ScapFDInfoGetCharType(CScapFDInfo fd) {
	sinsp_fdinfo_t* fdinfo = (sinsp_fdinfo_t*)fd;
	return fdinfo->get_typechar();
}

const char* ScapFDInfoGetName(CScapFDInfo fd) {
	sinsp_fdinfo_t* fdinfo = (sinsp_fdinfo_t*)fd;
	return fdinfo->tostring_clean().c_str();
}

int ScapFDInfoIsUnixSock(CScapFDInfo fd) {
	sinsp_fdinfo_t* fdinfo = (sinsp_fdinfo_t*)fd;
	return fdinfo->is_unix_socket();
}

int ScapFDInfoIsIPv4Sock(CScapFDInfo fd) {
	sinsp_fdinfo_t* fdinfo = (sinsp_fdinfo_t*)fd;
	return fdinfo->is_ipv4_socket();
}

int ScapFDInfoIsIPv6Sock(CScapFDInfo fd) {
	sinsp_fdinfo_t* fdinfo = (sinsp_fdinfo_t*)fd;
	return fdinfo->is_ipv6_socket();
}

int ScapFDInfoIsUDPSock(CScapFDInfo fd) {
	sinsp_fdinfo_t* fdinfo = (sinsp_fdinfo_t*)fd;
	return fdinfo->is_udp_socket();
}

int ScapFDInfoIsTCPSock(CScapFDInfo fd) {
	sinsp_fdinfo_t* fdinfo = (sinsp_fdinfo_t*)fd;
	return fdinfo->is_tcp_socket();
}

int ScapFDInfoIsPipe(CScapFDInfo fd) {
	sinsp_fdinfo_t* fdinfo = (sinsp_fdinfo_t*)fd;
	return fdinfo->is_pipe();
}

int ScapFDInfoIsFile(CScapFDInfo fd) {
	sinsp_fdinfo_t* fdinfo = (sinsp_fdinfo_t*)fd;
	return fdinfo->is_file();
}

int ScapFDInfoIsDirectory(CScapFDInfo fd) {
	sinsp_fdinfo_t* fdinfo = (sinsp_fdinfo_t*)fd;
	return fdinfo->is_directory();
}

unsigned short ScapFDInfoGetServPort(CScapFDInfo fd) {
	sinsp_fdinfo_t* fdinfo = (sinsp_fdinfo_t*)fd;
	return fdinfo->get_serverport();
}

scap_l4_proto ScapFDInfoGetL4Proto(CScapFDInfo fd) {
	sinsp_fdinfo_t* fdinfo = (sinsp_fdinfo_t*)fd;
	return fdinfo->get_l4proto();
}

int ScapFDInfoIsRoleServer(CScapFDInfo fd) {
	sinsp_fdinfo_t* fdinfo = (sinsp_fdinfo_t*)fd;
	return fdinfo->is_role_server();
}

int ScapFDInfoIsRoleClient(CScapFDInfo fd) {
	sinsp_fdinfo_t* fdinfo = (sinsp_fdinfo_t*)fd;
	return fdinfo->is_role_client();
}

int ScapFDInfoIsRoleNone(CScapFDInfo fd) {
	sinsp_fdinfo_t* fdinfo = (sinsp_fdinfo_t*)fd;
	return fdinfo->is_role_none();
}

int ScapFDInfoIsSocketConnected(CScapFDInfo fd) {
	sinsp_fdinfo_t* fdinfo = (sinsp_fdinfo_t*)fd;
	return fdinfo->is_socket_connected();
}

int ScapFDInfoIsCloned(CScapFDInfo fd) {
	sinsp_fdinfo_t* fdinfo = (sinsp_fdinfo_t*)fd;
	return fdinfo->is_cloned();
}

const char* ScapFDInfoGetOldName(CScapFDInfo fd) {
	sinsp_fdinfo_t* fdinfo = (sinsp_fdinfo_t*)fd;
	return fdinfo->m_oldname.c_str();
}

unsigned int ScapFDInfoGetSIPv4(CScapFDInfo fd) {
	sinsp_fdinfo_t* fdinfo = (sinsp_fdinfo_t*)fd;
	return fdinfo->m_sockinfo.m_ipv4info.m_fields.m_sip;
}

unsigned int ScapFDInfoGetDIPv4(CScapFDInfo fd) {
	sinsp_fdinfo_t* fdinfo = (sinsp_fdinfo_t*)fd;
	return fdinfo->m_sockinfo.m_ipv4info.m_fields.m_dip;
}

unsigned short ScapFDInfoGetSPortv4(CScapFDInfo fd) {
	sinsp_fdinfo_t* fdinfo = (sinsp_fdinfo_t*)fd;
	return fdinfo->m_sockinfo.m_ipv4info.m_fields.m_sport;
}

unsigned short ScapFDInfoGetDPortv4(CScapFDInfo fd) {
	sinsp_fdinfo_t* fdinfo = (sinsp_fdinfo_t*)fd;
	return fdinfo->m_sockinfo.m_ipv4info.m_fields.m_dport;
}

unsigned char ScapFDInfoGetProtov4(CScapFDInfo fd) {
	sinsp_fdinfo_t* fdinfo = (sinsp_fdinfo_t*)fd;
	return fdinfo->m_sockinfo.m_ipv4info.m_fields.m_l4proto;
}

void* ScapFDInfoGetSIPv6(CScapFDInfo fd) {
	sinsp_fdinfo_t* fdinfo = (sinsp_fdinfo_t*)fd;
	return (void*)fdinfo->m_sockinfo.m_ipv6info.m_fields.m_sip;
}

void* ScapFDInfoGetDIPv6(CScapFDInfo fd) {
	sinsp_fdinfo_t* fdinfo = (sinsp_fdinfo_t*)fd;
	return (void*)fdinfo->m_sockinfo.m_ipv6info.m_fields.m_dip;
}

unsigned short ScapFDInfoGetDPortv6(CScapFDInfo fd) {
	sinsp_fdinfo_t* fdinfo = (sinsp_fdinfo_t*)fd;
	return (unsigned short)fdinfo->m_sockinfo.m_ipv6info.m_fields.m_dport;
}

unsigned short ScapFDInfoGetSPortv6(CScapFDInfo fd) {
	sinsp_fdinfo_t* fdinfo = (sinsp_fdinfo_t*)fd;
	return (unsigned short)fdinfo->m_sockinfo.m_ipv6info.m_fields.m_sport;
}

unsigned char ScapFDInfoGetProtov6(CScapFDInfo fd) {
	sinsp_fdinfo_t* fdinfo = (sinsp_fdinfo_t*)fd;
	return fdinfo->m_sockinfo.m_ipv6info.m_fields.m_l4proto;
}
