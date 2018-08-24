.PHONY: clean

TARGET=go-sysdig

FLAGS="-I/home/terylt/sysdig/sysdig-0.23.0/userspace/libsinsp/ -I/home/terylt/sysdig/sysdig-0.23.0/userspace/libscap/ -I/home/terylt/sysdig/sysdig-0.23.0/userspace/libsinsp/third-party/jsoncpp/"

$(TARGET): 
	go build -x .

clean:
	rm -f *.o *.so *.a $(TARGET)
