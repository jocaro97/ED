#include <iostream>
#include <set>
#include <ctime>
#include <cstdlib>
using namespace std;


/**
 * @brief Devuelve la intersección de dos conjuntos
 * @param a: primer conjunto
 * @param b: segundo conjunto
 */

set<int> Interseccion(set<int> a, set<int> b){
  set<int>::iterator p;
  set<int> c;

  for(p = a.begin(); p!= a.end(); p++)
    if(b.find(*p) != b.end())
      c.insert(*p);

  return c;
}

/**
 * @brief Devuelve la unión de dos conjuntos
 * @param a: primer conjunto
 * @param b: segundo conjunto
 */

set<int> Union(set<int> a, set<int> b, set<int> c){
  set<int> interab,interac,interbc,result;

  interab = Interseccion(a,b);
  interac = Interseccion(a,c);
  interbc = Interseccion(b,c);

  set<int>::iterator p;

  for(p = interab.begin(); p!= interab.end(); p++)
    if(c.find(*p) == c.end())
      result.insert(*p);

  for(p = interac.begin(); p!= interac.end(); p++)
    if(b.find(*p) == b.end())
      result.insert(*p);

  for(p = interbc.begin(); p!= interbc.end(); p++)
    if(a.find(*p) == a.end())
        result.insert(*p);

  return result;
}
/**
 * @brief Imprime un conjunto de tipo T sobre el flujo de salida
 * @param s: flujo de salida. Es MODIFICADO
 * @param l: el conjunto con los elementos a imprimi
 * */
template <class T>
ostream & operator<<(ostream & s, const set<T> & c){

  typename set<T>::const_iterator i;

  for (i=c.begin(); i != c.end(); i++)
      s << (*i) << " ";

  return s;
}

/**
 * @brief Inicializar el generador de numero aleatorios
 *        Esta funcion debe ser llamada antes de usar rand
**/

void InicializarSemilla(){
  srand(time(0));
}

/**
 * @brief Genera numero enteros positivos aleatorios en el rango [min,max]
**/

int generaEntero(int min, int max){
    int tam= max -min+1;
    return ((rand()%tam)+min);
}
int main(){

  set<int> b,c,a;

  InicializarSemilla();

  for (int i=0;i<10;i++)
    b.insert(generaEntero(1,100)); //inserta un entero generado aleatoriamente en el rango 1-100
  cout<<b<<endl;

  for (int i=0;i<10;i++)
    a.insert(generaEntero(1,100)); //inserta un entero generado aleatoriamente en el rango 1-100
  cout<<a<<endl;

  for (int i=0;i<10;i++)
    c.insert(generaEntero(1,100)); //inserta un entero generado aleatoriamente en el rango 1-100
  cout<<c<<endl;

  cout << "UNION:" <<endl;

  cout << Union(a,b,c) <<endl;

  cout << "INTERSECCION" <<endl;

  cout << Interseccion(a,b) <<endl;





}
