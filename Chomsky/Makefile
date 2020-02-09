

G2CNF: regprod.o transicion.o G2CNF.o NFA.o alfabeto.o estado.o grammar.o
	g++ regprod.o transicion.o G2CNF.o NFA.o alfabeto.o estado.o grammar.o -o G2CNF

G2CNF.o: G2CNF.cpp
	g++ -c G2CNF.cpp
NFA.o: NFA.cpp NFA.h
	g++ -c NFA.cpp
grammar.o: grammar.cpp grammar.h
	g++ -c grammar.cpp
alfabeto.o: alfabeto.cpp alfabeto.h
	g++ -c alfabeto.cpp
estado.o: estado.cpp estado.h
	g++ -c estado.cpp
transicion.o: transicion.cpp transicion.h
	g++ -c transicion.cpp
regprod.o: regprod.cpp regprod.h
	g++ -c regprod.cpp
clean:
	rm *.o G2CNF
