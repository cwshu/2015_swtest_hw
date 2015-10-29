CXX = clang++
CXXFLAGS = -std=c++14 -g -Wall
LDFLAGS = -lgtest

all: triangle.out nextdate.out

%.out: %.cpp
	$(CXX) -o $@ $(CXXFLAGS) $(LDFLAGS) $<

clean:
	rm -f *.out
