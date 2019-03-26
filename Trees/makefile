#!make -f

test: TreeTest.o Tree.o Node.o
	clang++-6.0 -std=c++17 $^ -o test

%.o: %.cpp
	clang++-6.0 -std=c++17 --compile $< -o $@

TreeTest.o: badkan.hpp Tree.hpp Node.hpp

clean:
	rm -f *.o demo test
