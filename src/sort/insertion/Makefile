libisort: isort.cpp
	g++ isort.cpp -c -O2
	ar rcs libisort.a isort.o

all: main.cpp libisort
	g++ main.cpp -o isort -L../.. -L. -lutil -lisort -O2

clean:
	@rm -f isort
	@rm -f isort.exe
	@rm -f isort.app
	@rm -f isort.o
	@rm -f libisort.a

.PHONY: all