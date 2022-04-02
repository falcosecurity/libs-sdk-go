.PHONY: clean

TARGET=falcolibs

FLAGS="-I/usr/include/falcosecurity/ -I/usr/include/falcosecurity/userspace/libsinsp -I/usr/include/falcosecurity/userspace/libscap"

install: $(TARGET)
	go install

$(TARGET):
	go build -x .

clean:
	rm -f *.o *.so *.a $(TARGET)
