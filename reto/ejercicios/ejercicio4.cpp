/*EJERCICIO 4:
Diseñar una función booleana que devuelva true si en una
expresión matemática, los paréntesis, corchetes y llaves, están
colocados de forma correcta. (a cada símbolo abierto le
correspnde uno cerrado del mismo tipo).
*/

#include <iostream>
#include <string>

bool EsFuncionMatematica(std::string cad){
  std::string::iterator p,q;
  std::string aux;
  bool esfuncion = false;

  for(p = cad.begin(); p != cad.end(); p ++){

    if((*p == '(') || (*p == ')') || (*p == '[') || (*p == ']') || (*p == '{') || (*p == '}'))
      aux.push_back(*p);

  }

    q = aux.begin();
    q++;

    p = aux.begin();


    while( q != aux.end()){

      switch (*p) {
        case '(':
          if( *q == ')'){
            esfuncion = true;
            aux.erase(q);
            aux.erase(p);
            p = aux.begin();
            q = aux.begin();
            q ++;
          }else
            esfuncion = false;
          break;
        case '[':
          if( *q == ']'){
            esfuncion = true;
            aux.erase(q);
            aux.erase(p);
            p = aux.begin();
            q = aux.begin();
            q ++;
          }else
            esfuncion = false;
          break;
        case '{':
          if( *q == '}'){
            esfuncion = true;
            aux.erase(q);
            aux.erase(p);
            p = aux.begin();
            q = aux.begin();
            q ++;
          }else
            esfuncion = false;
          break;
      }
      q++;
      p++;
    }

   return esfuncion;
}

int main(int argc, char const *argv[]) {
  std::string cadena = {"{[(3 +2) * 5] / 4} + 4 * (-5)"};

  std::cout << cadena << std::endl;

  if(EsFuncionMatematica(cadena))
    std::cout << "Es función matemática" << std::endl;
    else
      std::cout << "No es función matemática" << std::endl;

  std::string otra = {"{[(3 + 2 * 5] / 4} + 4 * (-5)"};

  std::cout << otra << std::endl;

  if(EsFuncionMatematica(otra))
    std::cout << "Es función matemática" << std::endl;
    else
      std::cout << "No es función matemática" << std::endl;

  return 0;
}
