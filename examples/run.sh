#!/bin/bash
#
# usage: ./run.sh [goscap|cppscap|cscap] <scapfile>
#

EXAMPLE=${1:-goscap}
TRACE=${2:-traces/httpd.scap}

DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
export $(cat $DIR/../makefile.manifest.inc | grep -v "#" | xargs)

docker run --rm \
    -v $DIR:/examples \
    -w /examples \
    ghcr.io/sysflow-telemetry/libs/libs:$FALCOSECURITY_LIBS_VERSION \
    $EXAMPLE/$EXAMPLE $TRACE