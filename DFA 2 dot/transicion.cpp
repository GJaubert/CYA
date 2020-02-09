// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 6 CyA - Automatas Finitos Deterministas
// Autor: Gabriel García Jaubert
// Correo: alu0101240374@ull.edu.es
// Fecha: 29/10/2019
// Archivo transicion.cpp: Desarrollamos los metodos de la clase transicion 
//                    
//    

#include "transicion.h"

transicion::transicion(std::string str1, std::string str2, std::string str3){
  salida = str1;
  label = str2;
  destino = str3;
}
