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

// Package falcolibs provides a Go wrapper for the Libs public APIs.
package falcolibs

// #include "../c/libs.h"
import "C"

type ScapEvent struct {
	evt C.CScapEvent
	ti  ThreadInfo
}

func (i ScapEvent) GetTS() uint64 {
	return uint64(C.ScapEvGetTS(i.evt))
}

func (i ScapEvent) GetRecordNum() uint64 {
	return uint64(C.ScapEvGetNum(i.evt))
}

func (i ScapEvent) GetCPUID() uint16 {
	return uint16(C.ScapEvGetCPUID(i.evt))
}

func (i ScapEvent) GetType() uint16 {
	return uint16(C.ScapEvGetType(i.evt))
}

func (i ScapEvent) GetFlags() uint16 {
	return uint16(C.ScapEvGetFlags(i.evt))
}

func (i ScapEvent) GetDirection() uint16 {
	return uint16(C.ScapEvGetDirection(i.evt))
}

func (i ScapEvent) GetName() *C.char {
	return C.ScapEvGetName(i.evt)
}
func (i ScapEvent) GetNameAsGoString() string {
	return C.GoString(C.ScapEvGetName(i.evt))
}
func (i ScapEvent) GetTID() int64 {
	return int64(C.ScapEvGetTID(i.evt))
}

func (i ScapEvent) GetThreadInfo(queryOS bool) *ThreadInfo {
	if queryOS {
		i.ti.tinfo = C.ScapEvGetThreadInfo(i.evt, 1)
	} else {
		i.ti.tinfo = C.ScapEvGetThreadInfo(i.evt, 0)
	}
	return &(i.ti)
}
