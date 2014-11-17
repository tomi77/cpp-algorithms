SRCDIR = src
BINDIR = bin
LIBDIR = lib
CXX = g++
CXXFLAGS = -O2 -Wall -std=c++11 -L$(LIBDIR) -I$(SRCDIR)
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

libcrc32: src/crypto/hash/crc32/crc32.cpp
	@mkdir -p $(LIBDIR)
	$(CXX) $(CXXFLAGS) $^ -c -o $@.o
	$(AR) $(ARFLAGS) $(LIBDIR)/$@.a $@.o
	@rm -f $@.o

crc32: libcrc32 src/crypto/hash/crc32/main.cpp
	@mkdir -p $(BINDIR)
	$(CXX) src/crypto/hash/crc32/main.cpp -o $(BINDIR)/$@ -lcrc32 $(CXXFLAGS)

libtransposition: src/crypto/cipher/transposition/transposition.cpp
	@mkdir -p $(LIBDIR)
	$(CXX) $(CXXFLAGS) $^ -c -o $@.o
	$(AR) $(ARFLAGS) $(LIBDIR)/$@.a $@.o
	@rm -f $@.o

caesar: libtransposition src/crypto/cipher/caesar/main.cpp
	@mkdir -p $(BINDIR)
	$(CXX) src/crypto/cipher/caesar/main.cpp -o $(BINDIR)/$@ -ltransposition $(CXXFLAGS)

librot13: src/crypto/cipher/rot13/rot13.cpp
	@mkdir -p $(LIBDIR)
	$(CXX) $(CXXFLAGS) $^ -c -o $@.o
	$(AR) $(ARFLAGS) $(LIBDIR)/$@.a $@.o
	@rm -f $@.o

rot13: librot13 src/crypto/cipher/rot13/main.cpp
	@mkdir -p $(BINDIR)
	$(CXX) src/crypto/cipher/rot13/main.cpp -o $(BINDIR)/$@ -lrot13 $(CXXFLAGS)

librot47: src/crypto/cipher/rot47/rot47.cpp
	@mkdir -p $(LIBDIR)
	$(CXX) $(CXXFLAGS) $^ -c -o $@.o
	$(AR) $(ARFLAGS) $(LIBDIR)/$@.a $@.o
	@rm -f $@.o

rot47: librot47 src/crypto/cipher/rot47/main.cpp
	@mkdir -p $(BINDIR)
	$(CXX) src/crypto/cipher/rot47/main.cpp -o $(BINDIR)/$@ -lrot47 $(CXXFLAGS)

librot5: src/crypto/cipher/rot5/rot5.cpp
	@mkdir -p $(LIBDIR)
	$(CXX) $(CXXFLAGS) $^ -c -o $@.o
	$(AR) $(ARFLAGS) $(LIBDIR)/$@.a $@.o
	@rm -f $@.o

rot5: librot5 src/crypto/cipher/rot5/main.cpp
	@mkdir -p $(BINDIR)
	$(CXX) src/crypto/cipher/rot5/main.cpp -o $(BINDIR)/$@ -lrot5 $(CXXFLAGS)

librot18: src/crypto/cipher/rot18/rot18.cpp
	@mkdir -p $(LIBDIR)
	$(CXX) $(CXXFLAGS) $^ -c -o $@.o
	$(AR) $(ARFLAGS) $(LIBDIR)/$@.a $@.o
	@rm -f $@.o

rot18: librot18 src/crypto/cipher/rot18/main.cpp
	@mkdir -p $(BINDIR)
	$(CXX) src/crypto/cipher/rot18/main.cpp -o $(BINDIR)/$@ -lrot18 $(CXXFLAGS)

libhorner: src/math/polynomial/horner.cpp
	@mkdir -p $(LIBDIR)
	$(CXX) $(CXXFLAGS) $^ -c -o $@.o
	$(AR) $(ARFLAGS) $(LIBDIR)/$@.a $@.o
	@rm -f $@.o

horner: libhorner src/math/polynomial/main.cpp
	@mkdir -p $(BINDIR)
	$(CXX) src/math/polynomial/main.cpp -o $(BINDIR)/$@ -lhorner $(CXXFLAGS)

clean:
	@rm -f $(LIBDIR)/* $(BINDIR)/*

alllibs: libutil libbsort libisort libqsort libcsort libfib libcrc32 libtransposition libhorner librot5 librot13 librot18 librot47

.PHONY: all
all: bsort isort qsort csort fib crc32 cezar horner rot5 rot13 rot18 rot47