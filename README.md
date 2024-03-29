# Libs SDK
[![Falco Ecosystem Repository](https://github.com/falcosecurity/evolution/blob/main/repos/badges/falco-ecosystem-blue.svg)](https://github.com/falcosecurity/evolution/blob/main/REPOSITORIES.md#ecosystem-scope) [![Sandbox](https://img.shields.io/badge/status-sandbox-red?style=for-the-badge)](https://github.com/falcosecurity/evolution/blob/main/REPOSITORIES.md#sandbox)

A simplified API (a.k.a. facade) for [Falco Libs](https://github.com/falcosecurity/libs) in Golang.

This is an _experimental_ project. Comments and feedback are welcome!

## Usage

To import the Libs SDK package:

```bash
go get github.com/sysflow-telemetry/libs-sdk-go
```

Below is a minimal example. Check [examples/goscap](examples/goscap) for a complete example.

```go
import (
    "fmt"
    "os"

    "github.com/sysflow-telemetry/libs-sdk-go/pkg/libs"
)

func main() {
    var ev libs.ScapEvent
    inspector := libs.New()
    inspector.HostAndPortResolve(0)
    inspector.OpenLive(30)
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
```

## Build

Pre-requisites:

* docker
* make

To build the SDK, which includes C and Go wrappers for Libs, run:

```bash
make sdk
```

## Hello "Libs"

To compile the examples, run:

```bash
make examples/build
```

The output binary accepts the example name (default: `goscap`) and a scap file (default: `traces/httpd.scap`), and prints some basic event information in the standard output.

```bash
./examples/run.sh [goscap|cppscap|cscap] <scapfile>
```

For example, to test `goscap`, run:

```bash
./examples/run.sh goscap
```

## Libs builder and runtime images

This SDK builds using the [libs](ghcr.io/sysflow-telemetry/libs/libs) builder image currently maintained in a fork of the libs project. Two base images are currently built and hosted in GHCR. These are intented to be used in multi-stage builds where one first builds the Libs consumer using the builder image in an initial stage, and then copies the target executable in a second stage that is derived from the [runtime](ghcr.io/sysflow-telemetry/libs/runtime) image. This should result in very small images for release.

| **Image** | **Description** | **Dockerfile** | **Environment** |
|---|---|---|---|
| ghcr.io/sysflow-telemetry/libs/libs | A base image containing the pre-installed Falco Libs and tools for building Libs consumers | [docker/libs](https://github.com/sysflow-telemetry/libs/blob/libs_base_image/docker/libs/Dockerfile) | FALCOSECURITY_LIBS_CFLAGS<br>FALCOSECURITY_LIBS_LDFLAGS |
| ghcr.io/sysflow-telemetry/libs/runtime | A base image containing the Falco Libs driver loader, to be used to build Libs consumer release images | [docker/driver-loader](https://github.com/sysflow-telemetry/libs/blob/libs_base_image/docker/driver-loader/Dockerfile) | |

The libs builder image defines two built-in environment variables that can be used in build automation for Libs consumers (e.g., see this [Makefile](examples/cppscap/Makefile)):

* FALCOSECURITY_LIBS_CFLAGS: defines the CFLAGS for including the Libs headers

* FALCOSECURITY_LIBS_LDFLAGS: defines the LDFLAGS for linking the Libs libraries and dependencies

## Creating Libs consumer images

Using this SDK, you can easily create Docker images for your Libs consumer. Example dockerfiles are providede in the `examples` directory.

To build the docker images for the examples, run:

```bash
make examples
```

To perform a live capture with any of the example consumers, run:

```bash
./examples/<goscap|cppscap|cscap>/run.sh
```

