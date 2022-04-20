#
# FALCOSECURITY_LIBS_CFLAGS and FALCOSECURITY_LIBS_LDFLAGS are environment variables
# defined in the libs builder image currently hosted in ghcr.io/sysflow-telemetry/libs/libs
#
CXX = gcc
CFLAGS = -D_GNU_SOURCE -DHAS_CAPTURE -Wall -DNDEBUG -I/build/src/c/ $(FALCOSECURITY_LIBS_CFLAGS)
LDFLAGS = -L/build/src/c/ -lfalcolibs $(FALCOSECURITY_LIBS_LDFLAGS)

cscap: main.o
	$(CXX) $^ -o $@ $(LDFLAGS)

main.o: main.c
	$(CXX) $(CFLAGS) -o $@ -c $^

.PHONY: clean
clean:
	rm -f *.o *.so *.a cscap
