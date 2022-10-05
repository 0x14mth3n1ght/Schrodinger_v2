HEADERS=$(wildcard *.h)

all: CXX

CXX: $(HEADERS)
	./cxxtest-4.4/bin/cxxtestgen --error-printer -o tests.cpp $^

