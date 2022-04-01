package libs

// #include "../c++/libs.h"
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
