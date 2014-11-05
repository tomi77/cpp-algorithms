libutil: util.cpp
	g++ util.cpp -c -O2
	ar rcs libutil.a util.o

clean:
	@rm -f util.o
	@rm -f libutil.a
	cd ./sort && make clean

all: libutil
	cd ./sort && make all

.PHONY: all