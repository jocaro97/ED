/*EJERCICIO 1:
Usando la clase list<T>, construir una función que permita
"duplicar" una lista intercalando alternativamente tras cada
elemento en la posición i, el elemento que esta en la posición
n-i-1 (i=0, 1, ..., n-1).
Ejemplo 1:
lista inicial = (a,b,c,d)
lista final = (a,d,b,c,c,b,d,a)
Ejemplo 2:
lista inicial: (1,2,3,4,5)
lista final: (1,5,2,4,3,3,4,2,5,1)
*/

#include <iostream>
#include <list>

template <class T>
std::list<T> duplicarEspecial(std::list<T> lista) {
  std::list<T> aux;

  typename std::list<T>::iterator p;
  typename std::list<T>::reverse_iterator q;
  q = lista.rbegin();

  for(p = lista.begin(); p != lista.end(); p++ ){
    aux.push_back(*p);
    aux.push_back(*q);
    q++;
  }
  return aux;
}


int main(int argc, char const *argv[]) {
  std::list<int> lista1, lista1final;
  std::list<char> lista2, lista2final;

  for(int i=1; i<6; i++)
    lista1.push_back(i);

  for(char j='a'; j < 'e'; j++)
    lista2.push_back(j);

  std::cout << "Lista 1 inicial:" << std::endl;

  std::list<int>::iterator p;
  for(p = lista1.begin(); p != lista1.end(); p++)
    std::cout << *p << " ";

  std::cout << std::endl;

  std::cout << "Lista 1 final: " << std::endl;
  lista1final = duplicarEspecial(lista1);
  for(p = lista1final.begin(); p != lista1final.end(); p++ )
    std::cout << *p << " ";

    std::cout << std::endl;
    std::cout << "Lista 2 inicial:" << std::endl;

    std::list<char>::iterator q;
    for(q = lista2.begin(); q != lista2.end(); q++)
      std::cout << *q << " ";

    std::cout << std::endl;

    std::cout << "Lista 2 final: " << std::endl;
    lista2final = duplicarEspecial(lista2);
    for(q = lista2final.begin(); q != lista2final.end(); q++ )
      std::cout << *q << " ";



  return 0;
}
