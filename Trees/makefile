#!make -f

# CXX=clang++-6.0
# CXXFLAGS=-std=c++17

all: a.out
	./a.out



a.out: TreeTest.o Tree.o Node.o
	clang++-5.0 -std=c++17 TreeTest.o Tree.o Node.o

Node.o: Node.cpp Node.hpp
	clang++-5.0 -std=c++17 --compile Node.cpp -o Node.o

Tree.o: Tree.cpp Tree.hpp Node.hpp
	clang++-5.0 -std=c++17 --compile Tree.cpp -o Tree.o

TreeTest.o: TreeTest.cpp Tree.hpp Node.hpp
	clang++-5.0 -std=c++17 --compile TreeTest.cpp -o TreeTest.o



clean:
	rm -f *.o a.out

