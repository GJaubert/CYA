#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#pragma once

 class alfabeto {
   public:
     /** Cantidad de simbolos en el alfabeto*/
     std::string numerodesimbolos;
     /** Vector que guarda los simbolos*/
     std::vector<std::string> simbolos;
     /** Constructor de alfabeto*/
     alfabeto(std::string in, std::vector<std::string> vectorin);
     /** Constrcutor predeterminado*/
     alfabeto();
    
    /**
     *@brief Crea un vector de simbolos y guarda su tamaño
     *@param strin Cantidad de simbolos, vectorin Vector con los estados
     *@return ninguno
     */
     void CreateAlfabeto(std::string in, std::vector<std::string> vectorin);
 };
