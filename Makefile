include makefile.manifest.inc

.PHONY: all
all: sdk

.PHONY: sdk
sdk: cpp \
	 go

.PHONY: cpp
cpp:
	docker run --rm -v $(shell pwd)/src:/src ghcr.io/sysflow-telemetry/libs/libs:$(FALCOSECURITY_LIBS_VERSION) make -C /src/c++

.PHONY: enter
enter:
	docker run -it --rm -v $(shell pwd)/src:/src ghcr.io/sysflow-telemetry/libs/libs:$(FALCOSECURITY_LIBS_VERSION) bash


.PHONY: go
go:
	docker run --rm -v $(shell pwd)/src:/src ghcr.io/sysflow-telemetry/libs/libs:$(FALCOSECURITY_LIBS_VERSION) /bin/bash -c "export CGO_LDFLAGS="" && make -C /src/c++ && make -C /src/go"

.PHONY: examples
examples:
	docker run --rm -v $(shell pwd)/src:/src -v $(shell pwd)/examples:/examples ghcr.io/sysflow-telemetry/libs/libs:$(FALCOSECURITY_LIBS_VERSION) /bin/bash -c "make -C /src/c++ && make -C /src/go install && make -C /examples/goscap && make -C /examples/cscap && make -C /examples/cppscap"

.PHONY: install_libs_headers
install_libs_local:
	mkdir -p build/include && docker run --rm -v $(shell pwd)/build:/build ghcr.io/sysflow-telemetry/libs/libs:$(FALCOSECURITY_LIBS_VERSION) cp -r /usr/include/falcosecurity build/include/.

.PHONY: clean
clean:
	make -C src/c++ clean
	make -C src/go clean
	make -C examples/goscap clean
	make -C examples/cscap clean
	make -C examples/cppscap clean
	rm -rf build

.PHONY : help
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... sdk"
	@echo "... cpp"
	@echo "... go"
	@echo "... install_libs_headers"
