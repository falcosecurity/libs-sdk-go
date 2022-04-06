.PHONY: clean

libfalcolibs.a: libs.o event.o threadinfo.o fdinfo.o
	ar r $@ $^

%.o: %.cpp
	g++ -D_GNU_SOURCE -DHAS_CAPTURE --std=c++0x -O3 -DNDEBUG -o $@ -c $^ -I/usr/include/falcosecurity/ -I/usr/include/falcosecurity/userspace/libsinsp -I/usr/include/falcosecurity/userspace/libscap

clean:
	rm -f *.o *.so *.a $(TARGET)
