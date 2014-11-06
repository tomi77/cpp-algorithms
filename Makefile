SRCDIR = src
BINDIR = bin
LIBDIR = lib
CXX = g++
CXXFLAGS = -O2 -Wall -L$(LIBDIR) -I$(SRCDIR)
AR = ar
ARFLAGS = rcs

libutil: src/util.cpp
	@mkdir -p $(LIBDIR)
	$(CXX) $(CXXFLAGS) $^ -c
	$(AR) $(ARFLAGS) $(LIBDIR)/$@.a util.o
	@rm -f util.o

libbsort: src/sort/bubble/bsort.cpp
	@mkdir -p $(LIBDIR)
	$(CXX) $(CXXFLAGS) $^ -c
	$(AR) $(ARFLAGS) $(LIBDIR)/$@.a bsort.o
	@rm -f bsort.o

bsort: libutil libbsort src/sort/bubble/main.cpp
	@mkdir -p $(BINDIR)
	$(CXX) src/sort/bubble/main.cpp -o $(BINDIR)/$@ -lutil -lbsort $(CXXFLAGS)

libisort: src/sort/insertion/isort.cpp
	@mkdir -p $(LIBDIR)
	$(CXX) $(CXXFLAGS) $^ -c
	$(AR) $(ARFLAGS) $(LIBDIR)/$@.a isort.o
	@rm -f isort.o

isort: libutil libisort src/sort/insertion/main.cpp
	@mkdir -p $(BINDIR)
	$(CXX) src/sort/insertion/main.cpp -o $(BINDIR)/$@ -lutil -lisort $(CXXFLAGS)

libqsort: src/sort/quick/qsort.cpp
	@mkdir -p $(LIBDIR)
	$(CXX) $(CXXFLAGS) $^ -c
	$(AR) $(ARFLAGS) $(LIBDIR)/$@.a qsort.o
	@rm -f qsort.o

qsort: libutil libqsort src/sort/quick/main.cpp
	@mkdir -p $(BINDIR)
	$(CXX) src/sort/quick/main.cpp -o $(BINDIR)/$@ -lutil -lqsort $(CXXFLAGS)

libcsort: src/sort/counting/csort.cpp
	@mkdir -p $(LIBDIR)
	$(CXX) $(CXXFLAGS) $^ -c
	$(AR) $(ARFLAGS) $(LIBDIR)/$@.a csort.o
	@rm -f csort.o

csort: libutil libcsort src/sort/counting/main.cpp
	@mkdir -p $(BINDIR)
	$(CXX) src/sort/counting/main.cpp -o $(BINDIR)/$@ -lutil -lcsort $(CXXFLAGS)

clean:
	@rm -f $(LIBDIR)/* $(BINDIR)/*

.PHONY: all
all: libutil libbsort bsort libisort isort libqsort qsort libcsort csort