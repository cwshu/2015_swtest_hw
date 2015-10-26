CXX = clang++
CXXFLAGS = -std=c++11 -g
LDFLAGS = -lgtest

all: triangle.out

%.out: %.cpp
	$(CXX) -o $@ $(CXXFLAGS) $(LDFLAGS) $<

clean:
	rm -f *.out
