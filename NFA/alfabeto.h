/**
   * @file alfabeto.h
   * @version 1.0
   * @date 05/11/2019
   * @author alu0101240374
   * @brief Guardamos lso simbolos.
   */


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#pragma once

 class alfabeto {
   public:
     /** Vector que guarda los simbolos*/
     std::string simbolo;
     /** Constrcutor predeterminado*/
     alfabeto();
     /** Constructor con un string*/
     alfabeto(std::string str);
 };
