#include "EventoHistorico.hpp"
#include <sstream>
#include <cassert>

/*
Constructores Fecha
 */

Fecha::Fecha(){
  anio = -1;
  dc = 1;
}

Fecha::Fecha(int f){
  anio = f;
  dc = 1;
}

/*
Operadores Fecha
 */

bool Fecha::operator<(Fecha f){
  bool rta;
  if (dc == 1) {
    if (f.dc == 0)
      rta = false;
    else
      rta = this->anio < f.anio;
  }
  else{
    if (f.dc == 1)
      rta = true;
    else
      rta = this->anio < f.anio;
  }
  return rta;
}

bool Fecha::operator>(Fecha f){
  bool rta;
  if (dc == 1) {
    if (f.dc == 0)
      rta = true;
    else
      rta = this->anio > f.anio;
  }
  else{
    if (f.dc == 1)
      rta = false;
    else
      rta = this->anio > f.anio;
  }
  return rta;
}

bool Fecha::operator==(Fecha f){
  return ((anio == f.anio) && (dc == f.dc));
}

bool Fecha::operator<=(Fecha f){
  return (*this < f) || (*this == f);
}

bool Fecha::operator>=(Fecha f){
  return (*this > f) || (*this == f);
}


/*
Constructores
 */
EventoHistorico::EventoHistorico(){
  f.anio = -1;
  f.dc = 1;
}

EventoHistorico::EventoHistorico(Fecha f){
  setFecha(f);
}

EventoHistorico::EventoHistorico(Fecha f, std::vector<Acontecimiento> v):evento(v){
  setFecha(f);
}

/*
Set y get
 */

void EventoHistorico::setFecha(Fecha f) {
  this->f = f;
}

void EventoHistorico::setEvento(std::vector<Acontecimiento> v){
  this->evento = v;
}

void EventoHistorico::addEvento(Acontecimiento a){
  if (busquedaAcontecimiento(a) == evento.end()) {
    evento.push_back(a);
  }
}

void EventoHistorico::addEvento(std::vector<Acontecimiento> evento){
  for (std::vector<Acontecimiento>::iterator p = evento.begin(); p != evento.end(); ++p){
    addEvento(*p);
  }
}

void EventoHistorico::addEvento(EventoHistorico v){
  assert(this->getFecha() == v.f);

  addEvento(v.evento);
}


/*
Busqueda y borrado
 */

std::vector<Acontecimiento>::iterator EventoHistorico::busquedaAcontecimiento(Acontecimiento a){
  bool encontrado = false;
  std::vector<Acontecimiento>::iterator p = evento.begin();

  while (p != evento.end() && !encontrado) {
    if (*p == a)
      encontrado = true;
    else
      ++p;
  }

  return p;
}

std::vector<Acontecimiento> EventoHistorico::buscar(std::string key) const{
  std::vector<Acontecimiento> v;

  for (std::vector<Acontecimiento>::const_iterator p = evento.begin(); p != evento.end(); ++p){
    if (p->find(key) != std::string::npos) {
      v.push_back(*p);
    }
  }

  return v;
}

bool EventoHistorico::eliminarAcontecimiento(Acontecimiento a){
  if (busquedaAcontecimiento(a) != evento.end()) {
    evento.erase(busquedaAcontecimiento(a));

    return true;
  }
  else
    return false;
}

int EventoHistorico::eliminar(std::string key){
  std::vector<Acontecimiento>::iterator p = evento.begin();
  int acontecimientos_eliminados = 0;

  while (p != evento.end()) {
    if (p->find(key) != std::string::npos) {
      evento.erase(p);
      ++acontecimientos_eliminados;
    }
    else
      ++p;
  }

  return acontecimientos_eliminados;
}

/*
E/S
 */

std::ostream& EventoHistorico::mostrarEvento(std::ostream& os) const{
   os << f.anio << '#' << f.dc;
   for (std::vector<Acontecimiento>::const_iterator p = evento.begin(); p != evento.end(); ++p){
     os << '#' << *p;
   }

   return os;
 }

std::istream& EventoHistorico::leerEvento(std::istream& is){
  std::string a;

  std::getline(is, a, '#');
  f.anio= std::stoi(a);

  std::getline(is, a, '#');
  f.dc= std::stoi(a);

  std::getline(is, a);

  std::stringstream ss(a);

  while (std::getline(ss, a, '#')) {
    evento.push_back(a);
  }

  return is;
}

std::ostream& EventoHistorico::prettyPrint(std::ostream& os) const{
  os << "Año: " << f.anio;
  if (f.dc)
    os << "dc";
  else
    os << "ac";

  os << '\n';

  for (std::vector<Acontecimiento>::const_iterator p = evento.begin(); p != evento.end(); ++p){
    os << "  -"<< *p << std::endl;
  }

   return os;
}

std::ostream& operator<<(std::ostream& os, EventoHistorico a){
   return a.mostrarEvento(os);
}


std::istream& operator>>(std::istream& is, EventoHistorico a){
  return a.leerEvento(is);
}
