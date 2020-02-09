// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 3 CyA - Calculadora para lenguajes formales
// Autor: Gabriel García Jaubert
// Correo: alu0101240374@ull.edu.es
// Fecha: 08/10/2019
// Archivo lenguaje.h: Describe la clase "Lenguaje". Esta consta de un set de strings
// 		       como atributo y como metodos los necesarios para leer y escribir
// 		       y los que se piden en la práctica para operar.
//                    


#include <set>
#include <fstream>
#include <cmath>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <assert.h>
 class Lenguaje {
   public:
     std::set<std::string> lenguaje;
     Lenguaje(std::string cadena);
     Lenguaje();
        
     void fRead(std::string entrada, std::string salida, 
		std::vector<Lenguaje> &almacen);	
     Lenguaje Concatenacion(Lenguaje& B);
     void fWrite(std::string out, std::vector<Lenguaje> almacen);
     void WriteSet(std::string out);
     Lenguaje Union(Lenguaje B);
     Lenguaje Interseccion(Lenguaje& B);
     bool Iguales(Lenguaje& B);
     Lenguaje Diferencia(Lenguaje& B);
     bool Sublenguaje(Lenguaje B);
     Lenguaje Potencia(std::string n);
     Lenguaje Inversa();
     void fWriteInfinito(std::string out);
     void Kleene(std::string out);
     void Positivo(std::string out);
     void WriteBool(int n, int m, std::string out);
 };
