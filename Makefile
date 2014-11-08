SRCDIR = src
BINDIR = bin
LIBDIR = lib
CXX = g++
CXXFLAGS = -O2 -Wall -L$(LIBDIR) -I$(SRCDIR)
AR = ar
ARFLAGS = rcs

libutil: src/util.cpp
	@mkdir -p $(LIBDIR)
	$(CXX) $(CXXFLAGS) $^ -c -o $@.o
	$(AR) $(ARFLAGS) $(LIBDIR)/$@.a $@.o
	@rm -f $@.o

libbsort: src/sort/bubble/bsort.cpp
	@mkdir -p $(LIBDIR)
	$(CXX) $(CXXFLAGS) $^ -c -o $@.o
	$(AR) $(ARFLAGS) $(LIBDIR)/$@.a $@.o
	@rm -f $@.o

bsort: libutil libbsort src/sort/bubble/main.cpp
	@mkdir -p $(BINDIR)
	$(CXX) src/sort/bubble/main.cpp -o $(BINDIR)/$@ -lutil -lbsort $(CXXFLAGS)

libisort: src/sort/insertion/isort.cpp
	@mkdir -p $(LIBDIR)
	$(CXX) $(CXXFLAGS) $^ -c -o $@.o
	$(AR) $(ARFLAGS) $(LIBDIR)/$@.a $@.o
	@rm -f $@.o

isort: libutil libisort src/sort/insertion/main.cpp
	@mkdir -p $(BINDIR)
	$(CXX) src/sort/insertion/main.cpp -o $(BINDIR)/$@ -lutil -lisort $(CXXFLAGS)

libqsort: src/sort/quick/qsort.cpp
	@mkdir -p $(LIBDIR)
	$(CXX) $(CXXFLAGS) $^ -c -o $@.o
	$(AR) $(ARFLAGS) $(LIBDIR)/$@.a $@.o
	@rm -f $@.o

qsort: libutil libqsort src/sort/quick/main.cpp
	@mkdir -p $(BINDIR)
	$(CXX) src/sort/quick/main.cpp -o $(BINDIR)/$@ -lutil -lqsort $(CXXFLAGS)

libcsort: src/sort/counting/csort.cpp
	@mkdir -p $(LIBDIR)
	$(CXX) $(CXXFLAGS) $^ -c -o $@.o
	$(AR) $(ARFLAGS) $(LIBDIR)/$@.a $@.o
	@rm -f $@.o

csort: libutil libcsort src/sort/counting/main.cpp
	@mkdir -p $(BINDIR)
	$(CXX) src/sort/counting/main.cpp -o $(BINDIR)/$@ -lutil -lcsort $(CXXFLAGS)

libfib: src/fib/fib.cpp
	@mkdir -p $(LIBDIR)
	$(CXX) $(CXXFLAGS) $^ -c -o $@.o
	$(AR) $(ARFLAGS) $(LIBDIR)/$@.a $@.o
	@rm -f $@.o

fib: libfib src/fib/main.cpp
	@mkdir -p $(BINDIR)
	$(CXX) src/fib/main.cpp -o $(BINDIR)/$@ -lfib $(CXXFLAGS)

libcrc32: src/hash/crc32/crc32.cpp
	@mkdir -p $(LIBDIR)
	$(CXX) $(CXXFLAGS) $^ -c -o $@.o
	$(AR) $(ARFLAGS) $(LIBDIR)/$@.a $@.o
	@rm -f $@.o

crc32: libcrc32 src/hash/crc32/main.cpp
	@mkdir -p $(BINDIR)
	$(CXX) src/hash/crc32/main.cpp -o $(BINDIR)/$@ -lcrc32 $(CXXFLAGS)

clean:
	@rm -f $(LIBDIR)/* $(BINDIR)/*

.PHONY: all
all: libutil libbsort bsort libisort isort libqsort qsort libcsort csort libfib fib