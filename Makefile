rpn: main.o Operation.o
	mkdir -p out
	g++ -std=c++23 -o out/rpn build/main.o build/Operation.o

main.o:
	mkdir -p build
	g++ -std=c++23 -o build/main.o -c src/main.cpp

Operation.o:
	mkdir -p build
	g++ -std=c++23 -o build/Operation.o -c src/Operation.cpp