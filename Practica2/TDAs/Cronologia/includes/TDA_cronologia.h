/**
  * @file TDA_cronologia.h
  * @brief Fichero cabecera del TDA Cronologia
  *
  */

#ifndef __CRONOLOGIA
#define __CRONOLOGIA

#include <iostream>
#include <list>
#include "../../FechaHistorica/includes/TDA_fechahistorica.h"

using namespace std;

/**
  *  @brief T.D.A. Cronologia
  *
  * Una instancia @e f del tipo de datos abstracto @c Cronologia es un objeto
  * que contiene diversas Fechas Históricas ordenadas por año. Es del tipo:
  *
  * año1::#Suceso1#suceso2 ...
  * año2::#OtroSuceso1#otroSuceso2...
  * ...::...
  *
  * Un ejemplo de uso es:
  * @inlude cronologia_exe.cpp
  *
  * @author José Javier Alonso Ramos
  * @date Octubre 2017
  */

class Cronologia {

 private:
/**
  * @page repConjunto Rep del TDA Cronologia
  *
  * @section invConjunto Invariante de la representación
  *
  * El invariante es \e todas las fechas historicas estarán ordenadas de menor a mayor año
  * no puede haber años ficticios y suponemos acontecimientos reales
  *
  * @section faConjunto Función de abstracción
  *
  * Un objeto válido @e rep del TDA Cronologia representa a la lista
  *
  * (FH1, FH2, FH3, ..., FHn) siendo FH = FechaHistórica
  *
  */

  list<FechaHistorica> lista_cronologia; /**< FechasHistóricas ordenadas cronológicamente*/

 public:

/**
  * @brief Constructor por defecto de la clase. Crea un objeto vacío
  */
  Cronologia();

/**
  * @brief Constructor con parámetro FH de la clase
  * @param f Fecha Histórica a incorporar en la lista
  * @pre f Debe cumplir el invariante de FechaHistorica
  */
  Cronologia(const FechaHistorica & f);

/**
  * @brief Constructor con parámetro fichero de una cronología de la clase
  * @param fichero Archivo que contiene una cronología
  * @pre fichero Debe estar escrito en un formato que permita su lectura
  */
  Cronologia(string fichero);

/**
  * @brief Constructor de copias de la clase
  * @param f Cronología a copiar
  */
  Cronologia (const Cronologia& c);  

/**
  * @brief Muestra los sucesos de un determinado año
  * @param os Salida por la que queremos obtener los sucesos
  * @return Muestra los hechos ocurridos en el año señalado cada uno en una linea diferente
  */
  void mostrarSucesosAnio(ostream & os, int an);

/**
  * @brief Adición de Fechas Históricas
  * @param f FechaHistórica que se va a añadir a la Cronologia
  * @return Asigna la Fecha Historica pasada como parámetro a la Cronologia en la que se trabaja
  */   
  void add(FechaHistorica f);

/**
  * @brief Unión de dos Cronologías
  * @param cron_1 Una de las dos cronologías a unir
  * @param cron_2 Segunda y última cronología a unir
  * @return Devuelve otra cronología formada por todas las fechas históricas de las pasadas como parámetros
  */
  friend Cronologia unir(const Cronologia& cron_1, const Cronologia& cron_2);

/**
  * @brief Busca todas las FH de la cronología que contengan la cadena \e palabra
  * @param palabra cadena a buscar entre todas las FH de la cronología
  * @return Devuelve una Lista de FH de la cronología que contengan la cadena \e palabra
  */
  Cronologia buscaPalabra(string palabra);

/**
  * @brief Busca una cadena y muestra las fechas relacionadas
  * @param os Salida por la que queremos obtener los sucesos
  * @param palabra Cadena que buscamos
  * @return Devuelve las fechas históricas completas en las que se ha encontrado la cadena a buscar.
  */
  void buscaPalabraMuestra(ostream & os, string palabra);

/**
  * @brief Busca una cadena y borra las fechas relacionadas
  * @param palabra Cadena que buscamos
  * @return Borra las fechas históricas completas en las que se ha encontrado la cadena a buscar.
  */
  void buscaPalabraBorra(string palabra);

/**
  * @brief Busca todas las FH de la cronología del año: \e anio
  * @param anio Año a buscar entre todas las FH de la cronología
  * @return Devuelve una Lista de FH de la cronología que sean del año: \e anio
  */
  FechaHistorica buscaAnio(int anio);

/**
  * @brief Busca un año y muestra las fechas relacionadas
  * @param os Salida por la que queremos obtener los sucesos
  * @param anio Año que buscamos
  * @return Devuelve la fecha histórica completas del año buscado.
  */
  void buscaAnioMuestra(ostream & os, int anio);

/**
  * @brief Busca un año y borra la fecha relacionada
  * @param anio Año que buscamos
  * @return Borra la fecha histórica completa del año buscado.
  */
  void buscaAnioBorra(int anio);

  /**
  * @brief Compara dos Cronologias
  *	@param c Cronologia a comparar
  * @return Devuelve true si las Cronologias tienen el mismo año
  *
  * this.anio == c.anio
  */
  bool operator==(const Cronologia & c);

/**
  * @brief Salida de un Cronologia a ostream
  * @param os stream de salida
  * @param c Cronologia a escribir
  * @post Se obtiene en \a os el formato FechaHistorica, FechaHistorica, ... separando cada FechaHistorica con un salto de linea
  */
  friend ostream& operator<< (ostream& os, const Cronologia& c);

/**
  * @brief Entrada de un Cronologia desde istream
  * @param is stream de entrada
  * @param c Cronologia que recibe el valor
  * @retval La Cronologia leído en c
  * @pre La entrada tiene el formato FechaHistorica, FechaHistorica, ... separadas por salto de linea
  */
  friend istream& operator>> (istream& is, Cronologia& c);
 
};

#endif
