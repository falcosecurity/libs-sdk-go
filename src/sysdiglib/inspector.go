package sysdiglib
// #cgo LDFLAGS: -rdynamic  -L../c++sysdiglib/ -lsysdig -L../../sysdig-0.23.0/build/userspace/libsinsp/ -lsinsp -L../../sysdig-0.23.0/build/userspace/libscap/ -lscap -lelf -L../../sysdig-0.23.0/build/zlib-prefix/src/zlib/ -lz -L../../sysdig-0.23.0/build/jq-prefix/src/jq/.libs/ -ljq -L../../sysdig-0.23.0/build/b64-prefix/src/b64/src/ -lb64 -L../../sysdig-0.23.0/build/curl-prefix/src/curl/lib/.libs/ -lcurl -lrt -lanl -L../../sysdig-0.23.0/build/openssl-prefix/src/openssl/target/lib/ -lssl -L../../sysdig-0.23.0/build/openssl-prefix/src/openssl/target/lib/ -lcrypto -L../../sysdig-0.23.0/build/luajit-prefix/src/luajit/src/ -lluajit -ldl -lpthread -lstdc++ -lm
// #cgo CFLAGS: -I/home/terylt/sysdig/sysdig-0.23.0/userspace/libsinsp/ -I/home/terylt/sysdig/sysdig-0.23.0/userspace/libscap/ -I/home/terylt/sysdig/sysdig-0.23.0/userspace/libsinsp/third-party/jsoncpp/ -I../c++sysdiglib/
// #include "../c++sysdiglib/sysdig.h"
import "C"
type ScapInspector struct {
	inspector C.CScapInspector
}

func New() ScapInspector {
	var insp  ScapInspector
	insp.inspector = C.ScapInspNew()
	return insp
}

func (i ScapInspector) Free() {
	C.ScapInspFree(i.inspector)
}

func (i ScapInspector) Next(ev *ScapEvent) C.int {
	return C.ScapInspNext(i.inspector, &ev.evt)
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


/*func main() {
	//var ev ScapEvent
	inspector := New()
//	res := inspector.Next(ev)
	inspector.Free()
}*/
