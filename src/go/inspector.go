package falcolibs

// #include "../c++/libs.h"
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

func (i ScapInspector) Close() {
	C.ScapInspClose(i.inspector)
}

func (i ScapInspector) HostAndPortResolve(resolve int) {
	C.ScapInspHostAndPortResolve(i.inspector, C.int(resolve))
}
