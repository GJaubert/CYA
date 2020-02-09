

calculadora: main.o lenguaje.o
	g++ main.o lenguaje.o -o calculadora

main.o: main.cpp
	g++ -c main.cpp
lenguaje.o: lenguaje.cpp lenguaje.h
	g++ -c lenguaje.cpp
clean:
	rm *.o calculadora
