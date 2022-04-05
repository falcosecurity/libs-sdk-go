package main

import (
	"C"
	"fmt"
	"os"

	"github.com/sysflow-telemetry/libs-sdk/falcolibs"
)

func main() {
	scapFile := os.Args[1]
	var ev falcolibs.ScapEvent
	inspector := falcolibs.New()
	inspector.HostAndPortResolve(0)
	inspector.Open(scapFile)
	for true {
		res := inspector.Next(&ev)
		if res == falcolibs.SCAP_TIMEOUT {
			fmt.Println("SCAP TIMEOUT")
		} else if res == falcolibs.SCAP_EOF {
			fmt.Println("SCAP EOF")
			break
		} else if res != falcolibs.SCAP_SUCCESS {
			fmt.Println("SCAP FAILURE")
			break
		}
		fmt.Printf("%d %d %s\n", ev.GetRecordNum(), ev.GetTS(), ev.GetNameAsGoString())
	}
	inspector.Close()
	inspector.Free()
}
