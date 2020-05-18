/**
 * @file Pila_max.h
 * @brief Fichero cabecera para insertar la implementación deseada
 *
 * Permite modificar la implementación de Pila max mediante un numero del 1 a 3
 * 1. Para la implementación mediante una lista
 * 2. Para la implementación mediandte un vector dinamico
 * 3. Para la implementación mediante una cola
 */

#ifndef _PILA_MAX_H_
#define _PILA_MAX_H_

#define CUAL_COMPILO 2

#if CUAL_COMPILO == 1
  #include "Pila_max_List.hpp"
#elif CUAL_COMPILO == 2
  #include "Pila_max_VD.hpp"
#else
  #include "Pila_max_Cola.hpp"

#endif
#endif
