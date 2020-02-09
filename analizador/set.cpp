#include "set.h"


//Constructor predeterminado
 Token::Token(){
   token = "vacio";
 } 
 //constructor
 Token::Token(std::string intoken){
   token = intoken;
 }

 //STRING -> string
 void Token::Minus(){
   std::for_each(token.begin(), token.end(), [](char& c){
   c = ::tolower(c);
   });		
 }

 //string -> STRING
 void Token::Mayus(){
   std::for_each(token.begin(), token.end(), [](char& c){
   c = ::toupper(c);
   });
 }


 //Comprueba que no tenga caracteres especiales
 bool Token::CheckNoSpecial(){
   for (int i=0;i<token.size();i++) {
     //usamos ctype.h para la comprobacion de numero/letra
     if ((isdigit(token[i]))||(isalpha(token[i]))) {
       continue;		    
     } else {
         return true;
       }
   } return false; 
 }

 //Escritura de fichero
 void Token::fWrite(char out[50], char const tipo[15]){
   std::ofstream salida;
   //fstream::app no sobreescribe el fichero
   salida.open(out,std::fstream::app);
   salida << tipo << "   " << token << "\n";
   salida.close();
 }

 //comprobamos si es int, float o desconocido 
 int Token::CheckType(){
   for (int i=0;i<token.size();i++) {
     if (isdigit(token[i])) {
       continue;
     } else {
         if (token[i] == '.'){
           for (int j=i+1; j<token.size();j++) { 
             if (isdigit(token[j])) { 
               continue;
             } else {
                 return 3;
               }
           } return 2;
         } else {
             return 3;
           }
       }
     
   } return 1;
 }
 //1 es int, 2 es float, 3 es desconocido


 void Token::fRead(char in[50], char out[50], std::set<std::string> set_, 
		std::set<std::string> set2_,
		std::set<std::string> set3_)
 {  
   std::ifstream fichero;
   //Abrimos el fichero
   fichero.open(in);
   //Comprobamos que la peticion de abrirlo se cumplio
   if (!fichero.is_open()) {
     exit(EXIT_FAILURE);
   }
   std::string line;
   while (fichero >> line) {
     //Creamos objeto con el string leido
     Token  T(line);
     T.Minus();
     line = T.token;
     //Create iterator
     std::set<std::string>::iterator it = set_.find(line);
     if (it != set_.end()) { 
       T.Mayus();
       T.fWrite(out,"   ");
     } else {
         it = set2_.find(line);
         if(it != set2_.end()){
           T.fWrite(out,"OP ");
	 } else {
             it = set3_.find(line);
             if(it != set3_.end()){
               T.fWrite(out,"SIG");
             } else {
	         switch(T.CheckType()){
	           case 1: T.fWrite(out,"INT");
		           break;
	           case 2: T.fWrite(out,"FLOT");
		           break;
	           case 3: if(T.CheckNoSpecial()){
		           Token T("");
		           T.fWrite(out,"DESCONOCIDO");  		    
		           } else  	    
	    		       T.fWrite(out,"PAL");
	                       break;
	         }
	       }
           }
       }
   }	
   fichero.close();
 }

/*void Token::CreateSet(std::string conjunto[], std::set<std::string> set_,
		int MAX)
 {
   for( int i = 0; i < 50; i++) {
     set_.insert(conjunto[i]);
   }
 }
*/
