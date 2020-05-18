/*
(1 punto) Construye una clase agenda que de soporte al manejo de información del
tipo persona: <nombre, num_telefono, direccion>. Los nombre son todos distintos y se
tiene que poder buscar de forma eficiente tanto por nombre como por número de
teléfono o dirección. Además de en tiempo también debe ser eficiente en espacio.
Implementa las funciones: persona buscar_nombre(string nom), persona
buscar_telefono(string num), void insertar(persona p)
 */

#include <iostream>
#include <cmath>
#include <unordered_map>
using namespace std;

struct Persona{
  string nombre;
  string direccion;
  string numero;
};

class agenda{
private:

unordered_map<string, Persona> name;
unordered_map<string, Persona> num;
unordered_map<string, Persona> dir;

public:

  Persona buscar_nombre(string nom){

    unordered_map<string, Persona>::iterator it;
    it = name.find(nom);

    return it -> second;
  }

  Persona buscar_telefono(string number){
    unordered_map<string, Persona>::iterator it;
    it = num.find(number);

    return it -> second;
  }

  void insertar(Persona p){
    name[p.nombre] = p;
    num[p.numero] = p;
    dir[p.direccion] = p;
  }

};

int main(int argc, char const *argv[]) {
  Persona p;
  p.nombre = "Johanna";
  p.numero = "699342069";
  p.direccion = "Pintor Velazquez";

  agenda miagenda;

  miagenda.insertar(p);

  p.nombre = "Silka";
  p.numero = "666666666";
  p.direccion = "al lado de mi cama";

  miagenda.insertar(p);

  cout << "Buscamos por el nombre de Johanna" <<endl;

  p = miagenda.buscar_nombre("Johanna");

  cout << p.nombre <<endl;
  cout << p.numero <<endl;
  cout << p.direccion <<endl;

  cout << "Buscamos por numero 666666666" <<endl;

  p = miagenda.buscar_telefono("666666666");

  cout << p.nombre <<endl;
  cout << p.numero <<endl;
  cout << p.direccion <<endl;

  return 0;
}
