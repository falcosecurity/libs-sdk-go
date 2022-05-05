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

// An example Libs consumer based on libs-sdk-go.
package main

import (
	"C"
	"fmt"
	"os"

	"github.com/sysflow-telemetry/libs-sdk-go/pkg/libs"
)

func main() {
	if len(os.Args) > 2 {
		fmt.Println("usage: ./goscap [<scap file>]")
		os.Exit(1)
	}

	var ev libs.ScapEvent
	inspector := libs.New()
	inspector.HostAndPortResolve(0)
	if len(os.Args) == 2 {
		scapFile := os.Args[1]
		inspector.Open(scapFile)
	} else {
		inspector.OpenLive(30)
	}

	for true {
		res := inspector.Next(&ev)
		if res == libs.SCAP_TIMEOUT {
			// perform timeout checks
		} else if res == libs.SCAP_EOF {
			fmt.Println("SCAP EOF")
			break
		} else if res != libs.SCAP_SUCCESS {
			fmt.Println("SCAP FAILURE")
			break
		} else {
			fmt.Printf("%d %d %s\n", ev.GetRecordNum(), ev.GetTS(), ev.GetNameAsGoString())
		}
	}
	inspector.Close()
	inspector.Free()
}
