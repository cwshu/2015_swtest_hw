# usage:
#   make clean all         # build library unittest.
#   make clean example_use # build library example usage.
#   make clean all run cov # build library unittest, running test, and compute test coverage.
#
# only generate report of single program, use them after `make all run`
#   make triangle_cov
#   make nextdate_cov

CXX = clang++
CXXFLAGS = -std=c++14 -g -Wall -fprofile-arcs -ftest-coverage
LDFLAGS = -lgtest -lgcov

GCOV = llvm-cov gcov

all: unittest

triangle_cov:
	$(GCOV) -abc triangle.cpp

nextdate_cov:
	$(GCOV) -abc nextdate.cpp

cov:
	$(GCOV) triangle.cpp
	mv triangle.cpp.gcov triangle.cpp.line.gcov
	$(GCOV) -ab triangle.cpp
	mv triangle.cpp.gcov triangle.cpp.ab.gcov
	$(GCOV) -abc triangle.cpp
	mv triangle.cpp.gcov triangle.cpp.abc.gcov
	$(GCOV) nextdate.cpp
	mv nextdate.cpp.gcov nextdate.cpp.line.gcov
	$(GCOV) -ab nextdate.cpp
	mv nextdate.cpp.gcov nextdate.cpp.ab.gcov
	$(GCOV) -abc nextdate.cpp
	mv nextdate.cpp.gcov nextdate.cpp.abc.gcov

run:
	./triangle.out
	./nextdate.out

build: triangle.out nextdate.out 

unittest: CXXFLAGS += -D__UNIT_TEST__
unittest: build

example_use: CXXFLAGS += -D__USAGE_TEST__
example_use: build

%.out: %.cpp %_test.cpp
	$(CXX) -o $@ $(CXXFLAGS) $(LDFLAGS) $^

clean:
	rm -f *.out *.gcno *.gcda *.gcov
