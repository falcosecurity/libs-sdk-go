ARG FALCOSECURITY_LIBS_VERSION=latest
ARG FALCOSECURITY_DRIVER_VERSION=latest

### builder: based on libs base image
FROM ghcr.io/sysflow-telemetry/libs/libs:${FALCOSECURITY_LIBS_VERSION} as builder

COPY examples /build/examples
RUN make -C /build/examples/cppscap

### runtime: based on libs runtime base image
FROM ghcr.io/sysflow-telemetry/libs/runtime:${FALCOSECURITY_DRIVER_VERSION} as runtime

ENV FALCOSECURITY_DRIVER_NAME="falco"

ARG FALCOSECURITY_DRIVER_VERSION=latest
ENV FALCOSECURITY_DRIVER_VERSION=${FALCOSECURITY_DRIVER_VERSION}

COPY --from=builder /build/examples/cppscap/cppscap /usr/local/bin/cppscap
COPY --from=builder /usr/src /usr/src

RUN sed -i -E "s/@DRIVER_NAME@/\"${FALCOSECURITY_DRIVER_NAME}\"/" /usr/bin/falco-driver-loader && \
    sed -i -E "s/@DRIVER_VERSION@/\"${FALCOSECURITY_DRIVER_VERSION}\"/" /usr/bin/falco-driver-loader

CMD /usr/local/bin/cppscap
