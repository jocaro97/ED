/* programa para llevar la dependencias de conjuntodeenteros */

#include "./conjuntodeenteros.hpp"

conjuntodeenteros::conjuntodeenteros(){

}

conjuntodeenteros::conjuntodeenteros(int numero){
  numeros.insert(numero);
}

void conjuntodeenteros::setentero(int numero){
  numeros.insert(numero);
}

conjuntodeenteros conjuntodeenteros::inteseccion(conjuntodeenteros otro){
  conjuntodeenteros resultado;

  std::set<int>::iterator p,q;

  for(p = otro.numeros.begin(); p != otro.numeros.end(); p++){
    for(q = numeros.begin(); q != numeros.end(); q++){

        if(*p == *q)
          resultado.setentero(*p);
    }
  }

  return resultado;
}

conjuntodeenteros conjuntodeenteros::Union(conjuntodeenteros otro){
  conjuntodeenteros resultado;

  std::set<int>::iterator p,q;

  for(p = otro.numeros.begin(); p != otro.numeros.end(); p++)
    resultado.setentero(*p);

  for(q = numeros.begin(); q != numeros.end(); q++)
    resultado.setentero(*q);

  return resultado;
}

std::ostream& conjuntodeenteros::mostrar(std::ostream& os)const{
  std::set<int>::iterator p;

  for(p = numeros.begin(); p != numeros.end(); p++)
    os << *p <<" ";

  return os;
}
