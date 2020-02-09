 /**
   * @file transicion.h
   * @version 1.0
   * @date 29/10/2019
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
  /** Cantidad de transiciones que hay*/
   std::string cantidadtransiciones;
  /** Estado de salida*/
   std::string salida;
  /** Label*/
   std::string label;
  /** Estado destino*/
   std::string destino;
  /** Constructor con parametros: inicio, label, destino*/
   transicion(std::string str1, std::string str2, std::string str3);
  /** Constructor predeterminado*/
   transicion();
};
