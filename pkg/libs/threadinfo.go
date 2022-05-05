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

type ThreadInfo struct {
	tinfo C.CScapThreadInfo
}

func (i ThreadInfo) GetProc() *C.char {
	return C.ScapTInfoGetProc(i.tinfo)
}

func (i ThreadInfo) GetProcAsGoString() string {
	return C.GoString(C.ScapTInfoGetProc(i.tinfo))
}

func (i ThreadInfo) GetExe() *C.char {
	return C.ScapTInfoGetExe(i.tinfo)
}

func (i ThreadInfo) GetExeAsGoString() string {
	return C.GoString(C.ScapTInfoGetExe(i.tinfo))
}

func (i ThreadInfo) GetCWD() *C.char {
	return C.ScapTInfoGetCWD(i.tinfo)
}

func (i ThreadInfo) GetCWDAsGoString() string {
	return C.GoString(C.ScapTInfoGetCWD(i.tinfo))
}

func (i ThreadInfo) GetMainThread() *ThreadInfo {
	ti := new(ThreadInfo)
	ti.tinfo = C.ScapTInfoGetMainThread(i.tinfo)
	return ti
}

func (i ThreadInfo) GetTID() int64 {
	return int64(C.ScapTInfoGetTid(i.tinfo))
}

func (i ThreadInfo) GetPID() int64 {
	return int64(C.ScapTInfoGetPid(i.tinfo))
}

func (i ThreadInfo) GetPPID() int64 {
	return int64(C.ScapTInfoGetPPid(i.tinfo))
}

func (i ThreadInfo) GetVTID() int64 {
	return int64(C.ScapTInfoGetVTid(i.tinfo))
}

func (i ThreadInfo) GetVPid() int64 {
	return int64(C.ScapTInfoGetVPid(i.tinfo))
}

func (i ThreadInfo) GetUid() int64 {
	return int64(C.ScapTInfoGetUid(i.tinfo))
}

func (i ThreadInfo) GetGid() int64 {
	return int64(C.ScapTInfoGetGid(i.tinfo))
}

func (i ThreadInfo) GetContainerId() *C.char {
	return C.ScapTInfoGetContainerId(i.tinfo)
}

func (i ThreadInfo) GetContainerIdAsGoString() string {
	return C.GoString(C.ScapTInfoGetContainerId(i.tinfo))
}

func (i ThreadInfo) GetArgs() []string {
	length := int(C.ScapTInfoGetArgsLen(i.tinfo))
	var args []string
	for k := 0; k < length; k++ {
		args = append(args, C.GoString(C.ScapTInfoGetArgs(i.tinfo, C.int(k))))
	}
	return args
}

func (i ThreadInfo) GetArgsLen() int {
	return int(C.ScapTInfoGetArgsLen(i.tinfo))
}
