/*
3.
(1.5 puntos) Una secuencia guiada sobre un árbol binario de enteros comienza por
la raíz para a continuación, en cada paso, seleccionar el nodo con etiqueta más
pequeña de entre los nodos disponibles en ese momento que no hayan sido listados.
Se entiende por nodo disponible aquel cuyo padre ya ha sido procesado (excluyendo
la raíz).
a) ¿Qué estructura auxiliar utilizarías para almacenar el conjunto de nodos
disponibles? Razona tu respuesta.
b) Implementar una función que permita obtener una secuencia guiada de un árbol
binario.
Ejemplo:
21
/
\
6
5
/ \
/ \
10 1 7 3
\
2
Recorrido guiado: 21, 5, 3, 6, 1, 7, 2, 10
 */

#include <iostream>
#include <cmath>
#include <queue>
#include "bintree.h"
using namespace std;

struct Comparenode{
  bool operator()(int n1, int n2){
    return n1 > n2;
  }
};

void visitaguiada(bintree<int>::node n,priority_queue<int, vector<int>, Comparenode> &cola){

  cout << cola.top() <<endl;
  cola.pop();

  if(!n.null()){

    if(!n.left().null())
      cola.push(*(n.left()));
    if(!n.right().null())
      cola.push(*(n.right()));

    if((!n.left().null()) && (!n.right().null())){
      if(*(n.left()) < *(n.right())){
        visitaguiada(n.left(), cola);
        visitaguiada(n.right(), cola);
      }else{
        visitaguiada(n.right(), cola);
        visitaguiada(n.left(), cola);
      }

    }else if(!n.left().null()){

    }


  }
  }

int main(int argc, char const *argv[]) {
  bintree<int> miarbol(21);

  miarbol.insert_left(miarbol.root(), 6);
  miarbol.insert_right(miarbol.root(), 5);

  miarbol.insert_left(miarbol.root().left(), 10);
  miarbol.insert_right(miarbol.root().left(), 1);

  miarbol.insert_left(miarbol.root().right(), 7);
  miarbol.insert_right(miarbol.root().right(), 3);

  miarbol.insert_right(miarbol.root().right().left(),2);

  cout << "MI ARBOL: (LEVEL)" <<endl;

  for (bintree<int>::level_iterator i = miarbol.begin_level(); i!=miarbol.end_level(); ++i)
    cout << *i << " ";

  cout << endl;



  priority_queue<int,vector<int>, Comparenode> micola;
  int numero = *(miarbol.root());
  micola.push(numero);

  visitaguiada(miarbol.root(), micola);



  return 0;
}
