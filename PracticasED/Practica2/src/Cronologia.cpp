#include "Cronologia.hpp"
#include <sstream>

/*
Private
 */

void Cronologia::insertaEvento(EventoHistorico v){

  if (eventos.empty())
    eventos.push_back(v);
  else{
    bool insertado = false;

    for (std::vector<EventoHistorico>::iterator p = eventos.begin(); p != std::prev(eventos.end()) && !insertado; ++p){
      if (std::next(p)->getFecha() > v.getFecha()) {
        eventos.insert(p, v);
        insertado = true;
      }
      else if (std::next(p)->getFecha() == v.getFecha()) {
        std::next(p)->addEvento(v);
        insertado = true;
      }
    }
    if (!insertado)
      eventos.push_back(v);
  }


}

std::vector<EventoHistorico>::iterator Cronologia::getPos(Fecha f){
  std::vector<EventoHistorico>::iterator p = eventos.begin();
  bool encontrado = false;

  while (p != eventos.end() && !encontrado) {
    if (p->getFecha() == f) {
      encontrado = true;
    }
    else
      ++p;
  }

  return p;
}

std::vector<EventoHistorico>::const_iterator Cronologia::getPos(Fecha f)const {
  std::vector<EventoHistorico>::const_iterator p = eventos.begin();
  bool encontrado = false;

  while (p != eventos.end() && !encontrado) {
    if (p->getFecha() == f) {
      encontrado = true;
    }
    else
      ++p;
  }

  return p;
}

/*
Constructores
 */

Cronologia::Cronologia(EventoHistorico evento){
  insertaEvento(evento);
}

Cronologia::Cronologia(std::vector<EventoHistorico> v){
  setEventoHistorico(v);
}

/*
Set&Get
 */

void Cronologia::setEventoHistorico(std::vector<EventoHistorico> v){
  eventos.clear();

  for (std::vector<EventoHistorico>::iterator p = v.begin(); p != v.end() ; ++p)
    insertaEvento(*p);
}

void Cronologia::addEventoHistorico(EventoHistorico a){
  insertaEvento(a);
}

void Cronologia::addEventoHistorico(std::vector<EventoHistorico> v){
  for (std::vector<EventoHistorico>::iterator p = v.begin(); p != v.end() ; ++p)
    addEventoHistorico(*p);
}

Fecha Cronologia::getPrimerAnio()const{
  return eventos.begin()->getFecha();
}

Fecha Cronologia::getUltimoAnio()const{
  return std::prev(eventos.end())->getFecha();
}

EventoHistorico Cronologia::getEventoAnio(Fecha f)const{
  if (getPos(f) != eventos.end())
    return *getPos(f);
  else{
    EventoHistorico no_valido;
    return no_valido;
  }
}

/*
Eliminar y busqueda
 */

bool Cronologia::eliminarEventoAnio(Fecha f){
  bool eliminado = false;

  if (getPos(f) != eventos.end()){
    eventos.erase(getPos(f));
    eliminado = true;
  }

  return eliminado;
}

std::vector<EventoHistorico> Cronologia::restringir(Fecha f, Fecha l)const{
  std::vector<EventoHistorico>::const_iterator inicio = eventos.begin();
  std::vector<EventoHistorico>::const_iterator final = std::prev(eventos.end());

  while (inicio != std::prev(eventos.end()) && inicio->getFecha() < f) {
    ++inicio;
  }
  while (final != eventos.begin() && final->getFecha() > l) {
    --final;
  }

  std::vector<EventoHistorico> v;

  for (std::vector<EventoHistorico>::const_iterator p = inicio; p != final; ++p)
    v.push_back(*p);

  v.push_back(*final);

  return v;
}

std::vector<EventoHistorico> Cronologia::buscar(std::string key)const{
  std::vector<EventoHistorico> v;

  for (std::vector<EventoHistorico>::const_iterator p = eventos.begin(); p != eventos.end(); ++p){
    if (!(p->buscar(key).empty())) {
      EventoHistorico evento(p->getFecha(),p->buscar(key));
      v.push_back(evento);
    }
  }
  return v;
}


/*
E/S
 */

std::ostream& Cronologia::mostrarCronologia(std::ostream& os) const{
  for (std::vector<EventoHistorico>::const_iterator p = eventos.begin(); p != eventos.end() ; ++p){
    os << *p;
  }

  return os;
}

std::istream& Cronologia::leerCronologia(std::istream& is){
  eventos.clear();
  std::string str;
  EventoHistorico a;

  while (std::getline(is,str)) {
    std::stringstream ss(str);
    a.leerEvento(ss);
    insertaEvento(a);

  }

  return is;
}

std::ostream& Cronologia::prettyPrint(std::ostream& os) const{
  for (std::vector<EventoHistorico>::const_iterator p = eventos.begin(); p != eventos.end() ; ++p){
    p->prettyPrint(os);
  }

  return os;
}
