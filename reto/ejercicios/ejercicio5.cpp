/*EJERCICIO 5:
Diseñar una funcion
queue<int> barajas(queue<int> q1, queue<int>q2)
que devuelva una cola mezcla de q1 y q2, de forma que en
la cola de salida los ejementos de q2 ocupen la posiciones
impares y los ejementos de q1 las posiciones pares.
*/

#include<iostream>
#include<queue>

std::queue<int> barajas(std::queue<int> q1, std::queue<int> q2){
  std::queue<int> aux;

  while(!(q1.empty()) && !(q2.empty())){
    aux.push(q2.front());
    q2.pop();

    aux.push(q1.front());
    q1.pop();

  }

  if(!(q1.empty())){
    aux.push(q1.front());
    q1.pop();
  }

  if(!(q2.empty())){
    aux.push(q2.front());
    q2.pop();
  }

  return aux;
}

int main(int argc, char const *argv[]) {
  std::queue<int> uno,dos;

  for (int i=1; i<8; i++){
    if((i % 2) == 0)
      uno.push(i);
    else
      dos.push(i);
  }
  std::queue<int> resultado = barajas(uno,dos);

  while( !(resultado.empty())){
    std::cout << resultado.front() << std::endl;
    resultado.pop();

  }

  std::cout << "Segunda prueba" << std::endl;

  resultado = barajas(dos,uno);

  while( !(resultado.empty())){
    std::cout << resultado.front() << std::endl;
    resultado.pop();

  }

  return 0;
}
