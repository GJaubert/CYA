/**
  * @file estado.h
  * @version 1.0
  * @date 20/11/2019
  * @author alu0101240374
  * @brief Esta clase es usada para guardar todo lo referente a las reglas de
  * 								   produccion.
  */


#include <vector>
#include <string>
#include <ctype.h>
#include "alfabeto.h"
#include "transicion.h"
#include "NFA.h"
#pragma once

class regprod {
  public:
   /** Regla de produccion*/
    std::string regla;
   /** No terminal de partida*/ 
    std::string salida;
   /** Simbolos no terminales en la produccion*/
    std::string noterminales;
   /** Simbolos terminales en la produccion*/
    std::vector<alfabeto> terminales;
    /** COnstructor predeterminado*/
    regprod();
   /**
   *@brief Es usada para saber cuantos estados son necesarios añadir
   *@param ninguno
   *@return int: Numero de estados que añadir
   */
    int AddStates();
   /**
   *@brief Pasamos de una regla de produccion a una transicion
   *@param nfa_: objeto de tipo NFA que se va a modificar
   *@return int: Numero de estados añadidos en total
   */
    int MakeTransicion(NFA& nfa_);
    void Minimize(const char c);
    int NumerodeNoTerminales();
};
