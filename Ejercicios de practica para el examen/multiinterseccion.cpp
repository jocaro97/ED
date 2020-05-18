/*
(1 punto) Dados dos multiset con elementos enteros, implementar la función:
multiset<int> multi_interseccion (const multiset<int> & m1, const multiset<int> &m2)
que calcula la intersección de dos multiset: elementos comunes en los dos multiset repetidos tantas
veces como aparezcan en el multiset con menor número de apariciones del elemento.
Por ejemplo siendo m1={2,2,3,3} y m2={1,2,3,3,3,4} entonces m1∩m2={2,3,3} ó
si m1={2,2,2,3,3} y m2={1,2,2,2,2,3,3,3,4} entonces m1∩m2={2,2,2,3,3}
 */


#include <iostream>
#include <cmath>
#include <set>
using namespace std;

multiset<int> multi_interseccion (const multiset<int> & m1, const multiset<int> &m2){
  multiset<int>::iterator p,q;
  multiset<int> aux,copia;

  if(m1.size() < m2.size()){
    copia = m2;
    for(p = m1.begin(); p != m1.end(); ++p){
      if((q = copia.find(*p)) != copia.end()){
        aux.insert(*p);
        copia.erase(q);
      }
    }
  }else{
    copia = m1;
    for(p = m2.begin(); p != m2.end(); ++p){
      if((q = copia.find(*p)) != copia.end()){
        aux.insert(*p);
        copia.erase(q);
      }
    }
  }
  return aux;
}

int main(int argc, char const *argv[]) {
  multiset<int> m1,m2,m3;

  m1.insert(2);
  m1.insert(2);
  m1.insert(3);
  m1.insert(3);

  m2.insert(1);
  m2.insert(2);
  m2.insert(3);
  m2.insert(3);
  m2.insert(3);
  m2.insert(4);

  multiset<int>::iterator i;
  cout << "M1:" <<endl;

  for(i = m1.begin(); i != m1.end(); ++i)
    cout << *i <<" ";

  cout <<endl;

  cout << "M2:" <<endl;

  for(i = m2.begin(); i != m2.end(); ++i)
    cout << *i <<" ";

  cout <<endl;

  m3 = multi_interseccion(m1,m2);

  cout << "M3" <<endl;

  for(i = m3.begin(); i != m3.end(); ++i)
    cout << *i <<" ";

  cout <<endl;

  m1.insert(2);

  m2.insert(2);
  m2.insert(2);
  m2.insert(2);

  cout << "M1" <<endl;
  for(i = m1.begin(); i != m1.end(); ++i)
    cout << *i <<" ";

  cout <<endl;

  cout << "M2:" <<endl;

  for(i = m2.begin(); i != m2.end(); ++i)
    cout << *i <<" ";

  cout <<endl;

  m3 = multi_interseccion(m1,m2);

  cout << "M3" <<endl;

  for(i = m3.begin(); i != m3.end(); ++i)
    cout << *i <<" ";

  cout <<endl;

  return 0;
}
