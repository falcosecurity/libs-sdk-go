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

type ScapInspector struct {
	inspector C.CScapInspector
}

func New() ScapInspector {
	var insp ScapInspector
	insp.inspector = C.ScapInspNew()
	return insp
}

func (i ScapInspector) Free() {
	C.ScapInspFree(i.inspector)
}

func (i ScapInspector) Next(ev *ScapEvent) int {
	return int(C.ScapInspNext(i.inspector, &ev.evt))
}

func (i ScapInspector) Open(file string) int {
	fileC := C.CString(file)
	return int(C.ScapInspOpen(i.inspector, fileC))
}

func (i ScapInspector) OpenLive(timestamp uint) int {
	return int(C.ScapInspOpenLive(i.inspector, C.uint(timestamp)))
}

func (i ScapInspector) Close() {
	C.ScapInspClose(i.inspector)
}

func (i ScapInspector) HostAndPortResolve(resolve int) {
	C.ScapInspHostAndPortResolve(i.inspector, C.int(resolve))
}
