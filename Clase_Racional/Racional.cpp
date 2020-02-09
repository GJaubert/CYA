#include <iostream>
#include <cassert>
#include <cmath>
#include <iomanip>

using namespace std;

 class Racional  {
  public:
	Racional();
	Racional(int num, int den);
	int get_num(){
		return _num;}
	int get_den(){
		return _den;}


	void set_num(int n){
		_num = n;}
	void set_den(int d){
		assert ( d!=0);
		_den = d;}

	void add(Racional& a, Racional& b);
	void multiply(Racional& a, Racional& b);
	void restar(Racional& a, Racional& b);
	void dividir(Racional& a, Racional& b);
  	void write(ostream& os);
  private:
	int _num;
	int _den;
 };

 Racional::Racional(int num, int den)  {
  assert (den != 0);
  _num = num;
  _den = den;
 } 
  Racional::Racional(){
  _num = 0;
  _den = 1;
 }
  void Racional::add(Racional& a, Racional& b){
	 if (a.get_den() == b.get_den())  {
		 _den = a.get_den();
		 _num = a.get_num() + b.get_num();
	 }
	 else {
		_den = a.get_den() * b.get_den();
		_num = b.get_num() * a.get_den() + a.get_num() * b.get_den();
	 }
  }
  void Racional::multiply(Racional& a, Racional& b) 
{
	_num = a.get_num() * b.get_num();
	_den = a.get_den() * b.get_den();
}
  void Racional::write(ostream& os)
{
	os << setw(5) << get_num() << "/"  << get_den();
	
}	
