package sysdiglib
// #include "../c++sysdiglib/sysdig.h"
import "C"

type ScapEvent struct {
	evt C.CScapEvent
}

func (i ScapEvent) GetTS() C.ulong {
	return C.ScapEvGetTS(i.evt)
}

func (i ScapEvent) GetRecordNum() C.ulong {
	return C.ScapEvGetNum(i.evt)
}

func (i ScapEvent) GetCPUID() C.short {
	return C.ScapEvGetCPUID(i.evt)
}

func (i ScapEvent) GetType() C.ushort {
	return C.ScapEvGetType(i.evt)
}

func (i ScapEvent) GetFlags() C.ushort {
	return C.ScapEvGetFlags(i.evt)
}

func (i ScapEvent) GetDirection() C.ushort {
	return C.ScapEvGetDirection(i.evt)
}

func (i ScapEvent) GetName() *C.char {
	return C.ScapEvGetName(i.evt)
}
func (i ScapEvent) GetNameAsGoString() string {
	return C.GoString(C.ScapEvGetName(i.evt))
}
func (i ScapEvent) GetTID() C.long {
	return C.ScapEvGetTID(i.evt)
}
