CC = g++
CFLAGS = -std=c++11

all: release

main.o: main.cpp
	${CC} ${CFLAGS} -c main.cpp

release: main.o
	${CC} ${CFLAGS} -o main main.o

clean:
	rm -f main *.o
