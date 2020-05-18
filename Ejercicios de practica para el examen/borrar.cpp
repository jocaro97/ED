/*
(1.5 puntos) Dada una lista que contiene pilas con enteros y que se encuentra
ordenada de menor a mayor por el tope de cada pila, implementar una función
borrar, que elimina el tope de cada pila en la lista, con valores iguales al dado
como parámetro. La cabecera de la función sería:

void Borrar(list<stack<int> > & L, int elemento)
 */


#include <iostream>
#include <cmath>
#include <stack>
#include <list>
using namespace std;


  bool compare(const stack<int> &n1, const stack<int> &n2) {
    return (n1.top() <= n2.top());
  }



void Borrar(list<stack<int> > & L, int elemento){
  list<stack<int> >::iterator p;
  for(p = L.begin(); p != L.end(); ++p){
    if((p -> top()) == elemento){
      p -> pop();
      if (p -> empty())
        L.erase(p);
        p--;
    }
  }

  L.sort(compare);

}

int main(int argc, char const *argv[]) {
  stack<int> aux;
  list<stack<int> > lista;

  aux.push(1);
  aux.push(9);
  aux.push(2);

  lista.push_back(aux);

  aux.pop();
    aux.pop();
      aux.pop();

  aux.push(0);
  aux.push(1);
  aux.push(2);

  lista.push_back(aux);

  aux.pop();
    aux.pop();
      aux.pop();

  aux.push(2);

  lista.push_back(aux);

  aux.pop();

  aux.push(7);
  aux.push(10);
  aux.push(9);
  aux.push(3);

  lista.push_back(aux);

  aux.pop();
    aux.pop();
      aux.pop();
      aux.pop();

  aux.push(2);
  aux.push(4);


    lista.push_back(aux);

    aux.pop();
      aux.pop();

    aux.push(2);
    aux.push(8);

    lista.push_back(aux);

      list<stack<int> >::iterator q;

      cout << "lista sin borrar" <<endl;

      for(q = lista.begin(); q!= lista.end(); ++q)
        cout << q -> top() <<endl;

      Borrar(lista, 2);

      cout << "lista borrada" <<endl;


      for(q = lista.begin(); q!= lista.end(); ++q)
        cout << q -> top() <<endl;



  return 0;
}
