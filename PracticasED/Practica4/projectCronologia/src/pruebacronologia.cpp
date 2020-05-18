#include <fstream>
#include <iostream>
#include "../include/Cronologia.hpp"

int main(int argc, char * argv[]){

  if (argc!=2){
      std::cout<<"Dime el nombre del fichero con la cronologia"<< std::endl;
      return 0;
   }

   std::ifstream f (argv[1]);
   if (!f){
    std::cout<<"No puedo abrir el fichero "<<argv[1]<< std::endl;
    return 0;
   }

   Cronologia mi_cronologia;
   mi_cronologia.leerCronologia(f);   //Cargamos en memoria, en el traductor.

   mi_cronologia.prettyPrint(std::cout);


   int anio;

   std::cout<<"Dime un año a consultar:";
   std::cin >> anio;

   Fecha fec(anio);

   EventoHistorico mi_evento;

   mi_evento = mi_cronologia.getEventoAnio(fec);

   std::cout << "El evento que se encontro con ese año es: " << std::endl;
   mi_evento.prettyPrint(std::cout);

   std::cout << "Introduzca una fecha para añadir un nuevo evento a nuestra cronologia: " << std::endl;
   std::cin >> anio;

	 char a[1];
	 std::cin.read(a,1);

   EventoHistorico nuevo_evento;
   int entero;

   nuevo_evento.setFecha(anio);

   Acontecimiento mi_acontecimiento;

   do{
     std::cout << "Intrduzca un acontecimiento para añadirlo a nuestro nuevo evento: " << std::endl;
     getline( std::cin, mi_acontecimiento);

     nuevo_evento.addEvento(mi_acontecimiento);

     std::cout << "Introduzca un numero distinto a -1 si quiere seguir añadiendo acontecimientos: " << std::endl;
     std::cin >> entero;

   }while(entero != -1);

   std::cout << "este es el evento historico que vamos a añadir: " << std::endl;

   nuevo_evento.prettyPrint(std::cout);

   mi_cronologia.addEventoHistorico(nuevo_evento);

   std::cout << "mostramos la cronologia con el nuevo evento: " << std::endl;
   mi_cronologia.prettyPrint(std::cout);


   std::cout << "Introduzca una fecha para borrar ese evento de nuestra cronologia: " << std::endl;
   std::cin >> entero;

   Fecha mi_fecha(entero);

   mi_cronologia.eliminarEventoAnio(mi_fecha);

   std::cout << "mostramos la cronologia una vez eliminado el evento" << std::endl;
   mi_cronologia.prettyPrint(std::cout);

   Cronologia vec_eventos;

   std::cout << "introduzca una fecha para restringir (fecha inicial): " << std::endl;
   std::cin >> entero;

   Fecha inicial(entero);

   std::cout << "introduzca una fecha para restringir (fecha final)" << std::endl;
   std::cin >> entero;

   Fecha final(entero);

   vec_eventos = mi_cronologia.restringir(inicial,final);

  vec_eventos.prettyPrint(std::cout);

   std::string palabra;

   std::cout << "introduzca una palabra para buscar los eventos que la contienen: " << std::endl;
   std::cin >> palabra;

   vec_eventos = mi_cronologia.buscar(palabra);

   vec_eventos.prettyPrint(std::cout);
}
