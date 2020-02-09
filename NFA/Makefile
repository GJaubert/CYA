

NFA2DFA: NFA2DFA.o NFA.o alfabeto.o estado.o transicion.o
	g++ NFA2DFA.o NFA.o alfabeto.o estado.o transicion.o -o NFA2DFA

NFA2DFA.o: NFA2DFA.cpp
	g++ -c NFA2DFA.cpp
NFA.o: NFA.cpp NFA.h
	g++ -c NFA.cpp
transicion.o: transicion.cpp transicion.h
	g++ -c transicion.cpp
alfabeto.o: alfabeto.cpp alfabeto.h
	g++ -c alfabeto.cpp
estado.o: estado.cpp estado.h
	g++ -c estado.cpp	
clean:
	rm *.o NFA2DFA
