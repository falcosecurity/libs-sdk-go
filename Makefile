include makefile.manifest.inc

.PHONY: all
all: sdk

.PHONY: sdk
apis: cpp go

.PHONY: cpp
cpp:
	docker run --rm -v $(pwd)/src:/src ghcr.io/sysflow-telemetry/libs/libs:$(FALCOSECURITY_LIBS_VERSION) make -C /src/c++

.PHONY: go
go:
	cpp
	docker run --rm -v $(pwd)/src:/src ghcr.io/sysflow-telemetry/libs/libs:$(FALCOSECURITY_LIBS_VERSION) make -C /src/go

.PHONY: clean
clean:
	make -C src/c++ clean
	make -C src/go clean

.PHONY : help
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... sdk"
	@echo "... cpp"
	@echo "... go"
