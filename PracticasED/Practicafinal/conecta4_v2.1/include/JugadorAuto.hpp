#ifndef __CONECTA4_H__
#define __CONECTA4_H__


#include "ArbolGeneral.hpp"
#include "tablero.hpp"
#include <cassert>

/**
 * @brief T.D.A. JugadorAuto
 *
 */

class JugadorAuto{
	private:
  	ArbolGeneral<Tablero> arbol;    //< Arbol de tableros que representa todos movimientos
		unsigned max_profundidad;			//< Indica el nivel del arbol de tableros

		/**
		 * @brief Crea todos los posibles tableros que surgen de la etiqueta
		 * del nodo que se le pasa, y los engancha como hijos del nodo que se le pasa.
		 * PRECONDICION: El nodo n tiene que ser una hoja.
		 * @param n Nodo al que se le calculan sus hijos.
		 */
		void rellenarNodo(ArbolGeneral<Tablero>::Nodo n);

		/**
		 * @brief Rellena el arbol de tableros, nodo a nodo, recursivamente
		 * hasta la profundidad que se le pasa.
		 * @param n Nodo desde el que se Rellena.
		 * @param profundidad Profundidad del arbol a la que se quiere llegar.
		 */
		void rellenarNodoProfundidad(ArbolGeneral<Tablero>::Nodo n, unsigned profundidad);

		/**
		 * @brief Busca un tablero igual al que se le ha pasado en los nodos
		 * hijos del nodo.
		 * @param  n   Nodo en el que buscar.
		 * @param  tab Tablero a buscar.
		 * @return  Nodo en el que se encuentra el tablero que buscamos.
		 */
		const ArbolGeneral<Tablero>::Nodo buscarNodo(ArbolGeneral<Tablero>::Nodo n, Tablero tab ) const;

		/**
		 * @brief Busca un tablero igual al pasado en la profundidad que queramos
		 * @param  n           Nodo en el que comenzar la búsqueda
		 * @param  tab         Tablero a buscar
		 * @param  profundidad Profundidad hasta la que buscar
		 * @return             Nodo en el que se encuentra el tablero que buscamos
		 */
		const ArbolGeneral<Tablero>::Nodo buscarNodoProfundidad(ArbolGeneral<Tablero>::Nodo n, Tablero tab, int profundidad) const;

		/**
		 * @brief Cuenta el número de tableros en un nodo en los que gana el jugador
		 * al que le toca jugar
		 * @param  n Nodo en el que buscar
		 * @return   Numero de tableros
		 */
		int gana(ArbolGeneral<Tablero>:: Nodo n);

		/**
		 * @brief Cuenta el número de victorias en un nodo
		 * @param  n Nodo en el que contar.
		 * @return   Número de victorias
		 */
		int contarNumVictorias(ArbolGeneral<Tablero>::Nodo n);

		/**
		 * @brief Cuenta el número de derrotas en un nodo
		 * @param  n Nodo en el que contar.
		 * @return   Número de derrotas
		 */
		int contarNumDerrotas(ArbolGeneral<Tablero>::Nodo n);

	public:
		/*
		Constructores
		 */

		 /**
			* @brief Constructor vacio. Crea un arbol vacio de tableros.
			*/
  	JugadorAuto():max_profundidad(0){}

		/**
		 * @brief Constructor. Crea un arbol de tableros, cuya raiz
		 * es el tablero que se le pasa.
		 * @param t: tablero que será la raiz de arbol de tableros.
		 */
  	JugadorAuto(const Tablero &t);

		/**
		 * @brief Devuelve el arbol de tableros.
		 * IMPORTANTE: Esta función esta pendiente de revisión, la estamos usando
		 * para probar si funcionan los metodos de la clase, extrayendo
		 * el arbol y mostrandolo por pantalla.
		 * @return Devuelve el arbol de la clase.
		 */
		ArbolGeneral<Tablero> GetArbol();	// TODO Esta funcion no deberia de existir. Solo pruebas

		/**
		 * @brief Rellena el arbol de tableros, con todos los tableros
		 * posibles hasta una profundidad.
		 * @param max_profundidad Indica la profundidad con la que se va
		 * a calcular las posibles jugadas.
		 */
		void rellenarTablero(unsigned profundidad); // TODO Esta funcion es privada. Esta aquí para pruebas

		/**
		 * [actualizar description]
		 * @param tab [description]
		 */
		void actualizar(Tablero tab);

		/**
		 * @brief Busca el lugar en el que meter ficha para ganar, y si
		 * no puede, busca como defenderse para no perder.
		 * @return Número de tableros en los que gana el jugador
		 */
		unsigned metrica_defensiva_simple();

		/**
		 * @brief Busca el lugar en el que meter ficha para ganar, y si
		 * no puede, busca como defenderse para no perder, con la diferencia
		 * que analiza la jugada en más niveles.
		 * @return Número de tableros en los que gana el jugador
		 */
		unsigned metrica_defensiva();
		
		/**
		 * @brief Busca el lugar en el que meter ficha para ganar, y si
		 * no puede, busca donde insertar ficha analizando las posibles
		 * partidas para poder ganar
		 * que analiza la jugada en más niveles.
		 * @return Número de tableros en los que gana el jugador
		 */
		unsigned metrica_ofensiva();

};

#endif
