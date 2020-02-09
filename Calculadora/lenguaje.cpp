// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 3 CyA - Calculadora para lenguajes formales
// Autor: Gabriel García Jaubert
// Correo: alu0101240374@ull.edu.es
// Fecha: 08/10/2019
// Archivo lenguaje.cpp: En este archivo de 
// 	    	 	 desarrolla toda la clase Lenguaje anterior mente 
// 	    	 	 mencionada.
//

#include "lenguaje.h"
 //Constructor con una cadena como inicio
 Lenguaje::Lenguaje(std::string cadena){
   lenguaje.insert(cadena);
 }
 //Constructor vacio
 Lenguaje::Lenguaje(){
 }
 //Escribre SOLO UN lenguaje
 void Lenguaje::WriteSet(std::string out){
   std::ofstream salida;
   salida.open(out,std::fstream::app);
   salida << "{";
   for (std::set<std::string>::iterator it = lenguaje.begin();
                                   it != lenguaje.end(); it++) {
     if (it == lenguaje.begin())
       salida << *it;
       else
         salida << ", " << *it ;
     } 
   salida << '}' << "\n";
 }

 //Escribe todos los lenguajes
 void Lenguaje::fWrite(std::string out, std::vector<Lenguaje> almacen){
   std::ofstream salida;
   salida.open(out,std::fstream::app);
   for (int i = 0; i < almacen.size(); i++) {
     for (std::set<std::string>::iterator it = almacen[i].lenguaje.begin();
		       	             it != almacen[i].lenguaje.end(); it++) {
       salida << " " << *it;
     } 
   salida << "\n";}
 }

 Lenguaje Lenguaje::Concatenacion(Lenguaje& B){
   Lenguaje C;
   for (std::set<std::string>::iterator it = lenguaje.begin(); 
		                   it != lenguaje.end(); it++) {
     for (std::set<std::string>::iterator it2 = B.lenguaje.begin(); 
		                    it2 != B.lenguaje.end(); it2++) {
       //Reserva memoria para copiar un string
       char aux[20];
       std::string str1 = *it;
       std::string str2 = *it2;
       strcpy(aux, str1.c_str());
       strcat(aux, str2.c_str());
       C.lenguaje.insert(aux);    
     }
   }
   return C;
 }
  
 Lenguaje Lenguaje::Union(Lenguaje B){
   Lenguaje C;
   C.lenguaje.insert(lenguaje.begin(), lenguaje.end());
   C.lenguaje.insert(B.lenguaje.begin(), B.lenguaje.end()); 
   return C;
 }

 Lenguaje Lenguaje::Interseccion(Lenguaje& B){
   Lenguaje C;
   set_intersection(lenguaje.begin(),lenguaje.end(),
		    B.lenguaje.begin(),B.lenguaje.end(),
		    std::inserter(C.lenguaje,C.lenguaje.begin()));
   return C;
 }

 Lenguaje Lenguaje::Diferencia(Lenguaje& B){
   Lenguaje C;
   set_difference(lenguaje.begin(),lenguaje.end(),
                  B.lenguaje.begin(),B.lenguaje.end(),
                  std::inserter(C.lenguaje,C.lenguaje.begin()));
   return C;
  }

 bool Lenguaje::Sublenguaje(Lenguaje B){
   std::set<std::string>::iterator it = lenguaje.begin();
   do{
     B.lenguaje.find(*it) != B.lenguaje.end();
     it++;
   }
   while ((it != lenguaje.end())&&(B.lenguaje.find(*it) != B.lenguaje.end()));
     if (it == lenguaje.end())
	   return true;
     else 
	   return false;
 } 

 bool Lenguaje::Iguales(Lenguaje& B){
   if ((Sublenguaje(B))&&(B.Sublenguaje(*this)))
     return true;
   else 
     return false;
 }

 Lenguaje Lenguaje::Potencia(std::string n){
   //convertimos un string en un integer
   int times = stoi(n);
   assert (times >= 0);
   if (times == 0) { 
     Lenguaje C("&");
     return C;
   } else if (times == 1) {
       return *this;
     } else {
         Lenguaje C;
	 C = Concatenacion(*this);
         for (int  i=2;i<times;++i) {
           C = C.Concatenacion(*this);
         }    
       return C;
       }
 }

 void Lenguaje::Kleene(std::string out){
   //Dado que infinito no existe iteramos un numero finito de veces
   Lenguaje C;
   C.lenguaje.insert("&"); 
   C = C.Union(*this);
   C = C.Union(Potencia("2"));
   C = C.Union(Potencia("3"));		   
   C.fWriteInfinito(out);
 } 

 void Lenguaje::Positivo(std::string out){
   Lenguaje C;
   C = C.Union(*this);
   C = C.Union(Potencia("2"));
   C = C.Union(Potencia("3"));
   C.fWriteInfinito(out);
 }

 //Write solo para Kleene y Positivo
 void Lenguaje::fWriteInfinito(std::string out){
   std::ofstream salida;
   salida.open(out,std::fstream::app);
   salida << "{";
   std::set<std::string>::iterator it = lenguaje.begin();
   for (int i = 0; i < 10; i++) {  
     if (it == lenguaje.begin()) {
     salida << *it;
     it++;    
     }
     else{
     salida << ", " << *it;
     it++;
     }
    } salida << "..." << '}' << "\n";
 }

 Lenguaje Lenguaje::Inversa(){
   Lenguaje C;
   std::string aux;
   for (std::set<std::string>::iterator it = lenguaje.begin();
		                   it != lenguaje.end(); it++) {
     aux = *it;
     reverse(aux.begin(),aux.end());
     C.lenguaje.insert(aux);
     } 
   return C;
 }
 //Write solo para Iguales y Sublenguaje
 void Lenguaje::WriteBool(int n, int m, std::string out){
   std::ofstream salida;
   salida.open(out,std::fstream::app);
   std::string str1,str2;
   if (n == 1) {
     str1 = "sublenguaje";
   } else {
       str1 = "igual";
     }
   if (m == 1) {
     str2 = "si";
   }
   else{ 
     str2 = "no";
   }
   salida << "La cadena " << str2 << " es " << str1 << "\n";
 } 

 void Lenguaje::fRead(std::string entrada, std::string salida, 
		               std::vector<Lenguaje> &almacen){
   std::ifstream fichero;
   fichero.open(entrada);
   if (!fichero.is_open()) {
     exit(EXIT_FAILURE);	  
   }
   std::string line;
   int i = 0;
   while (getline(fichero, line)) {
     Lenguaje aux;
     almacen.push_back(aux);
     line.erase(line.begin(), line.begin()+1); 
     line.erase(line.end()-1, line.end());
     std::stringstream ss(line);
     while (ss >> line) {
       if (line.find('&') != std::string::npos)
         continue;
       if (line.find(',') != std::string::npos) {
       line.erase(line.end()-1, line.end());
       }  
       almacen[i].lenguaje.insert(line);
     }
   i++;  
  }
 }



