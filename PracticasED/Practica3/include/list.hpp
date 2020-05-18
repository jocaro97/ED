/**
  * @file List.h
  * @brief Fichero cabecera del TDA List
  *
  * Gestiona una secuencia de elementos con facilidades para la inserci�n y
  * borrado de elementos en cualquier punto de la misma
  */
#ifndef LIST_
#define LIST_
/**
 *  @brief T.D.A. List
 *
 *
 * Una instancia @e c del tipo de dato abstracto List sobre un dominio @e T es
 * una sucesi�n finita de elementos del mismo. En una Lista, las operaciones de inserci�n tienen
 * lugar en cualquier punto de la misma. Una lista de longitud @e n la denotamos
 * - <a1,a2,a3,..,an<
 * En esta lista, tendremos acceso a todos los elementos.
 *
 * Si n=0 diremos que la lista est� vac�a.
 *
 * El espacio requerido para el almacenamiento es O(n), donde n es el n�mero
 * de elementos de la lista.
 *
 * @author J.Capote , G.Galindo y C. de la Torre
 * @date Noviembre 2016
*/

template<class T>
class List{
	private:
		/**
	    * @page repConjunto Rep del TDA List
	    *
	    * @section invConjunto Invariante de la representaci�n
	    *
	    * El invariante es \e rep.cab apunte a una celda vacia cuyo campo
	    * siguiente apunte a la primera celda con un elemento válido y
	    * \e rep.ultima apunte a la ultima celda con un elemento valido y el
	    * campo siguiente apunte a "0"
	    *
	    * @section faConjunto Funci�n de abstracci�n
	    *
	    * Un objeto v�lido @e rep del TDA List reprensenta a un conjunto de
	    * elementos del tipo template T siendo el primer elemento de la lista
	    * rep.cab->siguiente->elemento y el ultimo rep.ultima->elemento
	    *
	    */
	  struct Celda {
	  	T elemento;        ///< Elemento de informaci�n.
	    Celda *siguiente;  ///< Puntero al siguiente nodo.

	    /**
	     * @brief Constructor por defecto
	     */
	    Celda() : siguiente(0){
	    }
	    /**
	     * @brief Constructor con par�metros
	     * @param elem Elemento de informaci�n.
	     * @param sig Puntero al siguiente nodo.
	     */
	    Celda(const T & elem, Celda * sig): elemento(elem), siguiente(sig){
	    }
	  };

		Celda *cab; ///< Puntero al primer nodo de la lista.
		Celda *ultima; ///< Puntero al �ltimo nodo de la lista.
	public:
	 /**
    	  * @brief Constructor por defecto
   	  */
		List();
	/**
    	 * @brief Constructor de copias
  	 * @param l La lista de la que se har� la copia.
 	 */
		List(const List& l);
	/**
	 * @brief Destructor
	 */
		~List();
	/**
    	 * @brief Operador de asignaci�n
   	 * @param l La lista que se va a asignar.
    	 */
		List& operator=(const List& l);
	/**
   	 * @brief Comprueba si la lista est� vac�a
	 * @return devuelve un booleano
  	 */
		bool vacia()const;
	/**
     	 * @brief Añade un elemento al final de la lista
     	 */
		void pushback(T elem);
	/**
     	 * @brief Elimina el último elemento de la lista
     	 */
		void popback();
	/**
     	 * @brief Devuelve el último elemento de la lista
     	 */
		T& getLast();
	/**
     	 * @brief Devuelve el último elemento de la lista (constante)
     	 */
		const T& getLast()const;

};

#include "list.cpp"

#endif
