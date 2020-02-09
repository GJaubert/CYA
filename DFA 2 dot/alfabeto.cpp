// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 6 CyA - Automatas Finitos Deterministas
// Autor: Gabriel García Jaubert
// Correo: alu0101240374@ull.edu.es
// Fecha: 29/10/2019
// Archivo alfabeto.cpp: Desarrollamos los metodos de la clase alfabeto 
// 		      
//                    

#include "alfabeto.h"

alfabeto::alfabeto(){}

alfabeto::alfabeto(std::string in, std::vector<std::string> vectorin){
  numerodesimbolos = in;
  for(int i = 0; i < vectorin.size(); i++) {
    simbolos.push_back(vectorin[i]);
  }
}

void alfabeto::CreateAlfabeto(std::string in, std::vector<std::string> vectorin){
  numerodesimbolos = in;
  for(int i = 0; i < vectorin.size(); i++) {
    simbolos.push_back(vectorin[i]);
  }
}
