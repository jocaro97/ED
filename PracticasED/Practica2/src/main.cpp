/*Programa para probar la clase evento historico */

#include <iostream>
#include <cmath>
#include <fstream>
#include "EventoHistorico.hpp"

int main(int argc, char const *argv[]) {
  EventoHistorico f;
  if(argc == 2){
    std::ifstream flujo (argv[1]);

    if (!flujo) {
      std::cout << "No puedo abrir el fichero." <<std::endl;
    }

    f.leerEvento(flujo);
    std::cout << "Se leyó bien" <<std::endl;
    f.prettyPrint(std::cout);

    std::string palabra;

    std::cout << "introduzca un palabra para buscar" <<std::endl;
    std::cin >> palabra;

    std::vector<Acontecimiento> nuevo;
    nuevo = f.buscar(palabra);

    std::vector<Acontecimiento>::iterator p = nuevo.begin();

    while(p != nuevo.end()){
      std::cout << *p <<" ";
      ++p;
    }

    std::cout << std::endl;

    std::cout << "introduzca una palabra o letra para borrar todos los aocntecimientos que la contengan" <<std::endl;
    std::cin >> palabra;

    f.eliminar(palabra);

    f.prettyPrint(std::cout);


  }else{

    int entero;
    Acontecimiento palabra;
    Acontecimiento otro;
    std::string letra;

    std::cout << "introduzca una fecha: " << std::endl;
    std::cin >> entero;

    f.setFecha(entero);
    std::cout << "introduzca un acontecimiento: ";
    std::cin >> otro;
    f.addEvento(otro);

    do {
      std::cout << "introduzca un acontecimiento: ";
      std::cin >> palabra;
      f.addEvento(palabra);

      std::cin.ignore();
      std::cout << "si quiere introducir más acontecimientos escriba un numero distinto a -1:" << std::endl;
      std::cin >> entero;

    } while(entero != -1);


  f.prettyPrint(std::cout);
  std::cout << "eliminamos la palabra: "<<otro <<std::endl;

  f.eliminarAcontecimiento(otro);
  f.prettyPrint(std::cout);

  std::cout << "introduzca una palabra o una letra para borrar los acontecimientos que la contengan" << std::endl;
  std::cin >> letra;

  f.eliminar(letra);

  f.prettyPrint(std::cout);

  }


   return 0;
}
