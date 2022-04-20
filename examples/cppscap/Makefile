
#
# FALCOSECURITY_LIBS_CFLAGS and FALCOSECURITY_LIBS_LDFLAGS are environment variables
# defined in the libs builder image currently hosted in ghcr.io/sysflow-telemetry/libs/libs
#
CXX = g++
CFLAGS = -D_GNU_SOURCE -DHAS_CAPTURE -Wall -DNDEBUG $(FALCOSECURITY_LIBS_CFLAGS)
LDFLAGS = $(FALCOSECURITY_LIBS_LDFLAGS)

cppscap: main.o
	$(CXX) $^ -o $@ $(LDFLAGS)

main.o: main.cpp
	$(CXX) $(CFLAGS) -o $@ -c $^

.PHONY: clean
clean:
	rm -f *.o *.so *.a cppscap
