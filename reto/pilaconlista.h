/**
 * @file pilaconlista.h
 * @brief clase pila implementada con la estructura de una lista
 */

#ifndef _PILA_H_
#define _PILA_H_

#include <list>

/**
 * @breif clase pila
 *
 * La clase pila de ls stl implementada con una lista de la stl.
 * Para conesguirlo utilizaremos la lista como pila siendo
 * la primera posición de la lista la base de la pila
 * y el último elemento de la lista el tope de la pila.
 *
 * @author Johanna Capote Robayna
 * @date 29 Noviembre 2016
 */
template <class T>

class Pila{
private:
  std::list<T> lista_priv;

public:

  /**
   * @brief contructor por defecto de Pila.
   */
  Pila(){}

  /**
   * @brief Inserta un elemento en la lista.
   * @param elemento valor del nuevo elemento a añadir.
   */
 void poner(T elemento){lista_priv.push_back(elemento);}

 /**
  * @brief Elimina el último elemento de la pila
  */
 void quitar(){lista_priv.pop_back();}

 /**
  * @brief Devuelvo el tope de la pila, pero no lo saca de ella.
  * @return devuelve el últimio elmento introducido en la pila
  */

 T tope(){return lista_priv.back();}

 /**
  * @brief comprueba si la pila esta vacía
  * @return bool verdadero si está vacía y falso si no lo está
  */

 bool vacia(){return lista_priv.empty();}


};

#endif
