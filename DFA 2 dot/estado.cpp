// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 6 CyA - Automatas Finitos Deterministas
// Autor: Gabriel García Jaubert
// Correo: alu0101240374@ull.edu.es
// Fecha: 29/10/2019
// Archivo estado.cpp: Desarrollamos los metodos de la clase estado
//                    
//    

#include "estado.h"

estado::estado(){}

estado::estado(std::string strin, std::vector<std::string> vectorin){
  numberofstates = strin;
  for (int i = 0; i < vectorin.size(); i++){
  states.push_back(vectorin[i]);
  }
}

void estado::CreateEstado(std::string strin, std::vector<std::string> vectorin){
  numberofstates = strin;
  for (int i = 0; i < vectorin.size(); i++){
    states.push_back(vectorin[i]);
  }
}
