/**
  * @file Pila_max_Cola.h
  * @brief Fichero cabecera del TDA Pila_max_Cola
  *
  */
#ifndef PILA_MAX_
#define PILA_MAX_

#include "cola.hpp"

/**
  *  @brief T.D.A. Pila_mx_Cola
  *
  * Una instancia @e c del tipo de datos abstracto @c Pila_max_Cola es un objeto
  * para agrupar datos de tipo Elemento en una Pila, compuesto Elemento por dos
  * objetos: elem y max,ambos de tipo T. La clase está compuesta por una Cola
  * de Elementos.
  *
  * @author J. Capote, G. Galindo y C. de la Torre
  * @date ONoviembre 2016
  */
template <class T>
class PilaMax{
	/**
		* @page repConjunto Rep del TDA PilaMax
		*
		* @section invConjunto Invariante de la representaci�n
		*
		* El invariante es \e rep.datos sea una lista, un vector dinamico o una
		* cola que cumpla su respectivo invariante de representacion, y que el tipo
		* de dato T tenga definido un orden(operadores >, <, >=, <=)
		*
		* @section faConjunto Funci�n de abstracci�n
		*
		* Un objeto v�lido @e rep del TDA PilaMax representa a una estructura de
		* datos de tipo T en la que unicamente se tiene accesso al ultimo elemento
		* introducido y de la que conocemos el maximo.
		*
		*/
  private:
  /**
    * @page repConjunto Rep del TDA Pila_max_Cola
    *
    * @section faConjunto Funci�n de abstracci�n
    *
    * Un objeto v�lido @e rep del TDA Pila_max_Cola representa
    *
    * A un conjunto de Elementos agrupados en una Cola
    *
    */
    struct Elemento{
      T elem;
      T max;

   /**
    * @brief Constructor por defecto de Elemento. Crea el elemento
    * con elem=0 y max=0.
    */
      Elemento(){}
   /**
    * @brief Constructor de Elemento. Crea el elemento con elem=e y
    * max=m.
    * @param e dato de tipo T que da el valor de elem
    * @param m dato de tipo T que da el valor de max
    */
      Elemento(T e, T m): elem(e), max(m){}
    };/**< Elemento */

    Cola<Elemento> datos; /**< Cola de Elementos */

  public:
  /**
    * @brief Constructor por defecto de la clase. Crea el la Cola vacía.
    */
    PilaMax<T>(){}
  /**
    * @brief Constructor pcopia de la clase.
    * @param p objeto a copiar
    */
    PilaMax<T>(const PilaMax<T>& p):datos(p.datos){}

  /**
    * @brief Operador de asignacion.
    * @param p objeto a asignar.
    */

    PilaMax<T>& operator=(const PilaMax<T>& p){
      datos = p.datos;
    }

     /**
     * @brief Comprueba si la pila está vacía
     * @return bool verdadero si está vacía y falso si no lo está.
     */

    bool vacia() const{return datos.vacia();}
    /**
     * @brief Añade un nuevo elemento a la cola de la pila
     * @param t_elem valor del nuevo elemento a añadir
     */

    void poner(const T& t_elem);
    /**
     * @brief Elimina el útimo elemento de la pila
     */
    void quitar(){datos.quitar();}
    /**
     * @brief Devolver el tope de la pila
     * @return devuelve el valor del último elemento introducido en la pila
     */
    T tope() const{return datos.frente().elem;}
    /**
     * @brief Devolver el valor maximo de los elementos de la pila
     * @return devuelve el valor del maximo elemento de toda la pila
     */
    T max() const{return datos.frente().max;}
};

#include "Pila_max_Cola.cpp"

#endif
