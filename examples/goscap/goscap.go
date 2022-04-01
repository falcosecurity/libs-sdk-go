package main

// #cgo LDFLAGS: -lsysdig -lscap -lsinsp.
// #cgo CFLAGS: -I/home/terylt/sysdig/sysdig-0.23.0/userspace/libsinsp/ -I/home/terylt/sysdig/sysdig-0.23.0/userspace/libscap/ -I/home/terylt/sysdig/sysdig-0.23.0/userspace/libsinsp/third-party/jsoncpp/
// #include "../c++sysdiglib/sysdig.h"
import (
        "sysdiglib"
	"os"
	"fmt"
	"C"
       )

func main() {
	scapFile := os.Args[1]
	var ev sysdiglib.ScapEvent
	inspector := sysdiglib.New()
	inspector.HostAndPortResolve(0)
	inspector.Open(scapFile)
	for true {
		res := inspector.Next(&ev)
		if(res == sysdiglib.SCAP_TIMEOUT) {
			fmt.Println("SCAP TIMEOUT")
		} else if (res == sysdiglib.SCAP_EOF){
			fmt.Println("SCAP EOF")
			break
		} else if (res != sysdiglib.SCAP_SUCCESS){
			fmt.Println("SCAP FAILURE")
			break
		}
		//fmt.Println("SCAP SUCCESS")
		fmt.Printf("%d %d %s\n", ev.GetRecordNum(), ev.GetTS(), ev.GetNameAsGoString())
	}
	inspector.Close()
	inspector.Free()
}
