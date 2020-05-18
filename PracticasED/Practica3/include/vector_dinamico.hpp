/**
  * @file Vcetor_dinamico.h
  * @brief Fichero cabecera del TDA Vcetor_dinamico
  *
  * Gestiona una secuencia de elementos con facilidades para la inserci�n y
  * borrado de elementos en cualquier punto del vector
  */
#ifndef VECTOR_DINAMICO_
#define VECTOR_DINAMICO_

/**
 *  @brief T.D.A. Vcetor_dinamico
 *
 *
 * Una instancia @e c del tipo de dato abstracto Vector_dinamico sobre un dominio @e T es
 * una sucesi�n finita de elementos del mismo. Una vector-dinamico de longitud @e n la denotamos
 * - <a1,a2,a3,..,an<
 *
 * Si n=0 diremos que el vector est� vacío.
 *
 * El espacio requerido para el almacenamiento es O(n), donde n es el n�mero
 * de elementos de la cola.
 *
 * @author J.Capote, G. Galindo y C. de la Torre
 * @date
*/

template<class T>
class VectorDinamico{
	/**
		* @page repConjunto Rep del TDA VectorDinamico
		*
		* @section invConjunto Invariante de la representaci�n
		*
		* El invariante es que \e rep.numelem >= 0, rep.reservados >= rep.numelem
		* y rep.datos se array con memoria para albergar rep.reservados elementos.
		*
		* @section faConjunto Funci�n de abstracci�n
		*
		* Un objeto v�lido @e rep del TDA List reprensenta a un conjunto de
		* rep.numelem elementos del tipo template T consecutivos en memoria
		*
		*/
	private:
		T *datos; /**< Puntero a datos*/
		int numelem; /**< Número de elementos del vector*/
		int reservados; /**< Numero de elementos reseados*/

	public:
		/**
		* @brief constructor por defecto.
		*/
		VectorDinamico<T>(int n = 0);
		/**
		* @brief constructor copia de la clase.
		* @param v Vector a copiar
		*/
		VectorDinamico<T>(const VectorDinamico<T>& v);
		/**
		* @brief operador de asignación
		* @param v Vector a asignar
		*/
		VectorDinamico<T>& operator=(const VectorDinamico& v);

		/**
		* @brief devuelve el tamaño del vector
		* @return devuelve el valor de numelem
		*/
		int size(){return numelem;}
		/**
		*@brief devuelve la capacidad del vector
		*@return devuelve el valor de reservados
		*/
		int capacity(){return reservados;}
		/**
		*@brief operador corchete
		*@param i posicion de la que se desea saber el elemento
		*@return devuelve el elemento que se encuentra en la posicion i
		*/
		T& operator[](int i);
		/**
		*@brief operador corchete
		*@param i posicion de la que se desea saber el elemento
		*@return devuelve el elemento que se encuentra en la posicion i
		*/
		const T& operator[](int i) const;
		/**
		*@brief Cambia el tamaño del vector
		*@param n nuevo tamaño del vector
		*/
		void resize(int n);
		/**
		*@brief reserva un tamaño distinto de memoria
		*@param n tamaño de la nueva reserva
		*/
		void reserve(int n);
		/**
		*@brief comprueba si el vecor esta vacío
		*@return devuelve un booleano
		*/
		bool vacia()const{return numelem == 0;}

		/**
		*@brief añade un nuevo elemento al final del vector
		*@param elem nuevo elemento a añadir
		*/
		void pushback(T elem);
		/**
		*@brief elimina el último elemento del vector
		*/
		void popback();
		/**
		*@brief devuelve el último elemento del vector
		*@return devuelve un elemento de tipo T
		*/
		T& getLast();
		/**
		*@brief devuelve el último elemento del vector
		*@return devuelve un elemento de tipo T
		*/
		const T& getLast()const;

};

#include "vector_dinamico.cpp"


#endif
