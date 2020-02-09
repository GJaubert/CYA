 /**
   * @file transicion.h
   * @version 1.0
   * @date 20/11/2019
   * @author alu0101240374
   * @brief Guardamos las transiciones: estado inicio, label y estado destino.
   */


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#pragma once

 class transicion {
   public:
  /** Estado de salida*/
   std::string salida;
  /** Label*/
   std::string label;
  /** Estado destino*/
   std::string destino;
  /** Constructor con parametros: inicio, label, destino*/
   transicion();
 };
