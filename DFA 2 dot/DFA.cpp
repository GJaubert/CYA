// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 6 CyA - Automatas Finitos Deterministas
// Autor: Gabriel García Jaubert
// Correo: alu0101240374@ull.edu.es
// Fecha: 29/10/2019
// Archivo DFA.cpp: Desarrollamos los metodos de la clase DFA
//                    
//    

#include "DFA.h"

DFA::DFA(gestor gestor_){
    alfabeto_.CreateAlfabeto(gestor_.numerosimbolos, gestor_.alfabeto);
    estado_.CreateEstado(gestor_.estados, gestor_.statesname);
    estado_.start = gestor_.inicio;
    estado_.numeroaceptacion = gestor_.numeroaceptacion;
    estado_.aceptacion = gestor_.aceptacion;
    int x = stoi(gestor_.numerotransiciones);
    for (int i = 0; i < x; i++) {
      transicion aux(gestor_.salida[i], gestor_.label[i], gestor_.llegada[i]);
      transicion_.push_back(aux);
    }
    transicion_[0].cantidadtransiciones = gestor_.numerotransiciones;
}
