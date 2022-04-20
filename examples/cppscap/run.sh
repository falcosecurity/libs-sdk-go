#!/bin/bash
docker run \
    --privileged \
    -v /tmp:/tmp \
    -v /var/run/docker.sock:/host/var/run/docker.sock \
    -v /dev:/host/dev \
    -v /proc:/host/proc:ro \
    -v /boot:/host/boot:ro \
    -v /lib/modules:/host/lib/modules:ro \
    -v /usr:/host/usr:ro \
    -v /etc/:/host/etc:ro \
    -it --rm cppscap
