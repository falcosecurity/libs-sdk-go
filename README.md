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

To compile the examples (currently, "goscap"), run:

```bash
make examples
```

The output binary accepts a scap trace and prints some basic event information in the standard output.

To test it, run:

```bash
./goscap ../traces/httpd.scap
```
