CXX = g++
CXXFLAGS = -O2 -Wall -Llibs -Isrc
AR = ar
ARFLAGS = rcs

libutil: src/util.cpp
	@mkdir -p libs
	$(CXX) $(CXXFLAGS) $^ -c
	$(AR) $(ARFLAGS) libs/$@.a util.o
	@rm -f util.o

libbsort: src/sort/bubble/bsort.cpp
	@mkdir -p libs
	$(CXX) $(CXXFLAGS) $^ -c
	$(AR) $(ARFLAGS) libs/$@.a bsort.o
	@rm -f bsort.o

bsort: libutil libbsort src/sort/bubble/main.cpp
	@mkdir -p bin
	$(CXX) src/sort/bubble/main.cpp -o bin/$@ -lutil -lbsort $(CXXFLAGS)

libisort: src/sort/insertion/isort.cpp
	@mkdir -p libs
	$(CXX) $(CXXFLAGS) $^ -c
	$(AR) $(ARFLAGS) libs/$@.a isort.o
	@rm -f isort.o

isort: libutil libisort src/sort/insertion/main.cpp
	@mkdir -p bin
	$(CXX) src/sort/insertion/main.cpp -o bin/$@ -lutil -lisort $(CXXFLAGS)

libqsort: src/sort/quick/qsort.cpp
	@mkdir -p libs
	$(CXX) $(CXXFLAGS) $^ -c
	$(AR) $(ARFLAGS) libs/$@.a qsort.o
	@rm -f qsort.o

qsort: libutil libqsort src/sort/quick/main.cpp
	@mkdir -p bin
	$(CXX) src/sort/quick/main.cpp -o bin/$@ -lutil -lqsort $(CXXFLAGS)

libcsort: src/sort/counting/csort.cpp
	@mkdir -p libs
	$(CXX) $(CXXFLAGS) $^ -c
	$(AR) $(ARFLAGS) libs/$@.a csort.o
	@rm -f csort.o

csort: libutil libcsort src/sort/counting/main.cpp
	@mkdir -p bin
	$(CXX) src/sort/counting/main.cpp -o bin/$@ -lutil -lcsort $(CXXFLAGS)

clean:
	@rm -f libs/* bin/*

.PHONY: all
all: libutil libbsort bsort libisort isort libqsort qsort libcsort csort