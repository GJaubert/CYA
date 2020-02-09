/////////////////////////////////////////////////////////////
//  Gabriel Garcia Jaubert			           //
//							   //
// Universidad de La Laguna                                //
// 							   //
// Analizador de texto Practica 2                          //
/////////////////////////////////////////////////////////////

#include <fstream>
#include "set.h"
#include "tabla.h"



 int main (int argc, char* argv[]) {
   if ((argc == 1) || (argc == 2)) {
     std::cout << "Introduzca los archivos así: ./Ejecutable filein fileout\n";
   } else {	 
       //Creamos los conjuntos que usaremos despues para comprobar
       std::set<std::string> especial_(palabrasespeciales, 
		   palabrasespeciales+MAX_SPE);
       std::set<std::string> operators_(operators,operators+MAX_OP);
       std::set<std::string> sign_(sign,sign+MAX_SIG);
       char *entrada = argv[1];
       char *salida = argv[2];
       Token T;
       T.fRead(entrada,salida, especial_,operators_,sign_);
     }
 
 }
