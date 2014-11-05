libbsort: bsort.cpp
	g++ bsort.cpp -c -O2
	ar rcs libbsort.a bsort.o

all: main.cpp libbsort
	g++ main.cpp -o bsort -L.. -L. -lutil -lbsort -O2

clean:
	@rm -f bsort
	@rm -f bsort.exe
	@rm -f bsort.app
	@rm -f bsort.o
	@rm -f libbsort.a

.PHONY: all