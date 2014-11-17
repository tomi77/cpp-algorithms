SRCDIR = src
BINDIR = bin
LIBDIR = lib
CXX = g++
CXXFLAGS = -O2 -Wall -std=c++11 -L$(LIBDIR) -I$(SRCDIR) -I$(SRCDIR)/crypto
AR = ar
ARFLAGS = rcs

libutil: src/util.cpp
	@mkdir -p $(LIBDIR)
	$(CXX) $(CXXFLAGS) $^ -c -o $@.o
	$(AR) $(ARFLAGS) $(LIBDIR)/$@.a $@.o
	@rm -f $@.o

libsort: src/sort.cpp
	@mkdir -p $(LIBDIR)
	$(CXX) $(CXXFLAGS) $^ -c -o $@.o
	$(AR) $(ARFLAGS) $(LIBDIR)/$@.a $@.o
	@rm -f $@.o

bsort: libutil libsort src/sort/bsort.cpp
	@mkdir -p $(BINDIR)
	$(CXX) src/sort/bsort.cpp -o $(BINDIR)/$@ -lutil -lsort $(CXXFLAGS)

isort: libutil libsort src/sort/isort.cpp
	@mkdir -p $(BINDIR)
	$(CXX) src/sort/isort.cpp -o $(BINDIR)/$@ -lutil -lsort $(CXXFLAGS)

qsort: libutil libsort src/sort/qsort.cpp
	@mkdir -p $(BINDIR)
	$(CXX) src/sort/qsort.cpp -o $(BINDIR)/$@ -lutil -lsort $(CXXFLAGS)

csort: libutil libsort src/sort/csort.cpp
	@mkdir -p $(BINDIR)
	$(CXX) src/sort/csort.cpp -o $(BINDIR)/$@ -lutil -lsort $(CXXFLAGS)

libfib: src/fib/fib.cpp
	@mkdir -p $(LIBDIR)
	$(CXX) $(CXXFLAGS) $^ -c -o $@.o
	$(AR) $(ARFLAGS) $(LIBDIR)/$@.a $@.o
	@rm -f $@.o

fib: libfib src/fib/main.cpp
	@mkdir -p $(BINDIR)
	$(CXX) src/fib/main.cpp -o $(BINDIR)/$@ -lfib $(CXXFLAGS)

libhash: src/crypto/hash.cpp
	@mkdir -p $(LIBDIR)
	$(CXX) $(CXXFLAGS) $^ -c -o $@.o
	$(AR) $(ARFLAGS) $(LIBDIR)/$@.a $@.o
	@rm -f $@.o

crc32: libhash src/crypto/hash/crc32.cpp
	@mkdir -p $(BINDIR)
	$(CXX) src/crypto/hash/crc32.cpp -o $(BINDIR)/$@ -lhash $(CXXFLAGS)

libcipher: src/crypto/cipher.cpp
	@mkdir -p $(LIBDIR)
	$(CXX) $(CXXFLAGS) $^ -c -o $@.o
	$(AR) $(ARFLAGS) $(LIBDIR)/$@.a $@.o
	@rm -f $@.o

caesar: libcipher src/crypto/cipher/caesar.cpp
	@mkdir -p $(BINDIR)
	$(CXX) src/crypto/cipher/caesar.cpp -o $(BINDIR)/$@ -lcipher $(CXXFLAGS)

rot13: libcipher src/crypto/cipher/rot13.cpp
	@mkdir -p $(BINDIR)
	$(CXX) src/crypto/cipher/rot13.cpp -o $(BINDIR)/$@ -lcipher $(CXXFLAGS)

rot47: libcipher src/crypto/cipher/rot47.cpp
	@mkdir -p $(BINDIR)
	$(CXX) src/crypto/cipher/rot47.cpp -o $(BINDIR)/$@ -lcipher $(CXXFLAGS)

rot5: libcipher src/crypto/cipher/rot5.cpp
	@mkdir -p $(BINDIR)
	$(CXX) src/crypto/cipher/rot5.cpp -o $(BINDIR)/$@ -lcipher $(CXXFLAGS)

rot18: libcipher src/crypto/cipher/rot18.cpp
	@mkdir -p $(BINDIR)
	$(CXX) src/crypto/cipher/rot18.cpp -o $(BINDIR)/$@ -lcipher $(CXXFLAGS)

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

alllibs: libutil libsort libfib libhash libhorner libcipher

.PHONY: all
all: bsort isort qsort csort fib crc32 caesar horner rot5 rot13 rot18 rot47