CC = g++
CPPFLAGS = -I. -g
main: main.o Node.o
main.o: main.cpp main.h Node.h point.h
Node.o: Node.cpp Node.h
clean:
	rm main
	rm *.o
