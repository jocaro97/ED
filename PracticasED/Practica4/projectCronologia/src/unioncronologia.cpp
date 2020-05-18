#include "../include/Cronologia.hpp"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){

  if (argc!=3 && argc!=4){
      cout<<"Error: debe dar al menos los nombres de dos ficheros con cronologías. "<<endl;
      cout<<"[Opcional]: un tercer nombre de fichero para guardar la cronología resultante."<<endl;
      return 0;
   }

   ifstream f1 (argv[1]);
   if (!f1){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }
   ifstream f2 (argv[2]);
   if (!f2){
    cout<<"No puedo abrir el fichero "<<argv[2]<<endl;
    return 0;
   }

   Cronologia c1, c2;


   c1.leerCronologia(f1);    // Cargamos los datos de los ficheros en las cronologías.
   c2.leerCronologia(f2);

   c1.unionCronologia(c2);

   std::cout << "despues de la union" <<std::endl;


   if (argc==3)   //No se dio fichero de salida, imprimimos en cout
      c1.prettyPrint(std::cout);
   else{
     ofstream fout(argv[3]);
     if (!fout){
      cout<<"No puedo crear el fichero "<<argv[3]<<endl;
      return 0;
     }
     c1.mostrarCronologia(fout);

   }
}
