// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 6 CyA - Automatas Finitos Deterministas
// Autor: Gabriel García Jaubert
// Correo: alu0101240374@ull.edu.es
// Fecha: 29/10/2019
// Archivo gestor.cpp: Desarrollamos los metodos de la clase gestor
//                    
//    

#include "gestor.h"

 gestor::gestor(std::string in){
   filein = in;
 }

 void gestor::Read() {
   std::string line;
   std::ifstream fichero;
   fichero.open(filein);
   if (!fichero.is_open()) {
     exit(EXIT_FAILURE); 
   }
   while(getline(fichero,line)) {
     if ((line[0] == '/') && (line[1] == '/')) {
       continue;
     }
     if ((line[0] != '/')||(line[1] != '/')) {
       numerosimbolos = line;
       break;
     }
   }
   int x = stoi(numerosimbolos);
   for (int i = 0; i < x; i++) {
     getline(fichero,line); 
     alfabeto.push_back(line);
   }
   getline(fichero,estados);
   x = stoi(estados);
   for (int i = 0; i < x; i++) {
     getline(fichero,line);
     statesname.push_back(line);
   }
   getline(fichero,inicio);
   getline(fichero,numeroaceptacion);
   x = stoi(numeroaceptacion);
   for (int i = 0; i < x; i++) {
     getline(fichero,line);
     aceptacion.push_back(line);
   }
   getline(fichero,numerotransiciones);
   x = stoi(numerotransiciones);
   for (int i = 0; i < x; i++) { 
     fichero >> line;
     salida.push_back(line);
     fichero >> line;
     label.push_back(line);
     fichero >> line;
     llegada.push_back(line);
   }
 }
