// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 3 CyA - Calculadora para lenguajes formales
// Autor: Gabriel García Jaubert
// Correo: alu0101240374@ull.edu.es
// Fecha: 08/10/2019
// Archivo main.cpp: Este programa se basa en una calculadora de lenguajes, 
//                   en la cual si el usuario introduce un codigo, realiza
//                   cierta operacion con lenguajes que lee desde un fichero.
//

#include "lenguaje.h"
  
 int main (int argc, char* argv[]) {
   if ((argc == 1) || (argc == 2)||(argc == 3)) {
     std::cout << "Introduzca los archivos así: ./Ejecutable filein fileout\n";
   } else {
       Lenguaje A;
       std::vector<Lenguaje> almacen(1);
       A.fRead(argv[1],argv[2], almacen);
       int contador = almacen.size()-2;
       int i = 0;
       while (contador >= 0) {
	 if (strcmp(argv[3],"concatenacion") == 0) {
	   if (i+2 >= almacen.size()) break;
	   almacen[i].Concatenacion(almacen[i+1]).WriteSet(argv[2]);
	   i += 2;
	 }
	 else if (strcmp(argv[3],"union") == 0) {
           if (i+2 >= almacen.size()) break;
	   almacen[i].Union(almacen[i+1]).WriteSet(argv[2]);
	   contador -= 2;
	   i += 2;
	 }
         else if (strcmp(argv[3],"interseccion") == 0) {
           if (i+2 >= almacen.size()) break;
	   almacen[i].Interseccion(almacen[i+1]).WriteSet(argv[2]);
           contador -= 2;
	   i += 2;
	 }
  	 else if (strcmp(argv[3],"diferencia") == 0) {
	   if (i+2 >= almacen.size()) break;
	   almacen[i].Diferencia(almacen[i+1]).WriteSet(argv[2]);
     	   contador -= 2;
	   i += 2 ;
	   }
 	 else if (strcmp(argv[3],"sublenguaje") == 0) {
	   if (i+2 >= almacen.size()) break;
	   if (almacen[i].Sublenguaje(almacen[i+1]))
	     A.WriteBool(1,1,argv[2]);
	   else
	     A.WriteBool(1,0,argv[2]);
	     contador -= 2;
	     i += 2;
	   }
 	 else if (strcmp(argv[3],"igual") == 0) {
	   if (i+2 >= almacen.size()) break;
	   if (almacen[i].Iguales(almacen[i+1]))
	     A.WriteBool(0,1,argv[2]);
	   else 
	     A.WriteBool(0,0,argv[2]);
	     contador -= 2;
	     i += 2;
	 } 
	 else if (strcmp(argv[3],"inversa") == 0) {
 	   almacen[i].Inversa().WriteSet(argv[2]);
	   contador--;
	   i++;
	 }
         else if (strcmp(argv[3],"potencia") == 0) {
	   almacen[i].Potencia(argv[4]).WriteSet(argv[2]);
           contador--;
	   i++;
	 }
         else if (strcmp(argv[3],"positivo") == 0) {
	   almacen[i].Positivo(argv[2]);
	   contador--;
	   i++;
	 } 
 	 else if (strcmp(argv[3],"kleene") == 0) {
	   almacen[i].Kleene(argv[2]);
	   contador--;
	   i++;
	 }
         else {
           std::cout << "No se encuentra esa opcion\n";
	   break;
	 } 	
       }
     }
 }   


	
	
	
	
	
	
	
	
	
	
	
	
