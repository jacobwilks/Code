run: calc.o list.o 
	g++ -o run calc.o list.o
list.o: list.cpp list.h  node.h
	g++ -c -Wall -pedantic -g -std=c++11 list.cpp
calc.o: calc.cpp list.h stack.h node.h 
	g++ -c -Wall -pedantic -g -std=c++11 calc.cpp
clean: 
	rm calc.o student.o list.o run
