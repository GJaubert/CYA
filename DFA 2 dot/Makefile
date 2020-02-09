

DFA2dot: main.o DFA.o alfabeto.o estado.o transicion.o gestor.o DFAWriter.o
	g++ main.o DFA.o alfabeto.o estado.o transicion.o gestor.o DFAWriter.o -o DFA2dot

main.o: main.cpp
	g++ -c main.cpp
DFA.o: DFA.cpp
	g++ -c DFA.cpp
transicion.o: transicion.cpp
	g++ -c transicion.cpp
alfabeto.o: alfabeto.cpp
	g++ -c alfabeto.cpp
estado.o: estado.cpp
	g++ -c estado.cpp	
gestor.o: gestor.cpp gestor.h	
	g++ -c gestor.cpp
DFAWriter.o: DFAWriter.cpp DFAWriter.h
	g++ -c DFAWriter.cpp
clean:
	rm *.o DFA2dot
