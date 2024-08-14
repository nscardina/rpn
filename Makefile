CC = g++
override ARGS := -std=c++23

rpn: main.o Operation.o
	mkdir -p out
	$(CC) $(ARGS) -o out/rpn build/main.o build/Operation.o

main.o:
	mkdir -p build
	$(CC) $(ARGS) -o build/main.o -c src/main.cpp

Operation.o:
	mkdir -p build
	$(CC) $(ARGS) -o build/Operation.o -c src/Operation.cpp