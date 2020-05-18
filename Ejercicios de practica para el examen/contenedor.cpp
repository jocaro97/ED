/*
(1 punto) Tenemos un contenedor de pares de elementos, {clave, vector<int>} definida
como:
template <typename T>
class contenedor{
private:
unordered_map<T, vector<int> > datos;
.............
.............
}
Implementa un iterador que itere sobre los elementos que cumplan la propiedad de
que la suma de los elementos del vector<int> sea un número impar. Han de
implementarse (aparte de las de la clase iteradora) las funciones begin() y end().
 */

#include <iostream>
#include <cmath>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

template <typename T>
class contenedor{
  private:
    unordered_map<T, vector<int> > datos;

    bool sumaimpar(vector<int> vec){

      vector<int>::iterator q;
      int acumulador = 0;

        for(q = vec.begin(); q != vec.end(); ++q ){
          acumulador += *q;
        }

      if((acumulador % 2) == 0)
        return false;
        else
          return true;
    }

public:

  void insertar(T t, vector<int> vec){
    pair<T, vector<int> > p(t,vec);

    datos.insert(p);
  }

  T devuelveprimero(){
    return datos.first;
  }

  class iterator_impar{
  private:
    typename unordered_map<T, vector<int> >::iterator it;

  public:

    iterator_impar & operator++(){
      ++it;
      while(!sumaimpar(it -> second))
        ++it;

      return *this;
    }

    iterator_impar & operator--(){
      it --;
      while(!sumaimpar(it -> second))
        it --;

      return *this;
    }

    pair<T, vector<int> > operator *(){
      return *it;
    }

    bool operator==(const iterator_impar &i){
      return i.it == it;
    }

    bool operator !=(const iterator_impar &i){
      return i.it != it;
    }

    friend class contenedor;
  };

  iterator_impar begin(){
    contenedor::iterator_impar i;
    i.it = datos.begin();

    if(!sumaimpar(i.it -> second))
      ++i;

    return i;

  }

  iterator_impar end(){
    contenedor::iterator_impar i;

    i.it = datos.end();

    return i;
  }
};

int main(int argc, char const *argv[]) {
  contenedor<int> micontenedor;
  vector<int> aux;

  aux.push_back(1);
  aux.push_back(1);
  aux.push_back(1);

  micontenedor.insertar(1,aux);

  aux.push_back(1);

  micontenedor.insertar(2,aux);

  aux.push_back(1);

  micontenedor.insertar(3,aux);

  aux.push_back(1);

  micontenedor.insertar(4,aux);

  contenedor<int>::iterator p;

  for(p = micontenedor.begin(); p != micontenedor.end(); ++p)
    cout << (*p).first <<" ";

    cout <<endl;





  return 0;
}
