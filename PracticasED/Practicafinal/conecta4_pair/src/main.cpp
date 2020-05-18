#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <unistd.h>
#include <termio.h>     // Linux/Windows users
//#include <termios.h>    // Mac OSX users

#include "ArbolGeneral.hpp"
#include "../include/tablero.hpp"
#include "mando.hpp"
#include "../include/JugadorAuto.hpp"

using namespace std;

/******************************************************************************/
/**
 * @brief Captura el caracter pulsado por teclado (sin necesidad de pulsar, a continuación, Enter).
 * @return: Caracter pulsado (char).
 */
char getch() {
        char buf = 0;
        struct termios old = {0};
        if (tcgetattr(0, &old) < 0)
                perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if (tcsetattr(0, TCSANOW, &old) < 0)
                perror("tcsetattr ICANON");
        if (read(0, &buf, 1) < 0)
                perror ("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if (tcsetattr(0, TCSADRAIN, &old) < 0)
                perror ("tcsetattr ~ICANON");
        return (buf);
}

/******************************************************************************/
/**
 * @brief Imprime en pantalla el tablero completo, con el mando y el jugador.
 * @param t : Tablero que se va a imprimir.
 * @param m : Mando indicando la posición del jugador.
 */
void imprimeTablero(Tablero & t, Mando & m){
    cout << m.GetJugador() << endl;
    cout << t ;
    cout << m.GetBase() << endl;
    cout << m.GetMando() << endl;
}

/******************************************************************************/
/**
 * @brief Implementa el desarrollo de una partida de Conecta 4 sobre un tablero 5x7, pidiendo por teclado los movimientos de ambos jugadores según turno.
 * @return : Identificador (int) del jugador que gana la partida (1 o 2).
 */
int jugar_partida(int fil, int col, int metrica, int turno) {

    Tablero tablero(fil, col);      //Tablero 5x7
    Mando mando(tablero);       //Mando para controlar E/S de tablero
		JugadorAuto j2(tablero);
    char c = 1;
    int jugada;
    int quienGana = tablero.quienGana();

    if(turno == 1){
      //mientras no haya ganador y no se pulse tecla de terminación
      while(c != Mando::KB_ESCAPE && quienGana == 0) {
  				if (tablero.GetTurno() == 1) {
  					system("clear");
  	        mando.actualizarJuego(c, tablero);  // actualiza tablero según comando c
  	        imprimeTablero(tablero, mando);     // muestra tablero y mando en pantalla
  	        quienGana = tablero.quienGana();    // hay ganador?
  	        if(quienGana==0) c = getch();       // Capturamos la tecla pulsada.
  				}
  				else{
  					system("clear");
            j2.actualizar(tablero);
            switch (metrica) {
              case 1:
              jugada = j2.metrica_defensiva();
              break;
              case 2:
              jugada = j2.metrica_ofensiva();
              break;
              case 3:
              jugada = j2.metrica_defensiva_simple();
              break;

            }
            if (!tablero.colocarFicha(jugada)) {
  						printf("Error al colocar la ficha en la pos %d\n", jugada);
  					}
  					tablero.cambiarTurno();
  					imprimeTablero(tablero, mando);
  					quienGana = tablero.quienGana();
          }

  				}
    }else{
      while(c != Mando::KB_ESCAPE && quienGana == 0) {
  				if (tablero.GetTurno() == 1) {
  					system("clear");
            j2.actualizar(tablero);
            switch (metrica) {
              case 1:
              jugada = j2.metrica_defensiva();
              break;
              case 2:
              jugada = j2.metrica_ofensiva();
              break;
              case 3:
              jugada = j2.metrica_defensiva_simple();
              break;

  				}
          if (!tablero.colocarFicha(jugada)) {
            printf("Error al colocar la ficha en la pos %d\n", jugada);
          }
          tablero.cambiarTurno();
          imprimeTablero(tablero, mando);
          quienGana = tablero.quienGana();
        }
  				else{
  					system("clear");
            mando.actualizarJuego(c, tablero);  // actualiza tablero según comando c
  	        imprimeTablero(tablero, mando);     // muestra tablero y mando en pantalla
  	        quienGana = tablero.quienGana();    // hay ganador?
  	        if(quienGana==0) c = getch();       // Capturamos la tecla pulsada.

            }
  				}
        }


    return tablero.quienGana();
}

int main(int argc, char *argv[]){

    if(argc == 5){
      int filas = atoi(argv[1]);
      int columnas = atoi(argv[2]);
      int metrica = atoi(argv[3]);
      int turno = atoi(argv[4]);
      int ganador = jugar_partida(filas,columnas,metrica,turno);
      cout << "metrica: " <<metrica<<endl;

      cout << "Ha ganado el jugador " << ganador << endl;
    }else{
      int ganador = jugar_partida(5,7,1,1);
      cout << "Ha ganado el jugador " << ganador << endl;
    }

}
