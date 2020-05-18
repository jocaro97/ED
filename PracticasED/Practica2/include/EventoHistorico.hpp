/**
  * @file EventoHistorico.hpp
  * @brief Fichero cabecera del TDA EventoHistorico
  *
  */

#ifndef EVENTO_HISTORICO
#define EVENTO_HISTORICO

#include <iostream>
#include <vector>

struct Fecha{
  int anio;
  bool dc;

  Fecha();
  Fecha(int f);

  bool operator<(Fecha f);
  bool operator>(Fecha f);
  bool operator==(Fecha f);
  bool operator<=(Fecha f);
  bool operator>=(Fecha f);
};

typedef std::string Acontecimiento;

/**
  *  @brief T.D.A. EventoHistorico
  *
  * Una instancia @e c del tipo de datos abstracto @c EventoHistorico es un objeto
  * para agrupar eventos sucedidos en un mismo año, compuestos por un struct Fecha,
  * compuesto este por un entero anio y un booleano para indicar si se refiere a
  * antes o después de cristo, y un vector de tipo string en el que se almacenan
  * los acontecimientos.
  *
  * @author J. Capote, G. Galindo y C. de la Torre
  * @date Octubre 2016
  */

class EventoHistorico{

private:
  /**
    * @page repConjunto Rep del TDA EventoHistorico
    *
    * @section invConjunto Invariante de la representaci�n
    *
    * El invariante es \e rep.f.anio >= 0
    *
    * @section faConjunto Funci�n de abstracci�n
    *
    * Un objeto v�lido @e rep del TDA EventoHistorico representa
    *
    * A un conjunto de acontecimientos (rep.eventos) que sucedieron en
    *
    * el año rep.f.anio
    *
    */
  Fecha f;  /**< Año */
  std::vector<Acontecimiento> evento;  /**< Acontecimientos */

  /**
   * @brief Busca un acontecimiento determinado en el vector de acontecimientos
   * @param a Acontecimiento a buscar
   * @return Posicion del elemento buscado si se encuentra o una posicion no valida si no lo encuenta
   */
  std::vector<Acontecimiento>::iterator busquedaAcontecimiento(Acontecimiento a);

public:

  /**
    * @brief Constructor por defecto de la clase. Crea el evento con el año -1
    * y el vector de acontecimientos vacio.
    */
  EventoHistorico();

  /**
    * @brief Constructor de la clase
    * @param f Fecha del EventoHistorico a construir
    * @return Crea el EventoHistorico con fecha f y ningun evento
    */
  EventoHistorico(Fecha f);

  /**
    * @brief Constructor de la clase
    * @param f año del EventoHistorico a construir
    * @param v Evento del EventoHistorico a construir
    * @return Crea el EventoHistorico con fecha f y los acontecmientos contenidos en v
    */
  EventoHistorico(Fecha f, std::vector<Acontecimiento> v);

  /**
    * @brief Fecha
    * @return Devuelve la fecha del EventoHistorico
    */
  Fecha getFecha() const{return f;}

  /**
    * @brief Evento
    * @return Devuelve el vector de acontecmientos del EventoHistorico
    */
  std::vector<Acontecimiento> getEvento() const{return evento;};

  /**
    * @brief Asignación de una Fecha
    * @param f Fecha del EventoHistorico a asignar
    * @return Asigna al objeto impl�cito la fecha f
    */
  void setFecha(Fecha f);

  /**
    * @brief Asignaci�n de vector de acontecimientos
    * @param v vector de acontecimientos del EventoHistorico a asignar
    * @return Asigna al objeto impl�cito el vector de acontecimientos v
    */
  void setEvento(std::vector<Acontecimiento> v);

  /**
    * @brief Añadir un acontecimiento a evento, comprobando que no este ya incluido
    * @param a acontecimiento a añadir
    * @return Añade al vector evento el acontecimiento a
    */
  void addEvento(Acontecimiento a);

  /**
    * @brief Añadir un conjunto acontecimientos al evento, comprobando que no esten ya incluidos
    * @param evento conjunto de acontecimientos a añadir
    * @return Añade al vector this->evento los acontecimientos de evento
    */
  void addEvento(std::vector<Acontecimiento> evento);

  /**
    * @brief Añadir un conjunto acontecimientos de otro evento al evento, comprobando que no esten ya incluidos
    * @param V evento al que pertenecen los acontecimientos a añadir
    * @return Añade al vector this->evento los acontecimientos del evento v
    * @pre La fecha de v y el evento debe coincidir
    */
  void addEvento(EventoHistorico v);

  /**
    * @brief Eliminar un acontecimiento concreto a evento
    * @param a acontecimiento a eliminar
    * @return Booleano que indica si se ha eliminado o no
    */
  bool eliminarAcontecimiento(Acontecimiento a);

  /**
    * @brief Eliminar acontecimientos que contengan la clave "key" de evento
    * @param key clave que deben contener los acontecimientos a eliminar
    * @return Numero de elementos eliminados
    */
  int eliminar(std::string key);

  /**
    * @brief Busca acontecimientos que contengan la clave "key"
    * @param key string que debe contener los acontecimientos buscados
    * @return Vector de acontecimientos con todos los encontrados en la busqueda
    */
  std::vector<Acontecimiento> buscar(std::string key) const;

  /**
    * @brief Salida de un EventoHistorico a ostream
    * @param os stream de salida
    * @post Se obtiene en \a os la cadena anio#dc#acontemiento#... con \e anio,dc,acontecimiento
    *   el año del evento, si fue antes o despues de cristo y cada uno de sus acontecimientos respectivamente
    */
  std::ostream& mostrarEvento(std::ostream& os) const;

  /**
    * @brief Entrada de un EventoHistorico desde istream
    * @param is stream de entrada
    * @retval El evento historico leido en *this
    * @pre La entrada tiene el formato anio#dc#acontemiento#... con \e anio,dc,acontecimiento el año
    *   del evento, si fue antes o despues de cristo y cada uno de sus acontecimientos respectivamente
    */
  std::istream& leerEvento(std::istream& is);

  /**
    * @brief Salida de un EventoHistorico a ostream
    * @param os stream de salida
    * @post Se obtiene en os la salida en un formato que intuitivo y agradable a la vista
    */
  std::ostream& prettyPrint(std::ostream& os) const;

};

std::ostream& operator<<(std::ostream& os, EventoHistorico a);
std::istream& operator>>(std::istream& is, EventoHistorico a);

#endif
