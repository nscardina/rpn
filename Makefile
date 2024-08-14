rpn: main.o Operation.o
	g++ -std=c++23 -o rpn build/main.o build/Operation.o

main.o:
	g++ -std=c++23 -o build/main.o -c src/main.cpp

Operation.o:
	g++ -std=c++23 -o build/Operation.o -c src/Operation.cpp