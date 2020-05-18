#include <iostream>
#include "Pila_max.hpp"

using namespace std;

int main(){

  PilaMax<int> p;
  int i;

  for ( i=10; i>=0 ; i--)
    p.poner(i);

  while (!p.vacia() ){
    cout << "El elemento de arriba de la pila max es: "<<p.tope()<<" y el maximo es: "<<p.max()<<endl;
    p.quitar();
  }

  cout << "Segunda prueba: " <<endl;

  for ( i=0; i<=10 ; i++)
    p.poner(i);

  while (!p.vacia() ){
    cout << "El elemento de arriba de la pila max es: "<<p.tope()<<" y el maximo es: "<<p.max()<<endl;
    p.quitar();
  }

  return 0;
}
