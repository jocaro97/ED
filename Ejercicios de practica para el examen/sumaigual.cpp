/*
(1.5 puntos) Implementa una función bool sumaIgual(const list<list<int> > &L) que
devuelve true si todas las sumas por filas y por columnas da el mismo resultado (se
asume que todas las listas tienen igual longitud). Por ejemplo, en la siguiente lista si se
suma cada fila y cada columna siempre se obtiene 3
L=< <0,1,1,1>,
    <2,1,0,0>,
    <1,0,2,0>,
    <0,1,0,2> >
 */

#include <iostream>
#include <cmath>
#include <list>

bool sumaIgual(const std::list< std::list<int> > &L){
  bool sumasiguales = true;
  std::list<int> sumafilas;
  std::list<int> sumacolumnas;
  int sumafils = 0;

  std::list< std::list<int> >::const_iterator p;
  std::list<int>::const_iterator q;
  std::list<int>::iterator r,s;

  p = L.begin();
  for(int i=0; i< p -> size(); i++)
    sumacolumnas.push_back(0);


  for(p = L.begin(); p != L.end(); ++p){
    for(q = p -> begin(), r = sumacolumnas.begin(); q != p -> end() && r != sumacolumnas.end(); ++q, ++r){
      sumafils += *q;
      *r += *q;
    }

    sumafilas.push_back(sumafils);
    sumafils = 0;
  }

  for(r = sumacolumnas.begin(); (++r) != sumacolumnas.end(); ++r)
    if(*r != *(++r))
      sumasiguales = false;

  for(r = sumafilas.begin(); (++r) != sumafilas.end() && sumasiguales; ++r)
    if(*r != *(++r))
      sumasiguales = false;

  if(sumafilas.front() != sumacolumnas.front())
    sumasiguales = false;

  return sumasiguales;
}

int main(int argc, char const *argv[]) {
  std::list< std::list<int> > LI;

  std::list< std::list<int> >::iterator j;
  std::list<int> aux;

  aux.push_back(0);
  aux.push_back(1);
  aux.push_back(1);
  aux.push_back(1);

  LI.push_back(aux);

  aux.clear();

  aux.push_back(2);
  aux.push_back(1);
  aux.push_back(0);
  aux.push_back(0);

  LI.push_back(aux);

  aux.clear();

  aux.push_back(1);
  aux.push_back(0);
  aux.push_back(2);
  aux.push_back(0);

  LI.push_back(aux);

  aux.clear();

  aux.push_back(0);
  aux.push_back(1);
  aux.push_back(0);
  aux.push_back(2);

  LI.push_back(aux);
  std::cout << "LISTA:" <<std::endl;
  std::list<int>:: iterator k;

  for(j = LI.begin(); j != LI.end(); ++j){
    for(k = j -> begin(); k != j-> end(); ++k)
      std::cout << *k <<" ";

    std::cout << std::endl;
  }

  if(sumaIgual(LI))
    std::cout << "SUMA IGUALES" << std::endl;
    else
      std::cout << "SUMA DISTINTA" << std::endl;

  aux.clear();

  aux.push_back(0);
  aux.push_back(1);
  aux.push_back(0);
  aux.push_back(2);

  LI.push_back(aux);

  for(j = LI.begin(); j != LI.end(); ++j){
    for(k = j -> begin(); k != j-> end(); ++k)
      std::cout << *k <<" ";

    std::cout << std::endl;
  }

  if(sumaIgual(LI))
    std::cout << "SUMA IGUALES" << std::endl;
    else
      std::cout << "SUMA DISTINTA" << std::endl;

  return 0;
}
