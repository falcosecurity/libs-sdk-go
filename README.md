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
