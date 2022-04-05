.PHONY: clean

TARGET=falcolibs

install: $(TARGET)
	go install

$(TARGET):
	go build -x .

clean:
	rm -f *.o *.so *.a $(TARGET)
