// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 7 CyA - Algoritmo de Creacion de Subconjuntos
// Autor: Gabriel García Jaubert
// Correo: alu0101240374@ull.edu.es
// Fecha: 05/11/2019
// Archivo estado.cpp: Desarrollamos los metodos de la clase estado
//                    
//    

#include "estado.h"
 
 estado::estado(){}
 estado::estado(std::string line){
   etiqueta = line;
 }
