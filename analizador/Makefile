

Set: main.o set.o
	g++ main.o set.o -o Set

main.o: main.cpp
	g++ -c main.cpp
set.o: set.cpp set.h
	g++ -c set.cpp
clean:
	rm *.o Set
