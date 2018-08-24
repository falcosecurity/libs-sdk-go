package sysdiglib
// #include "../c++sysdiglib/sysdig.h"
import "C"

type ThreadInfo struct {
	tinfo C.CScapThreadInfo
}
/*
func (i ThreadInfo) GetTS() C.ulong {
	return C.ScapEvGetTS(i.evt)
}

func (i ThreadInfo) GetRecordNum() C.ulong {
	return C.ScapEvGetNum(i.evt)
}

func (i ThreadInfo) GetCPUID() C.short {
	return C.ScapEvGetCPUID(i.evt)
}

func (i ThreadInfo) GetType() C.ushort {
	return C.ScapEvGetType(i.evt)
}

func (i ThreadInfo) GetFlags() C.ushort {
	return C.ScapEvGetFlags(i.evt)
}

func (i ThreadInfo) GetDirection() C.ushort {
	return C.ScapEvGetDirection(i.evt)
}

func (i ThreadInfo) GetName() *C.char {
	return C.ScapEvGetName(i.evt)
}
func (i ThreadInfo) GetNameAsGoString() string {
	return C.GoString(C.ScapEvGetName(i.evt))
}
func (i ThreadInfo) GetTID() C.long {
	return C.ScapEvGetTID(i.evt)
}*/
