/**
  * @file fechahistorica.h
  * @brief Fichero cabecera del TDA FechaHistorica
  *
  */

#ifndef __FECHA_HISTORICA
#define __FECHA_HISTORICA

#include <iostream>
#include <vector>

using namespace std;

/**
  *  @brief T.D.A. FechaHistorica
  *
  * Una instancia @e f del tipo de datos abstracto @c FechaHistorica es un objeto
  * que contiene diversos sucesos hisóricos agrupados en un mismo año. Es del tipo:
  *
  * año::#Suceso1#suceso2 ...
  *
  * Un ejemplo de uso es:
  * @inlude fechahistorica_exe.cpp
  *
  * @author José Javier Alonso Ramos
  * @date Octubre 2017
  */

class FechaHistorica {

 private:
/**
  * @page repConjunto Rep del TDA FechaHistorica
  *
  * @section invConjunto Invariante de la representación
  *
  * El invariante es \e rep.anio no puede ser mayor al año en que nos encontremos (ej. 2017)
  *
  * @section faConjunto Función de abstracción
  *
  * Un objeto válido @e rep del TDA FechaHistorica representa a la dupla
  *
  * (rep.anio,rep.acontecimientos)
  *
  */

  int anio; /**< año */
  vector<string> acontecimientos; /**< acontecimientos suedidos en anio */

/**
  * @brief Eliminar sucesos repetidos
  * @return elimina los sucesos que se hayan repetido en la Fecha histórica (únicamente si coinciden exactamente)
  */
  void elimina_repetido();

 public:

/**
  * @brief Constructor por defecto de la clase. Crea un objeto con el año de creación del programa
  */
  FechaHistorica();

/**
  * @brief Constructor de la clase
  * @param anio año de la fecha historica a construir
  * @param suceso aconteimiento ocurrido en la feha
  * @return Asocia los sucesos al año en que ocurrieron
  * @pre anio debe ser menor o igual a 2017
  * @pre sucesos Cada acontecimiento va precedido del caracter '#'
  */
  FechaHistorica(int anio, string sucesos);  
/**
  * @brief Constructor de copias de la clase
  * @param f FechaHistórica a copiar
  */
  FechaHistorica (const FechaHistorica& f);  

/**
  * @brief Mostrar Anio
  * @return Devuelve el año de la FechaHistorica
  */ 
  int getAnio ();

/**
  * @brief Mostrar Sucesos
  * @param os Salida por la que queremos obtener los sucesos de nuestra FechaHistorica
  * @return Muestra los hechos ocurridos en la FechaHistorica cada uno en una linea diferente
  */
  void mostrarSucesos(ostream & os);

/**
  * @brief Adición de sucesos
  * @param sucesos Acontecimientos que se van a añadir a la FechaHistorica
  * @return Asigna los sucesos pasados como parámetros a la FechaHistorica en la que se trabaja
  */   
  void add(string sucesos);

/**
  * @brief Eliminacion Trasera
  * @return Elimina el último suceso de la FechaHistorica
  */
  void pop_back();

/**
  * @brief Eliminación Interna
  * @return Elimina el suceso 'n' de la FechaHistorica
  * @pre n debe ser mayor o igual a 1 y menor o igual que el tamaño del vector
  */
  void pop_n(int n);

/**
  * @brief Vector de acontecimientos
  * @return Devuelve el vector de acontecimientos
  */
  vector<string> get_acontecimientos();

/**
  * @brief Fecha1 es menor que Fecha2(?)
  * @param f FechaHistorica a comparar
  * @return Devuelve true si FechaHistórica ocurrió antes que f, 
  *                  false si FechaHistórica ocurrió después de f 
  */   
  bool operator<(const FechaHistorica & f);

  /**
  * @brief Fecha1 es menor ó igual que Fecha2(?)
  * @param f FechaHistorica a comparar
  * @return Devuelve true si FechaHistórica ocurrió antes o a la par que f, 
  *                  false si FechaHistórica ocurrió después de f 
  */   
  bool operator<=(const FechaHistorica & f);

  /**
  * @brief Fecha1 es mayor que Fecha2(?)
  * @param f FechaHistorica a comparar
  * @return Devuelve false si FechaHistórica ocurrió antes que f, 
  *                  true si FechaHistórica ocurrió después de f 
  */   
  bool operator>(const FechaHistorica & f);

  /**
  * @brief Fecha1 es mayor ó igual que Fecha2(?)
  * @param f FechaHistorica a comparar
  * @return Devuelve false si FechaHistórica ocurrió antes que f, 
  *                  true si FechaHistórica ocurrió después o a la par que f 
  */   
  bool operator>=(const FechaHistorica & f);

  /**
  * @brief Compara dos FechaHistoricas
  *	@param f FechaHistorica a comparar
  * @return Devuelve true si las FechaHistoricas tienen el mismo año
  *
  * this.anio == f.anio
  */
  bool operator==(const FechaHistorica & f);

/**
  *
  *
  */
  FechaHistorica & operator=(const FechaHistorica & f);

/**
  * @brief Salida de un FechaHistorica a ostream
  * @param os stream de salida
  * @param f FechaHistorica a escribir
  * @post Se obtiene en \a os el formato ANIO#sucesos con \e ANIO el año
  *   en que ocurrieron los \e sucesos de \a f
  */
  friend ostream& operator<< (ostream& os, const FechaHistorica& f);

/**
  * @brief Entrada de un FechaHistorica desde istream
  * @param is stream de entrada
  * @param f FechaHistorica que recibe el valor
  * @retval El FechaHistorica leído en f
  * @pre La entrada tiene el formato ANIO#sucesos con \e ANIO el año
  *   en que ocurrieron los \e sucesos de \a f
  */
  friend istream& operator>> (istream& is, FechaHistorica& f);
 
};

#endif
