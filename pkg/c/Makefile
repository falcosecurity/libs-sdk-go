.PHONY: clean

libfalcolibs.a: libs.o event.o threadinfo.o fdinfo.o
	ar r $@ $^

%.o: %.cpp
	g++ -D_GNU_SOURCE -DHAS_CAPTURE --std=c++0x -O3 -DNDEBUG -o $@ -c $^ $(FALCOSECURITY_LIBS_CFLAGS)

clean:
	rm -f *.o *.so *.a $(TARGET)
