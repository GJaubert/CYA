// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 9 CyA - Forma Normal de Chomsky y una Gramatica indepentdiente del
//                                                                    contexto.
// Autor: Gabriel García Jaubert
// Correo: alu0101240374@ull.edu.es
// Fecha: 20/11/2019
// Archivo regprod.cpp: Desarrollamos los metodos de la clase regprod(
// 						reglas de produccion)
//                    
//    

#include "regprod.h"

 regprod::regprod(){
 }

 int regprod::AddStates(){
   int contador = 0;
   for (int i = 0; i < regla.size(); i++) {
    //Comprobamos si es mayus
     if (isupper(regla[i]))
       break;
     contador++;
   } return contador-1;
 }

 int regprod::MakeTransicion(NFA& nfa_){
   int i = 0;
   int numerotransiciones = 1;
   transicion item;
   item.salida = salida;
  //Creamos no terminales extra si los necesitamos 
   for (i; i < AddStates(); i++) {
     alfabeto newsimbol(std::to_string(i+1));
     item.destino = newsimbol.simbolo;
     item.label = regla[i];
     numerotransiciones++;
     nfa_.transiciones.push_back(item);
     item.salida = item.destino;
   }
   alfabeto nonterminalsimbol(std::string(1,regla.back()));
   if (AddStates()+1 == regla.size())
     item.destino = "f";
   else 
     item.destino = nonterminalsimbol.simbolo;
   if (isupper(regla[i]))
     item.label = "~";
   else  
     item.label = regla[i];
   nfa_.transiciones.push_back(item);
   return numerotransiciones;
 }

 void regprod::Minimize(const char c){
   if ((regla.size() == 1) && (islower(regla[0])))
     return;
   else 
     for (int i = 0; i < regla.size(); i++) {
       if (isdigit(regla[i]) || (islower(regla[i]))) {
 	 regla.insert(i,1,c);
         i++;
       }
     } std::cout << regla << "\n";
 }


 int regprod::NumerodeNoTerminales(){
   int cantidad = 0;
   for (int i = regla.size()-1; i >= 0; i--) {
     if ((islower(regla[i]))||(isdigit(regla[i]))) {
       i--;
       cantidad++;
     }
     else if ((i != regla.size()-1)&&(!islower(regla[i+1])))
       cantidad++;
     else 
       cantidad++;
   }
   return cantidad;
 }
