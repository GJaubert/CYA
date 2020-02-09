/**
  * @file estado.h
  * @version 1.0
  * @date 20/11/2019
  * @author alu0101240374
  * @brief Esta clase es usada para guardar todo lo referente a la gramatica.
  */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "alfabeto.h"
#include "regprod.h"
#pragma once

class grammar {
  public:
   /** Numero de simbolos no terminales*/
    std::string nnoterminales;
   /** Vector de estados simbolos no terminales*/
    std::vector<alfabeto> noterminales;
   /** Vector de estados de simbolos terminales*/ 
    std::vector<alfabeto> terminales;
   /** Numero de simbolos no terminales*/
    std::string nterminales;
   /** Simbolo de arranque*/
    alfabeto arranque;
   /** Cantidad de reglas de produccion*/
    std::string nproducciones;
   /** Vector que almacena las reglas de produccion*/ 
    std::vector<regprod> rules;
   /** Constructor predeterminado con un fichero de entrada como param*/ 
    grammar(std::string filein);
   /**
   *@brief Transforma una gramatica en NFA
   *@param ninguno
   *@return NFA: objeto de tipo NFA
   */
    NFA convertToNFA();
    /**
   *@brief Transforma una gramatica en FNC
   *@param ninguno
   *@return ninguno
   */
    void chomsky();
    /**
   *@brief Sustituye los simbolos terminales de n > 2
   *@para string nontermaux: Nombre del nuevo estado no terminal
   *@return ninguno
   */
    void Substitude(std::string& nontermaux);
   /**
   *@brief Minimiza las producciones de mas de 2 simbolos no terminales
   *@param string nontermaux: Nombre del nuevo estado no terminal
   *@return ninguno
   */
    void Minimize(std::string& nontermaux);
   /**
   *@brief Busca si un str se encuentra en el vector noterminales
   *@param string str: String que se desea buscar
   *@return booleano
   */
    bool FindCx(std::string str);
   /**
   *@brief Escribe la gramatica en un fichero destino
   *@param string out: Nombre del fcihero destino
   *@return ninguno
   */
    void WriteGrammar(std::string out);
};
