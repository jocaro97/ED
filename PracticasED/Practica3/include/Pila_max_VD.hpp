/**
  * @file Pila_max_VD.h
  * @brief Fichero cabecera del TDA Pila_max_VD
  *
  */#ifndef PILA_MAX
#define PILA_MAX

#include "vector_dinamico.hpp"
/**
  *  @brief T.D.A. Pila_mx_VD
  *
  * Una instancia @e c del tipo de datos abstracto @c Pila_max_VD es un objeto
  * para agrupar datos de tipo Elemento en una Pila, compuesto Elemento por dos
  * objetos: elem y max,ambos de tipo T. La clase está compuesta por uN vector dinamico
  * de Elementos.
  *
  * @author J. Capote, G. Galindo y C. de la Torre
  * @date Noviembre 2016
  */
template <class T>
class PilaMax{
	/**
		* @page repConjunto Rep del TDA PilaMax
		*
		* @section invConjunto Invariante de la representaci�n
		*
		* Mismo que en Pila_max_Cola.hpp
		*
		* @section faConjunto Funci�n de abstracci�n
		*
		* Misma que en Pila_max_Cola.hpp
		*
		*/
  private:
   /**
    * @page repConjunto Rep del TDA Pila_max_VD
    *
    * @section faConjunto Funci�n de abstracci�n
    *
    * Un objeto v�lido @e rep del TDA Pila_max_VD representa
    *
    * A un conjunto de Elementos agrupados en una vector dinamico
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

    VectorDinamico<Elemento> datos;/** vectos dinamico de Elementos */

  public:
   /**
    * @brief Constructor por defecto de la clase. Crea el vectordinamico vacío.
    */
    PilaMax<T>(){}
    /**
    * @brief Constructor copia de la clase.
    * @param p objeto a copiar
    */
    PilaMax<T>(const PilaMax<T>& p):datos(p.datos){}
  /**
    * @brief Operador de asignacion.
    * @param p objeto a asignar.
    */
    PilaMax<T>& operator=(const PilaMax<T>& p){datos = p.datos;}
   /**
     * @brief Comprueba si la pila está vacía
     * @return bool verdadero si está vacía y falso si no lo está.
     */
    bool vacia() const{return datos.vacia();}
   /**
     * @brief Añade un nuevo elemento al vector dinamico de la pila
     * @param t_elem valor del nuevo elemento a añadir
     */
    void poner(const T& t_elem);
  /**
     * @brief Elimina el útimo elemento de la pila
     */
    void quitar(){datos.popback();}
  /**
     * @brief Devolver el tope de la pila
     * @return devuelve el valor del último elemento introducido en la pila
     */
    T tope() const{return datos.getLast().elem;}
   /**
     * @brief Devolver el valor maximo de los elementos de la pila
     * @return devuelve el valor del maximo elemento de toda la pila
     */
    T max() const{return datos.getLast().max;}
};

#include "Pila_max_VD.cpp"


#endif
