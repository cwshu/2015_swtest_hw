CXX = clang++
CXXFLAGS = -std=c++14 -g -Wall
LDFLAGS = -lgtest

all: unittest

run:
	./triangle.out
	./nextdate.out

build: triangle.out nextdate.out 

unittest: CXXFLAGS += -D__UNIT_TEST__
unittest: build

example_use: CXXFLAGS += -D__USAGE_TEST__
example_use: build

%.out: %.cpp
	$(CXX) -o $@ $(CXXFLAGS) $(LDFLAGS) $<

clean:
	rm -f *.out
