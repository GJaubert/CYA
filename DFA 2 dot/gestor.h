/**
  * @file gestor.h
  * @version 1.0
  * @date 29/10/2019
  * @author alu0101240374
  * @brief Lee el fichero y gestiona los elementos.
  */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#pragma once

 class gestor {
   public :
     /** Fichero entrada*/
     std::string filein;
     /** cantidad de simbolos que se va a leer*/
     std::string numerosimbolos;
     /** Simbolos que forman el alfabeto*/
     std::vector<std::string> alfabeto;
     /** Cantidad de estados que se leeran*/
     std::string estados;
     /** Nombre de las etiquetas de los estados*/
     std::vector<std::string> statesname;
     /** Estado de inicio del DFA*/
     std::string inicio;
     /** Numero de estados de aceptacion*/
     std::string numeroaceptacion;
     /** Todos los estados de aceptacion*/
     std::vector<std::string> aceptacion;
     /** Cantidad de transiciones*/
     std::string  numerotransiciones;
     /** Estado de salida de la transicion*/
     std::vector<std::string> salida;
     /** EStado de llegada de la transicion*/
     std::vector<std::string> llegada;
     /** Simbolo que se consume durante la transicion*/
     std::vector<std::string> label;
    /** Constructor con un string como parametro*/
     gestor(std::string in);
     /**
   *@brief Lee el fichero y gestiona lo que lee
   *@param ninguno
   *@return ninguno
   */

     void Read();
 };
