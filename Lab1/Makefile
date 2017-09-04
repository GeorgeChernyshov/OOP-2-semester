all: main
main: ./bin/Lab1.o
	g++ ./bin/Lab1.o -o main
bin/Lab1.o: ./src/Lab1.cpp ./include/stdafx.h
	mkdir bin
	g++ -std=c++14 -Wextra -Werror -Wall ./src/Lab1.cpp -c -o ./bin/Lab1.o -I ./include
clean:
	rm -rf ./bin
