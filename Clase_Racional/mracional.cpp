#include <iostream>
#include <fstream>
#include "Racional.h"
 int main(int argc, char* argv[]) {
  Racional A(0,1);
  Racional B;
  Racional C;
  char *entrada = argv[1];
  char *salida = argv[2];
  if ((argc == 1) || (argc == 2)) {
   std::cout << "Introduzca los archivos así: ./Ejecutable filein fileout\n";
  } else {
   C.Final_(A,B, entrada, salida);
  }
 } 
