#include "../include/JugadorAuto.hpp"

JugadorAuto::JugadorAuto(const Tablero &t): arbol(t), max_profundidad(0){}

ArbolGeneral<Tablero> JugadorAuto::GetArbol(){
  return arbol;
}

/*
Precondicion: El nodo n tiene que ser una hoja
 */
void JugadorAuto::rellenarNodo(ArbolGeneral<Tablero>::Nodo n){

	if (!arbol.etiqueta(n).quienGana()) {
		ArbolGeneral<Tablero>::Nodo hermano_mas_der;

		for (int i = 0; i < n->etiqueta.GetColumnas(); i++) {
			ArbolGeneral<Tablero> hijo;
			Tablero tablero(n->etiqueta);

			if (tablero.colocarFicha(i)) {
				tablero.cambiarTurno();
				hijo.AsignaRaiz(tablero);

				if (!arbol.hijomasizquierda(n)){
					arbol.insertar_hijomasizquierda(n, hijo);
					hermano_mas_der = arbol.hijomasizquierda(n);
				}
				else{
					arbol.insertar_hermanoderecha(hermano_mas_der, hijo);
					hermano_mas_der = hermano_mas_der->drcha;
				}
			}
		}
	}
}

void JugadorAuto::rellenarNodoProfundidad(ArbolGeneral<Tablero>::Nodo n, unsigned profundidad){
	// Si la profundidad es 0 o negativa salimos del programa
	if (profundidad < 1) {
		printf("Profundidad no valida(<1)\n");
		exit(-1);
	}

	// Rellenamos el nodo pasado como argumento(rellenamos unicamente el nivel justo mas bajo)
	if (!arbol.hijomasizquierda(n)) {
		rellenarNodo(n);
	}

	ArbolGeneral<Tablero>::Nodo aux;

	/*
	Si la profundidad hasta la que hay que rellenar es mayor que 1, llamamos de nuevo a esta funcion
	pasandole como argumento cada nodo hijo de este, y una produndidad una unidad mejor
	 */
	if (profundidad > 1) {
		for(aux = arbol.hijomasizquierda(n); aux != 0; aux = arbol.hermanoderecha(aux)){
			rellenarNodoProfundidad(aux, profundidad-1);
		}
	}
}

void JugadorAuto::rellenarTablero(unsigned profundidad) {
  if (profundidad > max_profundidad) {
    rellenarNodoProfundidad(arbol.raiz(), profundidad);
    max_profundidad = profundidad;
  }
}

//Precondicion: Nodo n esta relleno. Nodo que devuelve cte?
const ArbolGeneral<Tablero>::Nodo JugadorAuto::buscarNodo(ArbolGeneral<Tablero>::Nodo n, Tablero tab ) const{
  ArbolGeneral<Tablero>::Nodo aux;
  for(aux = arbol.hijomasizquierda(n); aux != 0; aux = arbol.hermanoderecha(aux) )
    if(aux->etiqueta == tab)
      return aux;

  return aux;
}

//Precondicion: la profundidad no puede ser negativa. TODO Nodo que devuelve cte?
const ArbolGeneral<Tablero>::Nodo JugadorAuto::buscarNodoProfundidad(ArbolGeneral<Tablero>::Nodo n, Tablero tab, int profundidad) const{
  ArbolGeneral<Tablero>::Nodo aux, resultado;

  resultado = buscarNodo(n, tab);

  if(profundidad > 1){
    for(aux = arbol.hijomasizquierda(n); (aux != 0) && !resultado; aux = arbol.hermanoderecha(aux) ){
      resultado = buscarNodoProfundidad(aux,tab, profundidad-1);
    }
  }

  return resultado;
}

void JugadorAuto::actualizar(Tablero tab){
  ArbolGeneral<Tablero>::Nodo n;
  unsigned profundidad;

  n = buscarNodoProfundidad(arbol.raiz(), tab, max_profundidad);

  if (n) {
    profundidad = max_profundidad;

		ArbolGeneral<Tablero> arbol_aux;
    arbol_aux.asignar_subarbol(arbol, n);
		arbol = arbol_aux;
    max_profundidad = arbol.altura(arbol.raiz());

    rellenarTablero(profundidad);
  }

	else{
		ArbolGeneral<Tablero> nuevo_arbol(tab);
		arbol = nuevo_arbol;
	}

}

int JugadorAuto::gana(ArbolGeneral<Tablero>:: Nodo n){
	ArbolGeneral<Tablero>::Nodo aux;
	unsigned rta = 0, i = 0;
	for(aux = arbol.hijomasizquierda(n); (aux != 0) && !rta; aux = arbol.hermanoderecha(aux), ++i){
		if (arbol.etiqueta(aux).quienGana() == arbol.etiqueta(n).GetTurno())
			rta = i;
	}

	return rta;
}

unsigned JugadorAuto::metrica_defensiva_simple() {
	rellenarTablero(3);

	ArbolGeneral<Tablero>::Nodo aux,n = arbol.raiz();
	int rta;
	std::vector<int> soluciones;
	bool found = false;
	int pierde;

	if ((rta = gana(n))) {
		return rta;
	}

	for(aux = arbol.hijomasizquierda(n); (aux != 0) && !found; aux = arbol.hermanoderecha(aux), ++rta)
		if (!(pierde = gana(aux)))
			soluciones.push_back(rta);

	if (!soluciones.empty())
		return soluciones[soluciones.size()/2];
	else
		return 0;
}

int JugadorAuto::contarNumVictorias(ArbolGeneral<Tablero>::Nodo n){
	if (n) {
		int num_victorias = 0;

		ArbolGeneral<Tablero>::Nodo aux, aux2;
		for(aux = arbol.hijomasizquierda(n); (aux != 0); aux = arbol.hermanoderecha(aux))
			for(aux2 = arbol.hijomasizquierda(aux); (aux2 != 0); aux2 = arbol.hermanoderecha(aux2))
				if (arbol.etiqueta(aux2).quienGana() == arbol.etiqueta(aux).GetTurno())
					++num_victorias;
				else
					num_victorias += contarNumVictorias(aux2);

			return num_victorias;
	}
	else
		return 0;

}

int JugadorAuto::contarNumDerrotas(ArbolGeneral<Tablero>::Nodo n){
	if (n) {
		int num_derrotas = 0;

		ArbolGeneral<Tablero>::Nodo aux, aux2;
		for(aux = arbol.hijomasizquierda(n); (aux != 0); aux = arbol.hermanoderecha(aux))
			if (arbol.etiqueta(aux).quienGana() == arbol.etiqueta(n).GetTurno())
				++num_derrotas;
			else
				for(aux2 = arbol.hijomasizquierda(aux); (aux2 != 0); aux2 = arbol.hermanoderecha(aux2))
					num_derrotas += contarNumDerrotas(aux2);

			return num_derrotas;
	}
	else
		return 0;
}

unsigned JugadorAuto::metrica_ofensiva(){
	rellenarTablero(6);

	ArbolGeneral<Tablero>::Nodo aux,n = arbol.raiz();
	int rta;
	std::vector<int> soluciones, num_victorias;
	bool found = false;
	int pierde;

	if ((rta = gana(n))) {
		return rta;
	}

	for(aux = arbol.hijomasizquierda(n); (aux != 0) && !found; aux = arbol.hermanoderecha(aux), ++rta)
		if (!(pierde = gana(aux))){
			soluciones.push_back(rta);
			num_victorias.push_back(contarNumVictorias(aux));
		}

	if (soluciones.empty()) {
		return 0;
	}

	int max = num_victorias[0];
	rta = soluciones[0];

	for (size_t i = 1; i < soluciones.size(); i++) {
		if (num_victorias[i] > max) {
			max = num_victorias[i];
			rta = soluciones[i];
		}
	}

	return rta;
}

unsigned JugadorAuto::metrica_defensiva(){
	rellenarTablero(6);

	ArbolGeneral<Tablero>::Nodo aux,n = arbol.raiz();
	int rta;
	std::vector<int> soluciones, num_derrotas;
	bool found = false;
	int pierde;

	if ((rta = gana(n))) {
		return rta;
	}

	for(aux = arbol.hijomasizquierda(n); (aux != 0) && !found; aux = arbol.hermanoderecha(aux), ++rta)
		if (!(pierde = gana(aux))){
			soluciones.push_back(rta);
			num_derrotas.push_back(contarNumDerrotas(aux));
		}

	if (soluciones.empty()) {
		return 0;
	}

	int min = num_derrotas[0];
	rta = soluciones[0];

	for (size_t i = 1; i < soluciones.size(); i++) {
		if (num_derrotas[i] < min) {
			min = num_derrotas[i];
			rta = soluciones[i];
		}
	}

	return rta;
}
