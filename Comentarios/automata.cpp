// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 4 CyA - Eliminador de comentarios
// Autor: Gabriel García Jaubert
// Correo: alu0101240374@ull.edu.es
// Fecha: 15/10/2019
// Archivo automata.cpp: Desarrollamos los metodos de la clase automata 
//                      
//                    
//                    
// 

#include "automata.h"
#include "estado.h"

//Constructor con contador = 0
 automata::automata() {
   i = 0;
 } 

//funcion que comienza el analisis
 void automata::Simular(std::string inlinea) {
   line = inlinea;
   //objeto que invoca metodode clase estado   
   Estado inicio;  
   inicio.StateNone(*this,i);
   line = inicio.linefinal;
   carry = inicio.aux; 
 }
