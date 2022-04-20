include makefile.manifest.inc

.PHONY: all
all: sdk

.PHONY: sdk
sdk: sdk/c \
	 sdk/go

.PHONY: sdk/c
sdk/c:
	docker run --rm -v $(shell pwd)/src:/build/src ghcr.io/sysflow-telemetry/libs/libs:$(FALCOSECURITY_LIBS_VERSION) make -C /build/src/c

.PHONY: sdk/go
sdk/go:
	docker run --rm -v $(shell pwd)/src:/build/src ghcr.io/sysflow-telemetry/libs/libs:$(FALCOSECURITY_LIBS_VERSION) /bin/bash -c "make -C /build/src/c && make -C /build/src/go"

.PHONY: examples/build
examples/build:
	docker run --rm -v $(shell pwd)/src:/build/src -v $(shell pwd)/examples:/build/examples ghcr.io/sysflow-telemetry/libs/libs:$(FALCOSECURITY_LIBS_VERSION) /bin/bash -c "make -C /build/src/c && make -C /build/src/go install && make -C /build/examples/goscap && make -C /build/examples/cscap && make -C /build/examples/cppscap"

.PHONY: examples/cscap
examples/cscap:
	docker build --build-arg FALCOSECURITY_LIBS_VERSION=$(FALCOSECURITY_LIBS_VERSION) --build-arg FALCOSECURITY_DRIVER_VERSION=$(FALCOSECURITY_DRIVER_VERSION) -f examples/cscap/Dockerfile -t cscap .

.PHONY: examples/cppscap
examples/cppscap:
	docker build --build-arg FALCOSECURITY_LIBS_VERSION=$(FALCOSECURITY_LIBS_VERSION) --build-arg FALCOSECURITY_DRIVER_VERSION=$(FALCOSECURITY_DRIVER_VERSION) -f examples/cppscap/Dockerfile -t cppscap .

.PHONY: examples/goscap
examples/goscap:
	docker build --build-arg FALCOSECURITY_LIBS_VERSION=$(FALCOSECURITY_LIBS_VERSION) --build-arg FALCOSECURITY_DRIVER_VERSION=$(FALCOSECURITY_DRIVER_VERSION) -f examples/goscap/Dockerfile -t goscap .

.PHONY: examples
examples: examples/cscap \
	examples/cppscap \
	examples/goscap

.PHONY: install_libs_headers
install_libs_headers:
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
	@echo "... sdk/c"
	@echo "... sdk/go"
	@echo "... examples"
	@echo "... examples/build"
	@echo "... examples/cscap"
	@echo "... examples/cppscap"
	@echo "... examples/goscap"
	@echo "... install_libs_headers"
