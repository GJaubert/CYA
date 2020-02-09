// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 7 CyA - Algoritmo de Creacion de Subconjuntos
// Autor: Gabriel García Jaubert
// Correo: alu0101240374@ull.edu.es
// Fecha: 05/11/2019
// Archivo NFA.cpp: Desarrollamos los metodos de la clase NFA
//                    
// 

#include "NFA.h"
#include <stack>

 NFA::NFA(){}

 void NFA::Read(std::string filein){
   std::string line;
   std::ifstream fichero;
   fichero.open(filein);
   if (!fichero.is_open()) {
	  exit(EXIT_FAILURE);
   }
   while (getline(fichero,line)) {
     if ((line[0] == '/') && (line[1] == '/')) {
       continue;
     }
     if ((line[0] != '/')||(line[1] != '/')) {
       nsimbolos = line;
       break;
     }
   }
   int x = stoi(nsimbolos);
   getline(fichero,line);
   for (int i = 0; i < x; i++) {
     getline(fichero,line);
     alfabeto item(line);
     simbolos.push_back(item);
   }
   getline(fichero,nestados);
   x = stoi(nestados);
   for (int i = 0; i < x; i++) {
     getline(fichero,line);
     estado item2(line);
     estados.push_back(item2);
   }
   getline(fichero,inicio);
   getline(fichero,naceptacion);
   x = stoi(naceptacion);
   for (int i = 0; i < x; i++) {
     getline(fichero,line);
     estado item3(line);
     for (int j = 0; j < estados.size(); j++) {
       if (estados[j].etiqueta.compare(line) == 0)
         estados[j].aceptacion = true;
     }
     aceptacion.push_back(item3);
   }
   getline(fichero,ntransiciones);
   x = stoi(ntransiciones);
   for (int i = 0; i < x; i++) {
     int j = 0;
     transicion item4;
     fichero >> line;
     item4.salida = line;
     for (j; j < estados.size(); j++) {
       if (estados[j].etiqueta.compare(item4.salida) == 0)
	 break;
     }
     fichero >> item4.label;
     estados[j].label.push_back(item4.label);
     fichero >> item4.destino;
     estados[j].destino.push_back(item4.destino);
     transiciones.push_back(item4);
   }
 }

 void NFA::Write(std::string fileout){
   std::ofstream ficherout;
   ficherout.open(fileout, std::fstream::app);
   ficherout << "digraph DFA {\n";
   ficherout << " rankdir=LR;" << "\n";
   ficherout << " size = " << '"' << "10, 4" << '"' << ';' << "\n";
   ficherout << " d2tstyleonly = true;\n";
   
   ficherout << "node [shape = none]; "<< '"' << " " << '"' << ';' << "\n";
   ficherout << "node [shape = doublecircle];";
   int x = stoi(naceptacion);
   for (int i = 0; i < x; i++) {
     ficherout << " " << '"' << aceptacion[i].etiqueta << '"';
   }
   ficherout << ';';
   ficherout << "\n";
   ficherout << "node [shape = circle];\n";
   ficherout << '"' << " " << '"' << " -> " << '"' << inicio << '"';
   ficherout << "\n";
   x = stoi(ntransiciones);
   for (int i = 0; i < x; i++) {
     ficherout << '"' << transiciones[i].salida << '"';
     ficherout << " -> ";
     ficherout << '"' << transiciones[i].destino << '"';
     ficherout << "  [ label=" << '"' << transiciones[i].label << '"';
     ficherout << "];\n";
   }
   std::vector<estado> manolo = Move(estados,'1');
   for (int i = 0; i < manolo.size(); i++) {
	   ficherout << manolo[i].etiqueta;
   }
 }

 std::vector<estado> NFA::eClausura(std::vector<estado> T) {
   std::stack<estado> pila;
   std::vector<estado> epsilon = T;
   for (int k = 0; k < T.size(); k++) {
     T[k].epsilonvisitado = true;
     pila.push(T[k]);
     for (int i = 0; i < estados.size(); i++) {
       if (estados[i].etiqueta.compare(T[k].etiqueta) == 0)
 	 estados[i].epsilonvisitado = true;
     }     
   }
   while (!pila.empty()) {
     estado p;
     p.etiqueta = pila.top().etiqueta;
     p.epsilonvisitado = pila.top().epsilonvisitado;
     for (int i = 0; i < pila.top().label.size(); i++) {
       p.label.push_back(pila.top().label[i]);
       p.destino.push_back(pila.top().destino[i]);
     }
     pila.pop();
     for (int i = 0; i < p.label.size(); i++) {
       if ( p.label[i][0] == '~') {
         for (int j = 0; j < estados.size(); j++) {
           if ((estados[j].etiqueta.compare(p.destino[i]) == 0)&&
               (estados[j].epsilonvisitado == false)) {
	         estados[j].epsilonvisitado = true;
	         epsilon.push_back(estados[j]);
	         pila.push(estados[j]);
           }
         }
       }
     }
   }
   return epsilon;
 }

 std::vector<estado> NFA::Move(std::vector<estado> T, char a){
    std::stack<estado> pila;
    std::vector<estado> move;
    for (int i = 0; i < T.size(); i++) {
      T[i].movevisitado = true;
      pila.push(T[i]);
/*    for (int j = 0; j < estados.size(); j++) {
      if (estados[j].etiqueta.compare(T[i].etiqueta) == 0)
        estados[j].movevisitado = true;
    }*/
    } 
    while (!pila.empty()) {
      estado p;
      p.etiqueta = pila.top().etiqueta;
      p.epsilonvisitado = pila.top().epsilonvisitado;
      for (int i = 0; i < pila.top().label.size(); i++) {
        p.label.push_back(pila.top().label[i]);
        p.destino.push_back(pila.top().destino[i]);
      }
      pila.pop();
      for (int i = 0; i < p.label.size(); i++) {
        if (p.label[i][0] == a) {
          for (int j = 0; j < estados.size(); j++) {
	    if ((estados[j].etiqueta.compare(p.destino[i]) == 0)&&
	        (estados[j].movevisitado == false)) {
	           estados[j].movevisitado = true;
	           move.push_back(estados[j]);
	    }
	  } 
        }
      }
    }
  return move;
 }
