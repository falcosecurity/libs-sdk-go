package main

import (
	"C"
	"fmt"
	"os"

	"github.com/sysflow-telemetry/libs-sdk/falcolibs"
)

func main() {
	if len(os.Args) > 2 {
		fmtPrintln("usage: ./goscap [<scap file>]")
		os.Exit(1)
	}

	var ev falcolibs.ScapEvent
	inspector := falcolibs.New()
	inspector.HostAndPortResolve(0)
	if len(os.Args) == 2 {
		scapFile := os.Args[1]
		inspector.Open(scapFile)
	} else {
		inspector.OpenLive(30)
	}

	for true {
		res := inspector.Next(&ev)
		if res == falcolibs.SCAP_TIMEOUT {
			// perform timeout checks
		} else if res == falcolibs.SCAP_EOF {
			fmt.Println("SCAP EOF")
			break
		} else if res != falcolibs.SCAP_SUCCESS {
			fmt.Println("SCAP FAILURE")
			break
		} else {
			fmt.Printf("%d %d %s\n", ev.GetRecordNum(), ev.GetTS(), ev.GetNameAsGoString())
		}
	}
	inspector.Close()
	inspector.Free()
}
