// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 4 CyA - Eliminador de comentarios
// Autor: Gabriel García Jaubert
// Correo: alu0101240374@ull.edu.es
// Fecha: 15/10/2019
// Archivo ES.h: Aqui declaramos la clase ES(Entrada/Salida)
//                    
//                    
//   


#include "automata.h"

 class ES {
   public:
     std::string str;
     ES();
     void fRead(std::string entrada, std::string out);
     void fWrite(std::string salida);
 };
