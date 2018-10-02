run: main.o tree.o
	g++ -o run main.o tree.o
tree.o: tree.cpp tree.h node.h
	g++  -c -Wall -pedantic -g -std=c++11 tree.cpp
main.o: main.cpp tree.cpp 
	g++ -c -Wall -pedantic -g -std=c++11 main.cpp
clean: 
	rm main.o run tree.o
