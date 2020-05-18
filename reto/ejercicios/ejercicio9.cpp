/*
EJERCICIO 9
Diseñar una función orden:

  int orden (list<int> L)

  que devuelva 1 si L está ordeanada de forma asecendente de
  principio a fin, 2 si lo está de forma descendente y 0 si no
  está ordenada de ninguna forma
 */

#include<iostream>
#include<list>

int orden(std::list<int> L){
  bool esascendente, esdescendente;
  std::list<int>::iterator p,q;

  esascendente = true;
  esdescendente = true;

  q = L.begin();
  q++;

  for(p = L.begin(); (q != L.end())&&(esascendente); p++){
    if(*p > *q)
      esascendente = false;

    q++;
  }

  q = L.begin();
  q++;

  for(p = L.begin(); (q != L.end())&&(esdescendente); p++){
    if(*p < *q)
      esdescendente = false;

    q++;
  }

  if(esascendente)
    return 1;
    else if(esdescendente)
      return 2;
      else
        return 0;

}

int main(int argc, char const *argv[]) {
  std::list<int> primera ={1,2,3,4};
  std::list<int> segunda ={4,3,2,1};
  std::list<int> tercera ={1,2,1,3};

  std::list<int>::iterator p;

  std::cout << "Primera lista" << std::endl;

  for(p = primera.begin(); p != primera.end(); p++)
    std::cout << *p <<" ";

  std::cout << std::endl;

  if(orden(primera) == 1)
    std::cout << "Es ascendente" << std::endl;
    else if(orden(primera) == 2)
      std::cout << "Es descendente" << std::endl;
      else
        std::cout << "No esta ordenada" << std::endl;

  std::cout << "Segunda lista" << std::endl;

  for(p = segunda.begin(); p != segunda.end(); p++)
    std::cout << *p <<" ";

  std::cout << std::endl;

  if(orden(segunda) == 1)
    std::cout << "Es ascendente" << std::endl;
    else if(orden(segunda) == 2)
        std::cout << "Es descendente" << std::endl;
        else
            std::cout << "No esta ordenada" << std::endl;

  std::cout << "Tercera lista" << std::endl;

  for(p = tercera.begin(); p != tercera.end(); p++)
    std::cout << *p <<" ";

  std::cout << std::endl;

  if(orden(tercera) == 1)
    std::cout << "Es ascendente" << std::endl;
    else if(orden(tercera) == 2)
      std::cout << "Es descendente" << std::endl;
      else
        std::cout << "No esta ordenada" << std::endl;


  return 0;
}
