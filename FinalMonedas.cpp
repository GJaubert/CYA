#include <vector>
#include <list>
#include <iostream>
#include <string>
#include <iomanip>

class Cambio{
  public:
  int value;
  int quantity;
  std::list<Cambio> Devolver_cambio(int n, std::vector<int> monedas);
};

std::list<Cambio> Cambio::Devolver_cambio(int n, std::vector<int> monedas){
  int cociente = 0;
  int resto = n;
  std::list<Cambio> cambio;
  for (int i = 0; i < monedas.size(); i++) {
    if ((cociente = (resto/monedas[i])) > 0) {
      value = monedas[i];
      quantity = cociente;
      cambio.push_back(*this);
      resto = resto%monedas[i];
    } 
  } 
  // condicion de parada
   if (resto != 0)
      cambio.back().quantity = 0;
  return cambio;
}

int main(){
  std::vector<int> monedas{ 10000,5000,200, 100, 50, 20, 5, 2, 1};
  std::cout << "Introduzca cantidad a pagar: \n";
  float input = 0;
  std::cin >> input;
  input = input * 100;
  int price = static_cast<int>(input);
  std::list<Cambio> resultado;
  Cambio entrada;
  resultado = entrada.Devolver_cambio(price, monedas);
  if (resultado.back().quantity == 0)
    std::cout << "No se encontro solucion\n";
  else { 
    for (std::list<Cambio>::const_iterator iterator = resultado.begin(), end = resultado.end(); iterator != end; ++iterator) {
      std::cout << "Moneda: ";
      float temp = static_cast<int>(iterator->value)/100;
      if (iterator->value >= 100) {
        int humanread = iterator->value/100;
	std::cout << humanread;
      }	
      else {
	if (iterator->value < 10)
          std::cout << "0.0" << iterator->value;
	else
	  std::cout << "0." << iterator->value;
      }
      std::cout << " Cantidad: "<< iterator->quantity <<"\n";
    }
  }
}
