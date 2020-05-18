#include "../include/EventoHistorico.hpp"
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

bool Fecha::operator<(Fecha f) const{
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

bool Fecha::operator>(Fecha f) const{
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

bool Fecha::operator==(Fecha f) const{
  return ((anio == f.anio) && (dc == f.dc));
}

bool Fecha::operator<=(Fecha f) const{
  return (*this < f) || (*this == f);
}

bool Fecha::operator>=(Fecha f) const{
  return (*this > f) || (*this == f);
}

/*
Constructores
 */

EventoHistorico::EventoHistorico(){
  evento.first.anio = -1;
  evento.first.dc = 1;
}

EventoHistorico::EventoHistorico(Fecha f){
  setFecha(f);
}

EventoHistorico::EventoHistorico(Fecha f, std::set<Acontecimiento> s){
  evento.first = f;
  evento.second = s;
}

/*
Iterators & more
 */

 EventoHistorico::iterator EventoHistorico::begin(){
	 return evento.second.begin();
 }
 EventoHistorico::const_iterator EventoHistorico::cbegin()const{
	 return evento.second.cbegin();
 }
 EventoHistorico::iterator EventoHistorico::end(){
	 return evento.second.end();
 }
 EventoHistorico::const_iterator EventoHistorico::cend()const{
	 return evento.second.cend();
 }

/*
Set y get
 */

void EventoHistorico::setFecha(Fecha f) {
  evento.first = f;
}

void EventoHistorico::setEvento(std::set<Acontecimiento> s){
  evento.second = s;
}

void EventoHistorico::addEvento(Acontecimiento a){
  if (busquedaAcontecimiento(a) == evento.second.end()) {
    evento.second.insert(a);
  }
}

void EventoHistorico::addEvento(std::set<Acontecimiento> evento){
  for (std::set<Acontecimiento>::iterator p = evento.begin(); p != evento.end(); ++p){
    addEvento(*p);
  }
}

void EventoHistorico::addEvento(EventoHistorico v){
  assert(this->getFecha() == v.evento.first);

  addEvento(v);
}

/*
Busqueda y borrado
 */

std::set<Acontecimiento>::iterator EventoHistorico::busquedaAcontecimiento(Acontecimiento a){
  bool encontrado = false;
  std::set<Acontecimiento>::iterator p = evento.second.begin();

  while (p != evento.second.end() && !encontrado) {
    if (*p == a)
      encontrado = true;
    else
      ++p;
  }

  return p;
}

std::set<Acontecimiento> EventoHistorico::buscar(std::string key) const{
  std::set<Acontecimiento> v;

  for (std::set<Acontecimiento>::const_iterator p = evento.second.cbegin(); p != evento.second.end(); ++p){
    if (p->find(key) != std::string::npos) {
      v.insert(*p);
    }
  }

  return v;
}

bool EventoHistorico::eliminarAcontecimiento(Acontecimiento a){
  if (busquedaAcontecimiento(a) != evento.second.end()) {
    evento.second.erase(busquedaAcontecimiento(a));

    return true;
  }
  else
    return false;
}

int EventoHistorico::eliminar(std::string key){
  std::set<Acontecimiento>::iterator p = evento.second.begin();
  int acontecimientos_eliminados = 0;

  while (p != evento.second.end()) {
    if (p->find(key) != std::string::npos) {
      evento.second.erase(p);
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
   os << evento.first.anio << '#' << evento.first.dc;
   for (std::set<Acontecimiento>::const_iterator p = evento.second.cbegin(); p != evento.second.end(); ++p){
     os << '#' << *p;
   }

   return os;
 }

std::istream& EventoHistorico::leerEvento(std::istream& is){
  std::string a;

  std::getline(is, a, '#');
  evento.first.anio= std::stol(a);

  std::getline(is, a, '#');
  evento.first.dc= std::stoi(a);

  std::getline(is, a);

  std::stringstream ss(a);

  while (std::getline(ss, a, '#')) {
    evento.second.insert(a);
  }

  return is;
}

std::ostream& EventoHistorico::prettyPrint(std::ostream& os) const{
  os << "Año: " << evento.first.anio;
  if (evento.first.dc)
    os << "dc";
  else
    os << "ac";

  os << '\n';

  for (std::set<Acontecimiento>::const_iterator p = evento.second.cbegin(); p != evento.second.end(); ++p){
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
