libutil: util.cpp
	g++ util.cpp -c -O2
	ar rcs libutil.a util.o

clean:
	@rm -f util.o
	@rm -f libutil.a
	cd ./bsort && make clean
	cd ./isort && make clean
	cd ./qsort && make clean

all: libutil
	cd ./bsort && make all
	cd ./isort && make all
	cd ./qsort && make all

.PHONY: all