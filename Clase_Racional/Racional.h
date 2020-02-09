#include <iostream>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <cstdlib>

 class Racional  {
  public:
   //Constructores
   Racional();
   Racional(int num, int den);
   
   //Obtiene numerador
   int get_num(){
   return _num;
   }
   
   //Obtiene denominador
   int get_den(){
   return _den;
   }

   //Da valor numerador
   void set_num(int n){
   _num = n;
   }
   
   //Da valor denominador   
   void set_den(int d){
   assert ( d!=0);
   _den = d;
   }
   
   void rLine(Racional& A, Racional& B, std::ifstream& fichero);
   void fWrite(Racional& a, Racional& b, const char c, char nombre[50]);
   void Final_(Racional& A, Racional& B, char in[50], char out[50]); 
   void Add(Racional& a, Racional& b);
   void Multiply(Racional& a, Racional& b);
   void Restar(Racional& a, Racional& b);
   void Dividir(Racional& a, Racional& b);
   void Write(std::ostream& os);
   void Comparar(Racional& a, Racional& b, char nombre[50]);
  
  private:
   int _num;
   int _den;
  };

   Racional::Racional(int num, int den)  {
   //Comprueba den != 0
   assert (den != 0);
   _num = num;
   _den = den;
   } 
   
   //Constructor base
   Racional::Racional(){ 
   _num = 0;
   _den = 1;
   }
   
   //Suma
   void Racional::Add(Racional& a, Racional& b){
    //Mismo den
    if (a.get_den() == b.get_den())  {
    _den = a.get_den();                          
    _num = a.get_num() + b.get_num();
    }
    //Distinto den
    else {
    _den = a.get_den() * b.get_den();
    _num = b.get_num() * a.get_den() + a.get_num() * b.get_den();
    }
   }
  
   //Multiplica
   void Racional::Multiply(Racional& a, Racional& b) {
    _num = a.get_num() * b.get_num();
    _den = a.get_den() * b.get_den();
   
   }
   
   //Imprime por pantalla
   void Racional::Write(std::ostream& os){
    os << std::setw(5) << get_num() << "/"  << get_den() << std::endl;
   }

   void Racional::Restar(Racional& a, Racional& b){
    if (a.get_den()==b.get_den())  {
    _den = a.get_den();
    _num = a.get_num() - b.get_num();
    }  else {
    _den = a.get_den() * b.get_den();
    _num = a.get_num() * b.get_den() - b.get_num() * a.get_den();
     }
   }
 
   void Racional::Dividir(Racional& a, Racional& b){
    _num = a.get_num() * b.get_den();
    _den = a.get_den() * b.get_num();
   }

   //Compara e imprime directamente
   void Racional::Comparar(Racional& a, Racional& b, char nombre[50]){
    Racional aux;
    std::ofstream bucky;
    //Abrimos fichero con el nombre pasado por parametro
    bucky.open(nombre, std::fstream::app);
    aux.Restar(a,b);
     if (aux.get_num()<0) {
		  bucky << "A es menor"<< std::endl;
     }
     if (aux.get_num()>0) {
		  bucky << "A es mayor" << std::endl;
     }
     if (aux.get_num()==0) {
     bucky << "Los numeros son iguales" << std::endl;
     }
    bucky.close();
   }
   
   void Racional::Final_(Racional& A, Racional& B, char in[50], char out[50]){
    std::ifstream bucky;
    //Abrimos el fichero
    bucky.open(in);
    char aux1,aux2;
    int a,b,c,d = 0;
     //Comprobamos que la peticion de abrirlo se cumplio
     if (!bucky.is_open()) {
      exit(EXIT_FAILURE);
     }

     //Bucle de lectura de grupos de numeros pares
     while (bucky >> a >> aux1 >> b >> c >> aux2 >> d) {
      A.set_num(a);
      A.set_den(b);
      B.set_num(c);
      B.set_den(d);
      Add(A,B);
      fWrite(A,B,'+',out);
      Multiply(A,B);
      fWrite(A,B,'*',out);
      Restar(A,B);
      fWrite(A,B,'-',out);
      Dividir(A,B);
      fWrite(A,B,'/',out);
      Comparar(A,B,out);
     }
    bucky.close();		
   }
 
   //Escritura por fichero pasado por parametro
   void Racional::fWrite(Racional& a, Racional& b, const char c, char nombre[50])
{
    std::ofstream bucky;
    bucky.open(nombre, std::fstream::app);
    bucky << a.get_num() << "/" << a.get_den();
    bucky << std::setw(2) << c << std::setw(2);
    bucky << b.get_num() << "/" << b.get_den();
    bucky << " = " << get_num() << "/" << get_den() << "\n";
    bucky.close();
   }
  /* void Racional::rline(Racional& A,Racional& B, std::ifstream& fichero){
	int a,b,c,d;
	char aux1,aux2;
	while(fichero >> a >> aux1 >> b >> c >> aux2 >> d){
	fichero >> a >> aux1 >> b >> c >> aux2 >> d;
        A.set_num(a);
        A.set_den(b);
        B.set_num(c);
        B.set_den(d);
	}
   }*/

