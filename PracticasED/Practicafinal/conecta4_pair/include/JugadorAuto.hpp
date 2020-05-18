#ifndef __CONECTA4_H__
#define __CONECTA4_H__


#include "ArbolGeneral.hpp"
#include "tablero.hpp"
#include <utility>
#include <cassert>

/**
 * @brief T.D.A. JugadorAuto
 *
 * Una instancia @e c del tipo de datos abstracto @c JugadorAuto es un objeto
 * para representar los posibles movimientos de un tablero del juego "conecta 4",
 * compuestos por un ArbolGeneral de pair donde la pareja esta formada por un entero
 * que representa la jugada insertada y un Tablero donde se ve reflejada el instante
 * de la partida.
 *
 * @author J. Capote, G. Galingo y C. de la Torre
 * @date Enero 2017
 */

class JugadorAuto{
	private:
  	ArbolGeneral<std::pair<int,Tablero> > arbol;  //<Pair formado por un ArbolGeneral de Tableros que representa todos movimientos
		unsigned max_profundidad;											//< Indica el nivel del arbol de tableros

		/**
		 * @brief Crea todos los posibles tableros que surgen de la etiqueta
		 * del nodo que se le pasa, y los engancha como hijos del nodo que se le pasa.
		 * PRECONDICION: El nodo n tiene que ser una hoja.
		 * @param n Nodo al que se le calculan sus hijos.
		 */
		void rellenarNodo(ArbolGeneral<std::pair<int, Tablero> >::Nodo n);

		/**
		 * @brief Rellena el arbol de tableros, nodo a nodo, recursivamente
		 * hasta la profundidad que se le pasa.
		 * @param n Nodo desde el que se Rellena.
		 * @param profundidad Profundidad del arbol a la que se quiere llegar.
		 */
		void rellenarNodoProfundidad(ArbolGeneral<std::pair<int, Tablero> >::Nodo n, unsigned profundidad);

		/**
		 * @brief Rellena el arbol de tableros, con todos los tableros
		 * posibles hasta una profundidad.
		 * @param max_profundidad Indica la profundidad con la que se va
		 * a calcular las posibles jugadas.
		 */
		void rellenarTablero(unsigned profundidad);

		/**
		 * @brief Busca un tablero igual al que se le ha pasado en los nodos
		 * hijos del nodo.
		 * @param  n   Nodo en el que buscar.
		 * @param  tab Tablero a buscar.
		 * @return  Nodo en el que se encuentra el tablero que buscamos.
		 */
		const ArbolGeneral<std::pair<int, Tablero> >::Nodo buscarNodo(ArbolGeneral<std::pair<int, Tablero> >::Nodo n, Tablero tab ) const;

		/**
		 * @brief Busca un tablero igual al pasado en la profundidad que queramos
		 * @param  n           Nodo en el que comenzar la búsqueda
		 * @param  tab         Tablero a buscar
		 * @param  profundidad Profundidad hasta la que buscar
		 * @return             Nodo en el que se encuentra el tablero que buscamos
		 */
		const ArbolGeneral<std::pair<int, Tablero> >::Nodo buscarNodoProfundidad(ArbolGeneral<std::pair<int, Tablero> >::Nodo n, Tablero tab, int profundidad) const;

		/**
		 * @brief Cuenta el número de tableros en un nodo en los que gana el jugador
		 * al que le toca jugar
		 * @param  n Nodo en el que buscar
		 * @return   Numero de tableros
		 */
		int gana(ArbolGeneral<std::pair<int, Tablero> >:: Nodo n);

		/**
		 * @brief Cuenta el número de victorias en un nodo
		 * @param  n Nodo en el que contar.
		 * @return   Número de victorias
		 */
		int contarNumVictorias(ArbolGeneral<std::pair<int, Tablero> >::Nodo n);

		/**
		 * @brief Cuenta el número de derrotas en un nodo
		 * @param  n Nodo en el que contar.
		 * @return   Número de derrotas
		 */
		int contarNumDerrotas(ArbolGeneral<std::pair<int, Tablero> >::Nodo n);

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
		 * @brief Actualiza el arbol de tableros, poniendo como raiz
		 * el Tablero pasado como parámetro.
		 * @param tab tablero del cual se desea empezar a calcular el árbol
		 */
		void actualizar(Tablero tab);

		/**
		 * @brief Busca el lugar en el que meter ficha para ganar, y si
		 * no puede, busca como defenderse para no perder.
		 * @return Número de tableros en los que gana el jugador
		 */
		int metrica_defensiva_simple();

		/**
		 * @brief Busca el lugar en el que meter ficha para ganar, y si
		 * no puede, busca como defenderse para no perder, contando el numero de
		 * derrotas tras cada posible jugada suya
		 * @return Número de tableros en los que gana el jugador
		 */
		int metrica_defensiva();

		/**
		 * @brief Busca el lugar en el que meter ficha para ganar, y si
		 * no puede, busca donde insertar ficha analizando las posibles
		 * partidas para poder ganar.
		 * @return Número de tableros en los que gana el jugador
		 */
		int metrica_ofensiva();

};

#endif
