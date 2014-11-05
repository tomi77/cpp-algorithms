libqsort: qsort.cpp
	g++ qsort.cpp -c -O2
	ar rcs libqsort.a qsort.o

all: main.cpp libqsort
	g++ main.cpp -o qsort -L.. -L. -lutil -lqsort -O2

clean:
	@rm -f qsort
	@rm -f qsort.exe
	@rm -f qsort.app
	@rm -f qsort.o
	@rm -f libqsort.a

.PHONY: all