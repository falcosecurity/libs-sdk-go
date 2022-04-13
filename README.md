# Libs SDK (experimental)

A simplified API (a.k.a. facade) for [Falco Libs](https://github.com/falcosecurity/libs).

This is an _experimental_ project. Comments and feedback are welcome!

## Build

Pre-requisites:

* docker
* make

To build the SDK, which includes C++ and Go wrappers for Libs, run:

```bash
make sdk
```

## Hello "Libs"

To compile the examples, run:

```bash
make examples
```

The output binary accepts the example name (default: `goscap`) and a scap file (default: `traces/httpd.scap`), and prints some basic event information in the standard output.

```bash
./examples/run.sh [goscap|cppscap|cscap] <scapfile>
```

For example, to test `goscap`, run:

```bash
./examples/run.sh goscap
```

## Libs builder image

This SDK builds using the [libs](ghcr.io/sysflow-telemetry/libs/libs) builder image currently maintained in a fork of the libs project. Two base images are currently built and hosted in GHCR. These are intented to be used in multi-stage builds where one first builds the Libs consumer using the builder image in an initial stage, and then copies the target executable in a second stage that is derived from the [driver-loader](ghcr.io/sysflow-telemetry/libs/driver-loader) image. This should result in very small images for release.

| **Image** | **Description** | **Dockerfile** | **Environment** |
|---|---|---|---|
| ghcr.io/sysflow-telemetry/libs/libs | A base image containing the pre-installed Falco Libs and tools for building Libs consumers | [docker/libs](https://github.com/sysflow-telemetry/libs/blob/libs_base_image/docker/libs/Dockerfile) | FALCOSECURITY_LIBS_CFLAGS<br>FALCOSECURITY_LIBS_LDFLAGS |
| ghcr.io/sysflow-telemetry/libs/driver-loader | A base image containing the Falco Libs driver loader, to be used to build Libs consumer release images | [docker/driver-loader](https://github.com/sysflow-telemetry/libs/blob/libs_base_image/docker/driver-loader/Dockerfile) | |

The libs builder image defines two built-in environment variables that can be used in build automation for Libs consumers (e.g., see this [Makefile](examples/cppscap/Makefile)):

* FALCOSECURITY_LIBS_CFLAGS: defines the CFLAGS for including the Libs headers

* FALCOSECURITY_LIBS_LDFLAGS: defines the LDFLAGS for linking the Libs libraries and dependencies
