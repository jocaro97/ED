/*
EJERCICIO 7
Dadas 2 colas con elementos repetidos (y ordenados) implementar la función

  queue<int> multiinterseccion(queve<int> q1, queue<int> q2)

que calcule la multiinterseccion de 2 colas q1 y q2 y devuelva
el resultado en otra cola.
q1:[2,2,3,3]
q2:[1,2,3,3,3,4]
multiinterseccion [2,3,3]
 */

#include<iostream>
#include<queue>

std::queue<int> multiinterseccion(std::queue<int> q1, std::queue<int> q2){
  std::queue<int> aux;

  while(!q1.empty()){

    while(q2.front() < q1.front())
      q2.pop();

    if(q2.front() == q1.front()){
      aux.push(q2.front());
      q2.pop();
    }

    q1.pop();

  }

  return aux;
}

int main(int argc, char const *argv[]) {
  std::queue<int> q1,q2,q3;

  q1.push(2);
  q1.push(2);
  q1.push(3);
  q1.push(3);

  q2.push(1);
  q2.push(2);
  q2.push(3);
  q2.push(3);
  q2.push(3);
  q2.push(4);

  q3 = multiinterseccion(q1,q2);

  std::cout << "Q1: " << std::endl;

  while(!q1.empty()){
    std::cout << q1.front() <<" ";
    q1.pop();
  }

  std::cout << std::endl;

  std::cout << "Q2: " << std::endl;

  while(!q2.empty()){
    std::cout << q2.front() <<" ";
    q2.pop();
  }

  std::cout << std::endl;
  std::cout << "Multiinterseccion: " << std::endl;

  while(!q3.empty()){
    std::cout << q3.front() <<" ";
    q3.pop();
  }

  std::cout << std::endl;

  return 0;
}
