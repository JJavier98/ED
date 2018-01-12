/**
  * @file Pila_max_VD.h
  * @brief Fichero cabecera del TDA Pila_Max implementado con VectorDinamico
  *
  */
#ifndef _PILA_MAX_VD
#define _PILA_MAX_VD

#include "../../VD/VDG.h"

using namespace std;

/**
  *  @brief Tipo de elemento almacenado por el TDA Pila_Max
  *
  * Una instancia @e i de la estructura @c interior_pila es un objeto
  * que contiene una dupla de dos enteros:
  *
  * (entero_1, entero_2)
  *
  * La intención del diseño es usar:
  * entero_1 = elemento tope de la pila
  * entero_2 = elemento máximo de la pìla
  *
  */
struct interior_pila
{
	int elemento;    ///< entero_1 = elemento tope de la pila
	int max_actual;  ///< entero_2 = elemento máximo de la pìla

  /**
    * @brief Flujo de salida para la estructura @c interior_pila
    * @param os Indicará donde se mostrará la salida de información.
    * @param p Objeto de @c interior_pila a mostrar.
    */
	friend ostream& operator<< (ostream& os, const interior_pila& p);
};

/**
  *  @brief T.D.A. Pila_Max (VectorDinamico)
  *
  * Una instancia @e p del tipo de datos abstracto @c Pila_Max es un objeto
  * que contiene una lista de enteros acompañados del máximo valor introducido hasta el momento implementada en un Vector Dinamico.
  * Dado que es una pila solo podremos consultar el elemento del tope.
  * Se presenta de la siguiente manera:
  *
  * (entero_tope, máximo_pila)
  *
  * Un ejemplo de uso es:
  * @include Pila_Max.cpp
  *
  * @author José Javier Alonso Ramos
  * @date Noviembre 2017
  */
class Pila_Max{
private:
	
	VectorDinamico <interior_pila> vect; ///< Contenedor usado como pila (T.D.A. VectorDinamico)
	int elem_util;                       ///< número de elemntos dentro de la pila
	
public:
  /**
    * @brief Constructor por defecto
    */
	Pila_Max();

  /**
    * @brief Destructor
    */
	~Pila_Max();

  /**
    * @brief Retorna el máximo de la pila
    */
	int max();

  /**
    * @brief Retorna el entero del tope de la pila
    */
	int tope();

  /**
    * @brief Retorna el número de elementos en la pila
    */
	int util() const;

  /**
    * @brief Elimina el último elemento de la pila
    */
	void quitar();

  /**
    * @brief Añade un elemento al tope de la pila
    * @ param elem Elemento a añadir
    */
	void poner(int elem);

  /**
    * @brief Retorna si la pila está vacia(?)
    */
	bool vacia() const;

  /**
    * @brief Retorna la dupla (elemento, máximo) del tope de la pila
    */
	interior_pila topeCompleto();

};

#include "Pila_max_VD.cpp"

#endif