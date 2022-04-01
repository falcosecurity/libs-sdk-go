.PHONY: clean

libs.a: libs.o event.o threadinfo.o fdinfo.o
	ar r $@ $^

%.o: %.cpp
	g++ -std=c++11 -O3 -o $@ -c $^ -I/usr/include/falcosecurity/ -I/usr/include/falcosecurity/userspace/libsinsp -I/usr/include/falcosecurity/userspace/libscap

clean:
	rm -f *.o *.so *.a $(TARGET)
