FLAGS = -Werror

main.exe: main.o util.o add.o list.o del.o exit.o get.o
	g++ -o main.exe main.o util.o add.o list.o del.o exit.o get.o

main.o: main.cpp database.h
	g++ ${FLAGS} -c main.cpp

util.o: util.cpp
	g++ ${FLAGS} -c util.cpp

add.o: add.cpp database.h
	g++ ${FLAGS} -c add.cpp

list.o: list.cpp database.h
	g++ ${FLAGS} -c list.cpp

del.o: del.cpp database.h
	g++ ${FLAGS} -c del.cpp

exit.o: exit.cpp database.h
	g++ ${FLAGS} -c exit.cpp

get.o: get.cpp database.h
	g++ ${FLAGS} -c get.cpp

clean:
	rm -rf *.o main.exe