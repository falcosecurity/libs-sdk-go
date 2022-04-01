.PHONY: clean

TARGET=libs

FLAGS="-I/usr/include/falcosecurity/ -I/usr/include/falcosecurity/userspace/libsinsp -I/usr/include/falcosecurity/userspace/libscap"

$(TARGET):
	go build -x .

clean:
	rm -f *.o *.so *.a $(TARGET)
