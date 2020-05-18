
#ifndef _GUIA_H_
#define _GUIA_H_

#include <string>
#include <set>
#include <iostream>


class conjuntodeenteros{
private:
  std::set<int> numeros;

public:
  conjuntodeenteros();

  conjuntodeenteros(int numero);

  void setentero(int numero);

  conjuntodeenteros inteseccion(conjuntodeenteros otro);

  conjuntodeenteros Union(conjuntodeenteros otro);

  std::ostream& mostrar(std::ostream& is)const;

};

#endif
