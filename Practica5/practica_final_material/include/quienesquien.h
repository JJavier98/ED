/**
 * @file quienesquien.h
 * @brief Fichero cabecera del QuienEsQuien.
 *
 * Almacena el �rbol de preguntas para jugar al �Qui�n es qui�n?.
 */

#ifndef _QUIENESQUIEN_H_
#define _QUIENESQUIEN_H_

#define DEBUG_QUIENESQUIEN 0

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <cassert>
#include <set>
#include <sstream>

#include "pregunta.h"
#include "bintree.h"

using namespace std;

/**
 * @brief T.D.A. QuienEsQuien
 *
 * Conjunto de personajes con sus atributos.
 */
class QuienEsQuien{
private:
	/**
	  * @brief Almacena el nombre de los personajes. Su �ndice en 
	  *        este vector corresponde con el �ndice de su 
	  *        descripci�n en el tablero.
	  */
	vector<string> personajes;

	/**
	  * @brief Almacena los atributos.  Su �ndice en este vector 
	  *        corresponde con el �ndice correspondiente de cada 
	  *        vector del tablero.
	  */
	vector<string> atributos;

	/**
	  * @brief Matriz que almacena para cada personaje su valor para 
	  *        cada atributo.
	  */
	vector< vector<bool> > tablero;

	/**
	  * @brief Arbol de preguntas para adivinar personajes.
	  */
	bintree<Pregunta> arbol;

	/**
	  * @brief Nodo del arbol de preguntas correspondiente a la jugada 
	  *        actual.
	  */
	bintree<Pregunta>::node jugada_actual;

	/**
	 * @brief devuelve si el nodo n es el hijo izquierdo de su padre
	 * @param n nodo del que preguntamos si es hijo izquierda de su padre
	 */
	bool es_izquierda(bintree<Pregunta>::node n)
	{
		return n.parent().left() == n;
	}

	/**
	  * @brief Vacia todos los datos del QuienEsQuien receptor.
	  */
	void limpiar();

	/**
	 * @brief Devuelve el número de personajes que comparten el atributo pasado como parámetro
	 * @param col Columna referente a un atributo
	 */
	int contar_true_en_columna(int col);

	/**
	 * @brief Devuelve el número de personajes que no muestran el atributo pasado como parámetro
	 * @param col Columna referente a un atributo
	 */
	int contar_false_en_columna(int col);

	/**
	 * @brief E/S que pregunta si quiere iniciar una nueva partida
	 */
	bool nueva_partida();

	/**
	 * @brief E/S que pregunta si quiere continuar con el juego o ver los personajes restantes
	 */
	bool menu();

	/**
	 * @brief E/S que pregunta si el personaje buscado tiene un determinado atributo
	 */
	bool tiene_el_atributo();

  public:
	/**
	  * @brief Constructor b�sico de la clase
	  */
	QuienEsQuien();
	/**
	  * @brief Constructor de copia.
	  * @param quienEsQuien QuienEsQuien a copiar.
	  */
	QuienEsQuien(const QuienEsQuien &quienEsQuien);
	/**
	* @brief Destructor del pregunta.
	*/
	~QuienEsQuien();
	/**
	* @brief Sobrecarga del operador de asignaci�n.
	* @param quienEsQuien objeto a copiar.
	* @return Referencia al objeto copiado.
	*/
	QuienEsQuien& operator = (const QuienEsQuien &quienEsQuien);
	
	/**
	* @brief Operador de extracci�n de flujo.
	* @param is Stream de entrada
	* @param quienEsQuien Quien es quien a leer.
	* @return Referencia al stream de entrada.
	* 
	* Lee de @e is un quien es quien y lo almacena en @e 
	* quienEsQuien. El formato aceptado para la lectura es un TSV 
	* (tab-separated values) en el que las columnas tienen cabecera y 
	* son las preguntas. La �ltima columna corresponde al nombre del 
	* personaje. Tras la cabecera se especifica en cada l�nea un 
	* personaje, teniendo el valor 1 o 0 si tiene/no tiene el 
	* atributo de la columna. En la �ltima columna se da el 
	* nombre del personaje.
	*/
	friend istream& operator >> (istream& is, QuienEsQuien &quienEsQuien);
	
	/**
	* @brief Operador de inserci�n de flujo.
	* @param os Stream de salida
	* @param quienEsQuien Quien es quien a escribir.
	* @return Referencia al stream de salida.
	* 
	* Escribe en @e is un quien es quien.
	* El formato usado para la escritura es un TSV 
	* (tab-separated values) en el que las columnas tienen cabecera y 
	* son las preguntas. La �ltima columna corresponde al nombre del 
	* personaje. Tras la cabecera se especifica en cada l�nea un 
	* personaje, teniendo el valor 1 o 0 si tiene/no tiene el 
	* atributo de la columna. En la �ltima columna se da el 
	* nombre del personaje.
	*/
	friend ostream& operator << (ostream& os, const QuienEsQuien &quienEsQuien);

	/**
	  * @brief Escribe en la salida estandard las estructuras atributos, personajes y tablero.
	  */
	void mostrar_estructuras_leidas();

	/**
	  * @brief Este m�todo construye el �rbol de preguntas para todos los personajes del tablero.
	  */
	bintree<Pregunta> crear_arbol();

	/**
	  * @brief Sustituye el �rbol actual por el �rbol pasado por par�metro.
	  * @param arbol_nuevo Arbol de preguntas que sustituye al actual.
	  */
	void usar_arbol(bintree<Pregunta> arbol_nuevo);

	/**
	  * @brief Escribe el arbol generado en la salida estandard.
	  */
	void escribir_arbol_completo() const;

	/**
	   @brief M�todo que modifica el �rbol de preguntas para que haya
			  preguntas redundantes.
	   @post El �rbol de preguntas se modifica.
	*/
	void eliminar_nodos_redundantes(bintree<Pregunta>::node post_it);

	/**
	 * @brief Retorna la raíz del arbol en uso
	 */
	bintree<Pregunta>::node raiz();

	/**
	 * @brief Inicializa el juego.
	 * @post  Si la partida anterior no hab�a terminado se 
	 *        pierde el progreso.
	 */
	void iniciar_juego();

	/**
	  * @brief Dado un estado del tablero devuelve los nombres de 
	  *        los personajes que a�n no han sido tumbados en el 
	  *        tablero.
	  *
	  * @param jugada_actual Nodo del estado del tablero.
	  * 
	  * @return Conjunto de personajes que no han sido tumbados en el tablero.
	  * 
	  * @pre El arbol del QuienEsQuien receptor debe haber sido construido previamente.
	  * @pre El nodo indicado debe ser un nodo del arbol del QuienEsQuien receptor.
	  */
	set<string> informacion_jugada();

	/**
	 * @brief añade un nuevo personaje al juego actual de QuienEsQuien
	 * @param nombre Nombre del nuevo personaje
	 * @param caracteristicas Características del nuevo personaje. Deben ser los mismos atributos que los demas personajes del tablero
	 */
	void aniade_personaje(string nombre, const vector<bool> &caracteristicas);

	/**
	 * @brief elimina un personaje del tablero
	 * @param nombre Nombre del personaje a eliminar
	 */
	void elimina_personaje(string nombre);

	/**
	 * @brief Devuelve la posicion de un personaje en el vector de 'personajes' (coincide con la fila que ocupa en 'tablero')
	 * @param nombre Nombre del personaje del que queremos saber la posicion
	 */
	int return_fila_personaje(string nombre);

	/**
	 * @brief Pide por pantalla el nombre de un personaje y pregunta por sus caracteristicas
	 * @param nombre Aqui se recoge el nombre del personaje
	 * @param caracteristicas Aqui se recogen las caracteristicas del personaje
	 * */
	void introducir_datos_personaje(string &nombre, vector<bool> &caracteristicas);

	/**
	 * @brief Retorna un vector con las preguntas formuladas hasta el nodo actual
	 */
	void preguntas_formuladas(vector<string> &preguntas, vector<string> &respuestas);

	/**
	  * @brief Este m�todo permite calcular la media de la profundidad de las hojas del �rbol. Este valor representa el n�mero (promedio) de preguntas necesarias para adivinar cada personaje. A menor profundidad promedio, mejor soluci�n. Esta m�trica es un indicador para evaluar la calidad de vuestra soluci�n.
	  *
	  * @return Profundidad media del arbol de preguntas.
	  *
	  * @pre El arbol de preguntas debe haber sido construido previamente.
	  */
	float profundidad_promedio_hojas(); 

	/**
	  * @brief Rellena los datos del QuienEsQuien con un tablero calculado aleatoriamente.
	  * 
	  * @param numero_de_personajes N�mero de personajes que tiene el tablero a crear.
	  */
	void tablero_aleatorio(int numero_de_personajes);

};

#endif

