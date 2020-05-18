/*Programa para  */

#include <iostream>
#include <cmath>
#include "bintree.h"
using namespace std;

struct Comparenode {
  bool operator()(const bintree<int>::node& n1, const bintree<int>::node& n2) const
  {
    return *n1 > *n2;
  }
};

void SecuenciaGuiada(const bintree<int>& arbol)
{
  priority_queue<bintree<int>::node, vector<bintree<int>::node>, Comparenode> nodos;
  nodos.push(arbol.root());

  while(!nodos.empty()) {
    bintree<int>::node n = nodos.top();
    cout << *n << " ";
    nodos.pop();
    if (!n.left().null())
      nodos.push(n.left());
    if (!n.right().null())
      nodos.push(n.right());
  }
}

int main()
{
  /**
   *  EJERCICIO 3
   */
  cout << "EJERCICIO 3\n\n";
  bintree<int> arbol(21);

  arbol.insert_left(arbol.root(), 6);
  arbol.insert_right(arbol.root(), 5);
  arbol.insert_left(arbol.root().left(), 10);
  arbol.insert_right(arbol.root().left(), 1);
  arbol.insert_left(arbol.root().right(), 7);
  arbol.insert_right(arbol.root().right(), 3);
  arbol.insert_right(arbol.root().right().left(), 2);

  cout << "La secuencia guiada es: ";
  SecuenciaGuiada(arbol);

  cout << endl << endl;
return 0;
} 
