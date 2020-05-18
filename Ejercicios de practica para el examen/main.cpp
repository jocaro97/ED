
#include "./conjuntodeenteros.hpp"

int main(int argc, char const *argv[]) {
  int n;
  conjuntodeenteros a,b;

  std::cout << "Primero conjunto" <<std::endl;

  do{
    std::cout << "escribe un numeor para el primer conjunto:" <<std::endl;
    std::cin >> n;
    a.setentero(n);
    std::cout << "introduzca un numero distinto de -1 para meter mas numero" <<std::endl;
    std::cin >> n;

  }while( n != -1);

  std::cout <<"A:"<<std::endl;
  a.mostrar(std::cout);

  std::cout <<std::endl;

  std::cout << "Segundo conjunto" <<std::endl;

  do{
    std::cout << "escribe un numeor para el segundo conjunto:" <<std::endl;
    std::cin >> n;
    b.setentero(n);
    std::cout << "introduzca un numero distinto de -1 para meter mas numero" <<std::endl;
    std::cin >> n;

  }while( n != -1);

  std::cout <<"A:"<<std::endl;
  a.mostrar(std::cout);

  std::cout <<std::endl;
  std::cout <<"B:"<<std::endl;
  b.mostrar(std::cout);

  std::cout <<std::endl;

  std::cout << "intersección:" <<std::endl;

    conjuntodeenteros interseccion, Union;

    interseccion = a.inteseccion(b);

    interseccion.mostrar(std::cout);

    std::cout <<std::endl;


    std::cout << "union:" <<std::endl;

    Union = a.Union(b);

    Union.mostrar(std::cout);

  return 0;
}
