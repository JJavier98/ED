/**
  * @page repConjunto Rep del TDA Pila_Max
  *
  * @section invConjunto Invariante de la representación
  *
  * El invariante es que los elementos introducidos en Pila_Max deben ser enteros
  *
  * @section faConjunto Función de abstracción
  *
  * Un objeto válido @e rep del TDA Pila_Max representa a la dupla
  *
  * (entero_n, entero_máximo {de los n enteros introducidos} )
  *
  */
#define CUAL_COMPILA 2
#if CUAL_COMPILA==1
#include "Pila_VD/Pila_max_VD.h"
#else
#include "Pila_Cola/Pila_max_Cola.h"
#endif