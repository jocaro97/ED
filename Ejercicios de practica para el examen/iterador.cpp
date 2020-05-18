/*
5.- (1 punto) Implementar un iterador que itere sobre las claves que sean números primos
en una clase Diccionario definida como:
class Diccionario{
private:
map<int, list<string> > datos;
.............
.............
}
Han de implementarse (aparte de las de la clase iterador) las funciones begin() y end().
Se supone implementada una función bool primo (int x) que devuelve true si el entero x
es primo.

 */

#include <iostream>
#include <cmath>
#include <map>
#include <list>
using namespace std;


 class Diccionario{
 private:
 map<int, list<string> > datos;



 public:

   bool primo(int x){
     bool esprimo = true;

     int n = sqrt(x);
     for(int i=2; i<=n; i++){
       if(x % i)
        esprimo = false;
     }

     return esprimo;
   }

   class iterator_primo{
   private:
     map<int, list<string> >::iterator it;

   public:
     iterator_primo & operator++(){
       ++it;
       while(!primo(it -> first))
        ++it;

      return *this;
     }

     iterator_primo & operator--(){
       --it;
       while(!primo(it -> first))
        --it;

      return *this;
     }

     pair<const string,string> &operator *(){
       return *it;
     }
     bool operator ==(const iterator_primo &i){
       return i.it==it;
     }

     bool operator !=(const iterator_primo &i){
       return i.it!=it;
     }
     friend class Diccionario;

   };

   iterator_primo begin(){
      Diccionario::iterator_primo i;
      i.it = datos.begin();

      if(!primo(i.it -> first))
        ++i;

      return i;

   }


 };
