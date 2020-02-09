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
// Archivo grammar.cpp: Desarrollamos los metodos de la clase grammar
//                    
// 

#include "grammar.h"

grammar::grammar(std::string filein){
   std::string line;
   std::ifstream fichero;
  fichero.open(filein);
  if (!fichero.is_open()) 
    exit(EXIT_FAILURE);
 //Saltamos los comentarios
  while (getline(fichero,line)) {
     if ((line[0] == '/') && (line[1] == '/')) {
       continue;
     }
     if ((line[0] != '/')||(line[1] != '/')) {
      nterminales = line;
       break;
     }
   }
 //Lectura de alfabeto 
  int x = stoi(nterminales);
  for (int i = 0; i < x; i++) {
    getline(fichero,line);
    alfabeto item(line);
    terminales.push_back(item);
  }
 //Lectura de no terminales 
  getline(fichero,nnoterminales);
  x = stoi(nnoterminales);
  for (int i = 0; i < x; i++) {
    getline(fichero,line);
    alfabeto item2(line);
    noterminales.push_back(item2);
  }
 //Lectura de reglas de produccion 
  getline(fichero,arranque.simbolo); 
  getline(fichero,nproducciones);
  for (int i = 0; i < stoi(nproducciones); i++) {
    regprod item3;
    fichero >> item3.salida;
    fichero >> line;
    fichero >> item3.regla;
    rules.push_back(item3); 
  }
 }

 bool grammar::FindCx(std::string str){
   for (int i = 0; i < noterminales.size(); i++) {
     if (noterminales[i].simbolo.compare(str) == 0) {
       return true;
     }
   } 
   return false;
 }

 void grammar::Minimize(std::string& nontermaux){
   int quantity = 0;
   int newsimbols_ = 1;
   char c = nontermaux[0];
   c++;
   nontermaux = c;
   for (int i = 0; i < rules.size(); i++) {
     newsimbols_ = 1;
     quantity = 0;  
     for (int j = rules[i].regla.size()-1; j >= 0; j--) {
       if (rules[i].NumerodeNoTerminales() > 2) {
         if (quantity < 2) {
           if (((isdigit(rules[i].regla[j]))||(islower(rules[i].regla[j])))&&
			                                           (j != 1)) {
             j = j-2;
             quantity++;
           } else {
               quantity++;
             }
         } else {
             std::string str = rules[i].regla.substr(j+2,
			       rules[i].regla.size()-1);
             std::string straux = nontermaux + std::to_string(newsimbols_);
             rules[i].regla.erase(rules[i].regla.begin()+j+2,
			          rules[i].regla.end());
	     rules[i].regla.append(straux);
	    //Creamos el no terminal
	     alfabeto newnonterminal(straux);
	     noterminales.push_back(straux);
	     nnoterminales = std::to_string(noterminales.size());
	    //Creamos la nueva regla de produccion
	     regprod newrule;
	     newrule.salida = straux;
	     newrule.regla = str;
	     rules.push_back(newrule);
	     nproducciones = std::to_string(rules.size());
	    //Colocamos todo en orden para volver a iterar
	     j = rules[i].regla.size();
             newsimbols_++;
	     quantity = 0;
           }
       } 	   
     }
     c++;
     nontermaux = c;
   }
 }

 void grammar::chomsky(){
   int n = noterminales.size();
   std::string str = noterminales[n-1].simbolo;
   char c = str[0];
   c++;
   str = c;
   Substitude(str);
   Minimize(str);
 }

 void grammar::Substitude(std::string& nontermaux){
   for (int j = 0; j < rules.size(); j++) {
     if (rules[j].regla.size() > 1) { 
       for (int i = 0; i < rules[j].regla.size(); i++) {
         if (isdigit(rules[j].regla[i]) || (islower(rules[j].regla[i]))) {
           std::string str = nontermaux;
       	   str.push_back(rules[j].regla[i]);
	   rules[j].regla.insert(i,1,nontermaux[0]);
	   if (FindCx(str) == false) {
	     alfabeto newnonterminal(str);
	     noterminales.push_back(newnonterminal);
	     int t= stoi(nnoterminales) + 1;
             nnoterminales = std::to_string(t);
	     regprod newregprod;
   	     newregprod.salida = str;
	     newregprod.regla.push_back(rules[j].regla[i+1]);
	     rules.push_back(newregprod);
	     int p = stoi(nproducciones) + 1;
	     nproducciones = std::to_string(p);
	   }
           i++;
         }
       }
     }
   }
 }

 void grammar::WriteGrammar(std::string out){
   std::ofstream fichero;
   fichero.open(out, std::fstream::app);
   fichero << nterminales << "\n";
   for (int i = 0; i < terminales.size(); i++) {
     fichero << terminales[i].simbolo << "\n";
   }
   fichero << nnoterminales << "\n";
   for (int i = 0; i < noterminales.size(); i++) {
     fichero << noterminales[i].simbolo << "\n";
   }
   fichero << arranque.simbolo << "\n";
   fichero << nproducciones << "\n";
   for (int i = 0; i < rules.size(); i++) {
     fichero << rules[i].salida << "->" << rules[i].regla << "\n";
   }
 }

 /*NFA grammar::convertToNFA(){
   NFA chomsky;
   chomsky.nsimbolos = nterminales; 
  //Asignacion del alfabeto 
   for (int i = 0; i < terminales.size(); i++) {
     chomsky.simbolos.push_back(terminales[i]);
   }
  //Asignacion de los estados
   chomsky.nestados = nnoterminales;
   for (int i = 0; i < noterminales.size(); i++) {
     estado item(noterminales[i].simbolo);
     chomsky.estados.push_back(item);
   }
  //Estado de arranque 
   chomsky.inicio = arranque.simbolo;
   chomsky.naceptacion = "1";
   estado item2("f");
   chomsky.aceptacion.push_back(item2);
   int sumatransiciones = 0;
  //Asignacion de transiciones
   for (int i = 0; i < stoi(nproducciones); i++) {
     sumatransiciones += rules[i].MakeTransicion(chomsky);
   }
   chomsky.ntransiciones = std::to_string(sumatransiciones);
   return chomsky;
 }*/
