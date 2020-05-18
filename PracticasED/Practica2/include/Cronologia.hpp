/**
  * @file Cronologia.hpp
  * @brief Fichero cabecera del TDA Cronologia
  *
  */

#ifndef CRONOLOGIA_
#define CRONOLOGIA_

#include <iostream>
#include <vector>
#include "EventoHistorico.hpp"

/**
  *  @brief T.D.A. Cronologia
  *
  * Una instancia @e c del tipo de datos abstracto @c Cronologia es un objeto
  * para agrupar un conjunto de eventos historicos, compuestos por un vector de
  * EventoHistoricos.
  *
  * @author J. Capote, G. Galindo y C. de la Torre
  * @date Octubre 2016
  */

class Cronologia{
  private:

/**
  * @page repConjunto Rep del TDA Cronologia
  *
  * @section invConjunto Invariante de la representación
  *
  * El invarante de representacion es \e rep.eventos sea un vector de eventosHistoricos correctos y este ordenado
  *
  * @section faConjunto Función de abstracción
  *
  * Un objeto válido @e rep del TDA Cronologia representa a un conjunto
  *
  * de EventoHistoricos ordenado
  *
  */
    std::vector<EventoHistorico> eventos; /**< Eventos historicos */

    /**
     * @brief Inserta un EventoHistorico en eventos de manera ordenada
     * @param v EventoHistorico a añadir en eventos
     */

    void insertaEvento(EventoHistorico v);
    /**
     * @brief Busca la posicion del EventoHistorico de Fecha f en el vector(Metodo no constante)
     * @param f Fecha del EventoHistorico a buscar
     * @return posicion en el vector del EventoHistorico buscado
     */
    std::vector<EventoHistorico>::iterator getPos(Fecha f);
    /**
     * @brief Busca la posicion de un EventoHistorico en el vector(Metodo constante)
     * @param f Fecha del EventoHistorico a buscar
     * @return posicion en el vector del EventoHistorico buscado
     */
    std::vector<EventoHistorico>::const_iterator getPos(Fecha f)const;
  public:
    /**
      * @brief Constructor por defecto de la clase. Crea la Cronologia vacía.
      */
    Cronologia(){}
    /**
      * @brief Constructor de la clase
      * @param evento EventoHistorico con el que crear la clase
      * @return Crea la Cronologia con un solo EventoHistorico
      */
    Cronologia(EventoHistorico evento);
    /**
      * @brief Constructor de la clase
      * @param v vector de EventoHistoricoS con los que crear la clase
      * @return Crea la Cronologia a partir de un vector de EventoHistoricos
      */
    Cronologia(std::vector<EventoHistorico> v);

    /**
     * @brief devolver los eventos de la Cronologia
     * @return devuelve un vector con todos los EventoHistoricoS de la Cronologia
     */

    std::vector<EventoHistorico> getEventos()const {return eventos;}

      /**
        * @brief Reemplaza los eventos de la cronologia por los de
        * otro vector de EventoHistoricos
        * @param v vector de EventoHistoricoS a añadir
        * @return Reemplaza los eventos de la cronologia por los de
        * v
        */
    void setEventoHistorico(std::vector<EventoHistorico> v);
    /**
      * @brief Añadir un EventoHistorico en caso de que no este repetido
      * @param a EventoHistorico a añadir
      * @return Añade al objeto un EventoHistorico
      */
    void addEventoHistorico(EventoHistorico a);
    /**
      * @brief Añadir unvector de EventoHistoricoS
      * @param v vector de EventoHistoricoS a añadir
      * @return Añade al objeto un vector de EventoHistoricoS
      */
    void addEventoHistorico(std::vector<EventoHistorico> v);
    /**
      * @brief Devuelve el primer año de la cronología
      * @return Devuelve el año en el que comienza la cronología
      */
    Fecha getPrimerAnio()const;
    /**
      * @brief Devuelve el último año de la cronología
      * @return Devuelve el año en el que termina la cronología
      */
    Fecha getUltimoAnio()const;
    /**
      * @brief Devuelve el evento del año f
      * @param f Fecha del evento solicitado
      * @return Devuelve el evento o eventos ocurridos en el año f
      */
    EventoHistorico getEventoAnio(Fecha f)const;
    /**
      * @brief Eliminar un EventoHistorico
      * @param f Fecha del EventoHistorico a eliminar
      * @return Devuelve un booleano true si se ha eliminado el EventoHistorico
      * correctamente o false si no se ha eliminado correctamente
      */
    bool eliminarEventoAnio(Fecha f);
    /**
     * @brief Restringe la cronología
     * @param f primera fecha de la nueva cronología
     * @param l última fecha de la nueva cronología
     * @return devuelve un vector con los eventos de los eventos
     * pertenecientes a la cronologia restringida al intervalo f-l
     */
    std::vector<EventoHistorico> restringir(Fecha f, Fecha l)const;
    /**
     * @brief Busca EventoHistorico con una determinada palabra
     * @param key palabra que debe contener los acontecimientos buscados
     * @return devuelve un vector de eventos en cuyos acontecimientos aparece "key"
     */
    std::vector<EventoHistorico> buscar(std::string key)const;
    /**
      * @brief Entrada de una cronología desde el flujo de entrada istream
      * @param is stream de entrada
      * @retval La cronología leida en *this
      */
    std::istream& leerCronologia(std::istream& is);
    /**
      * @brief Salida de una Cronología a ostream
      * @param os stream de salida
      */
    std::ostream& mostrarCronologia(std::ostream& os) const;
    /**
      * @brief Salida de una Cronologia a ostream
      * @param os stream de salida
      * @post Se obtiene en os la salida en un formato intuitivo y agradable a la vista
      */
    std::ostream& prettyPrint(std::ostream& os) const;


};

#endif
