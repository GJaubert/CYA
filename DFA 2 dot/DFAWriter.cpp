// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 6 CyA - Automatas Finitos Deterministas
// Autor: Gabriel García Jaubert
// Correo: alu0101240374@ull.edu.es
// Fecha: 29/10/2019
// Archivo DFAWriter.cpp: Desarrollamos los metodos de la clase DFAWriter
//                    
//    

#include "DFAWriter.h"

DFAWriter::DFAWriter(){
}

DFAWriter::DFAWriter(std::string str){
  out = str;
}

void DFAWriter::WriteStandard(DFA dfa_){
	ficherout << "digraph DFA {\n";
	ficherout << " rankdir=LR;" << "\n";
        ficherout << " size = " << '"' << "10, 4" << '"' << ';' << "\n";
	ficherout << " d2tstyleonly = true;\n";
}

void DFAWriter::WriteShapes(DFA dfa_){
  ficherout << "node [shape = none]; "<< '"' << " " << '"' << ';' << "\n";
  ficherout << "node [shape = doublecircle];";
  int x = stoi(dfa_.estado_.numeroaceptacion);
  for (int i = 0; i < x; i++){
    ficherout << " " << '"' << dfa_.estado_.aceptacion[i] << '"';
  }
  ficherout << ';';
  ficherout << "\n";
  ficherout << "node [shape = circle];\n";
}

void DFAWriter::WriteDelta(DFA dfa_){
  ficherout << '"' << " " << '"' << " -> " << '"' << dfa_.estado_.start << '"';
  ficherout << "\n";
  int x = stoi(dfa_.transicion_[0].cantidadtransiciones);
  for (int i = 0; i < x; i++) {
    ficherout << '"' << dfa_.transicion_[i].salida << '"';
    ficherout << " -> ";
    ficherout << '"' << dfa_.transicion_[i].destino << '"';
    ficherout << "  [ label=" << '"' << dfa_.transicion_[i].label << '"'; 
    ficherout << "];\n";
  }
}

void DFAWriter::MainWrite(DFA dfa_){
  ficherout.open(out, std::fstream::app);
  WriteStandard(dfa_);
  WriteShapes(dfa_);
  WriteDelta(dfa_);
  ficherout << '}';
}
