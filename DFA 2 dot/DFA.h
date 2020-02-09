/**
  * @file DFA.h
  * @version 1.0
  * @date 29/10/2019
  * @author alu0101240374
  * @brief Crea un DFA con las clases {transiciones, estado, alfabeto}
  */


#include "gestor.h"
#include "estado.h"
#include "alfabeto.h"
#include "transicion.h"

 class DFA {
   public: 
     /** Crea objeto alfabeto*/
     alfabeto alfabeto_;
     /** Crea objeto estado*/
     estado estado_;
     /** Crea un vector de objetos transiciones*/
     std::vector<transicion> transicion_;
     /** Contruye el DFA con un objeto gestor*/
     DFA(gestor gestor_);
 };
