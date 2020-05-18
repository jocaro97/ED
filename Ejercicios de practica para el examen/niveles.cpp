/*
(1.5 puntos) Implementar una función que muestre las etiquetas de los nodos de un
árbol binario de enteros que estén entre dos niveles dados n1 y n2 (0<=n1<n2)
ambos inclusive
 */



#include <iostream>
#include <cmath>
#include "bintree.h"
using namespace std;

template <typename T>
void muestra(const bintree<T> & arbol, int n1, int n2){
  int nivel = 0;
  muestraniveles(arbol.root(),nivel,n1,n2);
}

template <typename T>
void muestraniveles(typename bintree<T>::node n, int nivel, int n1, int n2){

  if(!n.null()){
    if(n1 <= nivel)
      if(nivel <= n2){
      cout << *(n.left()) <<" ";
      cout << *(n.rigth()) <<" ";

      muestraniveles(n.left(), ++nivel, n1, n2);
      muestraniveles(n.right(), ++nivel, n1, n2);

    }
  }

}

int main(int argc, char const *argv[]) {
  bintree<int> Arb(7);
  Arb.insert_left(Arb.root(), 1);
  Arb.insert_right(Arb.root(), 9);
  Arb.insert_left(Arb.root().left(), 6);
  Arb.insert_right(Arb.root().left(), 8);
  Arb.insert_right(Arb.root().left().right(), 4);
  Arb.insert_left(Arb.root().right(), 5);

  muestra(Arb,1,2);

  return 0;
}
