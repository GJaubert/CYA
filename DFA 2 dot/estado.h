/**
  * @file estado.h
  * @version 1.0
  * @date 29/10/2019
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
     std::string numberofstates;
  /** Vector que almacena estados*/
     std::vector<std::string> states;
  /** Estado de inicio*/
     std::string start;
  /** Cantidad de estados de aceptacion*/
     std::string numeroaceptacion;
  /** Vector que almacena todos los de aceptacion*/
     std::vector<std::string> aceptacion;
  /** Constructor con un string y un vector de string*/
     estado(std::string strin, std::vector<std::string> vectorin);
  /** Constructor predeterminado*/
     estado();
  /**
   *@brief Crea un vector de estados y guarda su tamaño
   *@param strin Cantidad de estados, vectorin Vector con los estados
   *@return ninguno
   */
     void CreateEstado(std::string strin, std::vector<std::string> vectorin);
 };
