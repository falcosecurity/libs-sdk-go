.PHONY: clean

libsysdig.a: sysdig.o event.o threadinfo.o fdinfo.o
	ar r $@ $^

%.o: %.cpp
	g++ -std=c++11 -O3 -o $@ -c $^ -I../../sysdig-0.23.0/userspace/libsinsp/ -I../../sysdig-0.23.0/userspace/libscap/ -I../../sysdig-0.23.0/userspace/libsinsp/third-party/jsoncpp/

clean:
	rm -f *.o *.so *.a $(TARGET)
