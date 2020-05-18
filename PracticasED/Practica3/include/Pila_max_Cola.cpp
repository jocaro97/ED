template<class T>
void PilaMax<T>::poner(const T& t_elem){

  if (datos.num_elementos() == 0) {                     // Comprobamos que la lista no este vacia
    Elemento elem(t_elem, t_elem);
    datos.poner(elem);
  }
  else{
    Cola<Elemento> aux;
    Elemento elem;                                      // Declaramos el Elemento que insertaremos en la cola
    elem.elem = t_elem;                                 // Establecemos el dato

    if (t_elem > max())                      // Establemos el maximo comparandolo con el maximo anterior
      elem.max = t_elem;
    else
      elem.max = max();

    aux.poner(elem);                                    // Introducimos el elemento en la cola auxiliar

    while (datos.num_elementos() > 0) {                 // Insertamos cada uno de los elementos que contenia la cola original
      aux.poner(datos.frente());                        //  para mantener el orden
      datos.quitar();                                   // Al final del bucle la cola original se queda vacia
    }

    datos = aux;                                        // Igualamos la cola original a la cola vacia(operador de asig definido en la clase cola)
  }


}
