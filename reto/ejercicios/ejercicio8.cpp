/*
EJERCICIO 8

Diseñar una función que dada una lista devuelva otra lista R
los elementos repetidos de L. Si no hay elementos repetidos R
será la lista vacia.

L = {5,2,7,2,5,5,1}
R = {5,2}
 */

#include<iostream>
#include<list>

template<class T>
std::list<T> repetidos(std::list<T> L){
  typename std::list<T>::iterator p,q;
  std::list<T> aux;

  for(p = L.begin(); p != L.end(); p++){
    q = p;
    q++;
    while( q != L.end()){
      if(*p == *q){
        aux.push_back(*q);
        q = L.erase(q);
      }else
        q++;
    }
  }

  return aux;
}

template <class T>
std::ostream & operator<<(std::ostream & s, const std::list<T> & c){

  typename std::list<T>::const_iterator i;

  for (i=c.begin(); i != c.end(); i++)
      s << (*i) << " ";

  return s;
}

int main(int argc, char const *argv[]) {
  std::list<int> original = {1,2,3,3,3,4,5,6,6};

  std::list<char> orig = {'a','a','b','c','d','d'};

  std::cout << "Lista orignial" << std::endl;

  std::cout << original << std::endl;

  std::cout << "Lista de repetidos" << std::endl;

  std::cout << repetidos(original) << std::endl;

  std::cout << "Segunda lista original" << std::endl;

  std::cout << orig << std::endl;

  std::cout << "Segunda lista de repetidos" << std::endl;

  std::cout << repetidos(orig) << std::endl;


  return 0;
}
