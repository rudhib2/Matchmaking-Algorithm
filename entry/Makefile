EXENAME = main
TEST = test
OBJS = main.o Graph.o BFS.o Populate.o

CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME) : output_msg $(OBJS)
    $(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

#object file dependncies
main.o : main.cpp Graph.cpp Graph.h BFS.h BFS.cpp Populate.h Populate.cpp
    $(CXX) $(CXXFLAGS) main.cpp

graph.o : Graph.cpp Graph.h 
    $(CXX) $(CXXFLAGS) Graph.cpp

BFS.o : BFS.cpp BFS.h Graph.cpp Graph.h
    $(CXX) $(CXXFLAGS) BFS.cpp 

Populate.o : main.cpp Graph.cpp Graph.h BFS.h BFS.cpp Populate.h Populate.cpp
    $(CXX) $(CXXFLAGS) Populate.cpp


test: output_msg tests.o graph.o utility.o airport.o
    $(LD) tests.o utility.o graph.o airport.o $(LDFLAGS) -o test

tests.o: tests/tests.cpp tests/catch.hpp src/graph.h src/airport.h src/station.h src/utility.h
    $(CXX) $(CXXFLAGS) tests/tests.cpp