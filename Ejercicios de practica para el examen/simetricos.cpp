/*
(1 punto) Implementa una función que compruebe si un árbol binario es simétrico de
otro.
bool simetricos(const bintree<T> &a, const bintree<T> &b).
*/

#include <iostream>
#include <cmath>
#include "bintree.h"
using namespace std;

template <typename T >
bool nodossimetricos(typename bintree<T>::node a, typename bintree<T>::node b){

  if((*(a.left()) == *(b.rigth())) && (*(a.right()) == *(b.left()))){

    if((nodossimetricos(a.left(), b.rigth())) && (nodossimetricos(b.left(), a.right())))
      return true;

  }else
    return false;
}

template <typename T >
bool simetricos(const bintree<T> &a, const bintree<T> &b){

  if(nodossimetricos(a.root(), b.root()))
    return true;
    else
      return false;


}
