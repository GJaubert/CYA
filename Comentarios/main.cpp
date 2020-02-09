// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 4 CyA - Eliminador de comentarios
// Autor: Gabriel García Jaubert
// Correo: alu0101240374@ull.edu.es
// Fecha: 15/10/2019
// Archivo main.cpp: El main se orden de gestionar 
// 		     los argumentos que recibe y 
// 		     empezar 
//                       


#include "ES.h"

 int main (int argc, char* argv[]) {
  if ((argc == 1) || (argc == 2)) {
    std::cout << "Introduzca los archivos así: ./Ejecutable filein fileout\n";
  } else {
      ES frase;
      frase.fRead(argv[1],argv[2]);
    }
 }
