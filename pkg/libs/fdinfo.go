// Copyright (C) 2022 The Falco Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Package libs provides a Go wrapper for the Libs public APIs.
package libs

// #include "../c/libs.h"
import "C"

type FDInfo struct {
	fdinfo C.CScapFDInfo
}

func (i FDInfo) GetTypeChar() byte {
	return byte(C.ScapFDInfoGetCharType(i.fdinfo))
}

func (i FDInfo) GetName() *C.char {
	return C.ScapFDInfoGetName(i.fdinfo)
}

func (i FDInfo) GetNameAsGoString() string {
	return C.GoString(C.ScapFDInfoGetName(i.fdinfo))
}

func (i FDInfo) GetOldName() *C.char {
	return C.ScapFDInfoGetName(i.fdinfo)
}

func (i FDInfo) GetOldNameAsGoString() string {
	return C.GoString(C.ScapFDInfoGetName(i.fdinfo))
}

func (i FDInfo) IsUnixSock() bool {
	return bool(C.ScapFDInfoIsUnixSock(i.fdinfo) == 1)
}

func (i FDInfo) IsIPv4Sock() bool {
	return bool(C.ScapFDInfoIsIPv4Sock(i.fdinfo) == 1)
}

func (i FDInfo) IsIPv6Sock() bool {
	return bool(C.ScapFDInfoIsIPv6Sock(i.fdinfo) == 1)
}

func (i FDInfo) IsUDPSock() bool {
	return bool(C.ScapFDInfoIsUDPSock(i.fdinfo) == 1)
}

func (i FDInfo) IsTCPSock() bool {
	return bool(C.ScapFDInfoIsTCPSock(i.fdinfo) == 1)
}

func (i FDInfo) IsPipe() bool {
	return bool(C.ScapFDInfoIsPipe(i.fdinfo) == 1)
}

func (i FDInfo) IsFile() bool {
	return bool(C.ScapFDInfoIsFile(i.fdinfo) == 1)
}

func (i FDInfo) IsDirectory() bool {
	return bool(C.ScapFDInfoIsDirectory(i.fdinfo) == 1)
}

func (i FDInfo) GetServerPort() uint16 {
	return uint16(C.ScapFDInfoGetServPort(i.fdinfo))
}

func (i FDInfo) GetL4Proto() uint16 {
	return uint16(C.ScapFDInfoGetL4Proto(i.fdinfo))
}

func (i FDInfo) IsRoleServer() bool {
	return bool(C.ScapFDInfoIsRoleServer(i.fdinfo) == 1)
}

func (i FDInfo) IsRoleClient() bool {
	return bool(C.ScapFDInfoIsRoleClient(i.fdinfo) == 1)
}

func (i FDInfo) IsRoleNone() bool {
	return bool(C.ScapFDInfoIsRoleNone(i.fdinfo) == 1)
}

func (i FDInfo) IsSockConn() bool {
	return bool(C.ScapFDInfoIsSocketConnected(i.fdinfo) == 1)
}

func (i FDInfo) IsCloned() bool {
	return bool(C.ScapFDInfoIsCloned(i.fdinfo) == 1)
}

func (i FDInfo) GetSIPv4() uint32 {
	return uint32(C.ScapFDInfoGetSIPv4(i.fdinfo))
}

func (i FDInfo) GetDIPv4() uint32 {
	return uint32(C.ScapFDInfoGetDIPv4(i.fdinfo))
}

func (i FDInfo) GetDPortv4() uint16 {
	return uint16(C.ScapFDInfoGetDPortv4(i.fdinfo))
}

func (i FDInfo) GetProtov4() uint16 {
	return uint16(C.ScapFDInfoGetProtov4(i.fdinfo))
}

func (i FDInfo) GetDIPv6() []byte {
	return C.GoBytes(C.ScapFDInfoGetDIPv6(i.fdinfo), 16)
}

func (i FDInfo) GetSIPv6() []byte {
	return C.GoBytes(C.ScapFDInfoGetSIPv6(i.fdinfo), 16)
}

func (i FDInfo) GetDPortv6() uint16 {
	return uint16(C.ScapFDInfoGetDPortv6(i.fdinfo))
}

func (i FDInfo) GetSPortv6() uint16 {
	return uint16(C.ScapFDInfoGetSPortv6(i.fdinfo))
}

func (i FDInfo) GetProtov6() uint16 {
	return uint16(C.ScapFDInfoGetProtov6(i.fdinfo))
}
