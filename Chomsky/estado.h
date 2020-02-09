/**
  * @file estado.h
  * @version 1.0
  * @date 20/11/2019
  * @author alu0101240374
  * @brief Esta clase es usada para guardar todo lo referente a los estados.
  */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#pragma once

 class estado {
   public:
    /** Nombre del estado*/
     std::string etiqueta;
    /** Simbolos con los que transita*/ 
     std::vector<std::string> label;
    /** Estados a los que transita*/ 
     std::vector<std::string> destino;
    /** Si ha sido visitado en el algoritmo eClausura*/
     bool epsilonvisitado = false;
    /** Si ha sido visitado en el algoritmo Move*/ 
     bool movevisitado = false;
    /** Si el estado es de aceptacion*/ 
     bool aceptacion = false; 
    /** Constructor predeterminado*/ 
     estado();
    /** Constructor con un string para la etiqueta */ 
     estado(std::string line);
 };
