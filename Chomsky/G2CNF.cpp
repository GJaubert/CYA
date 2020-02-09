/**
  * @file main.h
  * @version 1.0
  * @date 12/11/2019
  * @author alu0101240374
  * @brief Gestionamos argumentos y comenzamos el programa
  */


#include "grammar.h"

 int main (int argc, char* argv[]) {
  /** Comprobamos si los argumentos estan bien escritos*/
    std::string help = "--help";
    std::string str = argv[1];
    if (str.compare(help) == 0 ) {
      std::cout << "Este programa trabaja con un fichero de entrada\n";
      std::cout << "****.dfa que se debera introducir con un formato\n";
      std::cout << "especifico en el cual se describa el DFA\n";
      std::cout << "en cuestion, y escribir de la siguiente forma \n";
      std::cout << "para que sea leido: ./DFA2dot input.dfa output.gv\n";
    }
    else if ((argc == 1) || (argc == 2)) {
      std::cout << "Formato de archivo incorrecto, pruebe ./DFA2dot";
      std::cout << "--help para mas informacion\n";
    } else {
       //Creamos objeto grammar
        grammar bucky(argv[1]);
        bucky.chomsky();
	bucky.WriteGrammar(argv[2]);
	//Convertimos a NFA e imprimimos 
//	bucky.convertToNFA().Specify(argv[2]);  
      }
 }  
