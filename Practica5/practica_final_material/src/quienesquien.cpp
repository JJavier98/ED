#include "../include/quienesquien.h"
#include <sstream>
#include <iostream>
#include <iterator>
#include <math.h>
#include <algorithm>

using namespace std;

QuienEsQuien::QuienEsQuien(){
	jugada_actual = arbol.root();
}
QuienEsQuien::QuienEsQuien(const QuienEsQuien &quienEsQuien){
	*this = quienEsQuien;
}
QuienEsQuien& QuienEsQuien::operator= (const QuienEsQuien &quienEsQuien){
	personajes = quienEsQuien.personajes;
	atributos = quienEsQuien.atributos;
	tablero = quienEsQuien.tablero;
	arbol = quienEsQuien.arbol;
	jugada_actual = quienEsQuien.jugada_actual;
	
	return *this;
}
QuienEsQuien::~QuienEsQuien(){
	this->limpiar();
}

void QuienEsQuien::limpiar(){
	personajes.clear();
	atributos.clear();
	tablero.clear();
	arbol.clear();
	jugada_actual = typename bintree<Pregunta>::node();
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
  if ( !v.empty() ) {
    out << '[';
    std::copy (v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
    out << "\b\b]";
  }
  return out;
}

void QuienEsQuien::mostrar_estructuras_leidas(){
	cout << "personajes: "<< (this->personajes) << endl;
	cout << "atributos:  "<< (this->atributos)  << endl;
	cout << "tablero:    "<< endl;


	// Escribe la cabecera del tablero
	for(vector<string>::iterator it_atributos = this->atributos.begin();
		it_atributos != this->atributos.end();
		it_atributos++){
		cout << *it_atributos << "\t";
	}
	cout <<endl;

	int indice_personaje = 0;
	for(vector<vector<bool> >::iterator it_tablero_atributos = tablero.begin();
		it_tablero_atributos!= tablero.end();
		it_tablero_atributos++){

		string personaje = this->personajes[indice_personaje];
		int indice_atributo = 0;
		for(vector<bool>::iterator it_atributos_personaje = (*it_tablero_atributos).begin();
			it_atributos_personaje != (*it_tablero_atributos).end();
			it_atributos_personaje++){

			cout << *it_atributos_personaje<<"\t";

			indice_atributo++;
		}

		cout << personaje << endl;

		indice_personaje++;
	}

}

/**
  * @brief Devuelve una copia de la cadena original sin las subcadenas no deseadas.
  * 
  * @param cadena_original Cadena de la que se eliminan las subcadenas no deseadas.
  * @param cadena_a_eliminar Subcadena que se busca y se elimina.
  *
  * @return Copia de la cadena original sin las subcadenas no deseadas.
  */
string limpiar_string(string cadena_original,string cadena_a_eliminar){
	string linea(cadena_original);

	while(linea.find_first_of(cadena_a_eliminar) != std::string::npos){
		linea.erase(linea.find_first_of(cadena_a_eliminar),cadena_a_eliminar.length());
	}

	return linea;
}

istream& operator >> (istream& is, QuienEsQuien &quienEsQuien) {
	quienEsQuien.limpiar();
	
  	if(is.good()){
  		string linea;
    	getline(is, linea, '\n');

    	linea = limpiar_string(linea,"\r");
    	
    	while(linea.find('\t') != string::npos ){
    		string atributo = linea.substr(0,linea.find('\t'));
			quienEsQuien.atributos.push_back(atributo);
    		linea = linea.erase(0,linea.find('\t')+1);
    	}

		assert(linea ==  "Nombre personaje");
	}
	
    while( is.good() ) {
    	string linea;
    	getline(is, linea, '\n');
    	linea = limpiar_string(linea,"\r");

    	//Si la linea contiene algo extrae el personaje. Si no lo es, la ignora.
    	if(linea != ""){;
	    	vector<bool> atributos_personaje;
	    	
	    	int indice_atributo=0;
	    	while(linea.find('\t') != string::npos){
	    		string valor = linea.substr(0,linea.find('\t'));
	    		
	    		assert(valor == "0" || valor == "1");
	    		
	    		bool valor_atributo = valor == "1";
	    		
	    		atributos_personaje.push_back(valor_atributo);
				
	    		linea = linea.erase(0,linea.find('\t')+1);
	    		indice_atributo++;
			}
			
			string nombre_personaje = linea;
	    	
	    	quienEsQuien.personajes.push_back(nombre_personaje);
	    	quienEsQuien.tablero.push_back(atributos_personaje);
	    }
  	}
  	
	return is;
}

ostream& operator << (ostream& os, const QuienEsQuien &quienEsQuien){

	//Escribimos la cabecera, que contiene los atributos y al final una columna para el nombre
	for(vector<string>::const_iterator it_atributos = quienEsQuien.atributos.begin();
		it_atributos != quienEsQuien.atributos.end();
		it_atributos++){

		os  << *it_atributos << "\t";
	}
	os << "Nombre personaje" << endl;

	//Rellenamos con ceros y unos cada l�nea y al final ponemos el nombre del personaje.
	for(int indice_personaje=0;indice_personaje<quienEsQuien.personajes.size();indice_personaje++){
		for(int indice_atributo=0;indice_atributo<quienEsQuien.atributos.size();indice_atributo++){

			os  << quienEsQuien.tablero[indice_personaje][indice_atributo] << "\t";
		}
		os  << quienEsQuien.personajes[indice_personaje] << endl;
	}

	return os;
}

/**
  * @brief Convierte un n�mero a un vector de bool que corresponde 
  *        con su representaci�n en binario con un numero de digitos
  *        fijo.
  *
  * @param n N�mero a convertir en binario.
  * @param digitos N�mero de d�gitos de la representaci�n binaria.
  *
  * @return Vector de booleanos con la representaci�n en binario de @e n 
  *      con el n�mero de elementos especificado por @e digitos. 

  */
vector<bool> convertir_a_vector_bool(int n, int digitos) {
  vector<bool> ret;
  while(n) {
    if (n&1){
      ret.push_back(true);
    } else{
      ret.push_back(false);
    }
    n>>=1;  
  }

  while(ret.size()<digitos){
  	ret.push_back(false);
  }

  reverse(ret.begin(),ret.end());
  return ret;
}

int QuienEsQuien::contar_true_en_columna(int col)
{
	int total_true = 0;

	for (int i = 0; i < personajes.size(); ++i)
	{
		if (tablero[i][col] == true)
			total_true++;
	}
	return total_true;
}

int QuienEsQuien::contar_false_en_columna(int col)
{
	int total_false = 0;

	for (int i = 0; i < personajes.size(); ++i)
	{
		if (tablero[i][col] == false)
			total_false++;
	}
	return total_false;
}

bintree<Pregunta> QuienEsQuien::crear_arbol()
{	
	//TODO :D:D
	
	Pregunta primera(atributos[0], personajes.size());
	bintree<Pregunta> arbol_(primera);

	bintree<Pregunta>::node nodo_guia;

	for(int i = 0 ; i < personajes.size() ; ++i)
	{
		nodo_guia = arbol_.root();

		for(int j = 0 ; j < atributos.size() ; ++j)
		{
			if(contar_false_en_columna(j) != 0 && contar_false_en_columna(j) != personajes.size())
			{
				if(tablero[i][j])
				{
					if( nodo_guia.left().null() )
					{
						if(j == atributos.size()-1)
						{
							Pregunta nuevo_nodo(personajes[i], 0);
							arbol_.insert_left(nodo_guia, nuevo_nodo);
						}
						else
						{
							Pregunta nuevo_nodo(atributos[j+1], 0);
							arbol_.insert_left(nodo_guia, nuevo_nodo);
						}
					}
					(*nodo_guia.left()).set_num_personajes((*nodo_guia.left()).obtener_num_personajes()+1);
					nodo_guia = nodo_guia.left();
				}
				else
				{
					if (nodo_guia.right().null())
					{
						if (j == atributos.size() - 1)
						{
							Pregunta nuevo_nodo(personajes[i], 0);
							arbol_.insert_right(nodo_guia, nuevo_nodo);
						}
						else
						{
							Pregunta nuevo_nodo(atributos[j+1], 0);
							arbol_.insert_right(nodo_guia, nuevo_nodo);
						}
					}
					(*nodo_guia.right()).set_num_personajes((*nodo_guia.right()).obtener_num_personajes() + 1);
					nodo_guia = nodo_guia.right();
				}
			}
		}
	}

	return arbol_;
}

void QuienEsQuien::usar_arbol(bintree<Pregunta> arbol_nuevo){
	arbol = arbol_nuevo;
}

bool QuienEsQuien::nueva_partida()
{
	int seleccion = -5;

	do
	{
		cout << endl
			 << endl
			 << "						"
			 << "****¿Quieres empezar una nueva partida? Sí<1> / No<2>****" << endl;
		cin >> seleccion;
	} while (seleccion != 1 && seleccion != 2);

	if (seleccion == 2)
		return false;
	else
		return true;
}

int QuienEsQuien::return_fila_personaje(string nombre)
{
	int Iarriba = personajes.size()-1;
	int Iabajo = 0;

	while (Iabajo <= Iarriba)
	{
		if (personajes[Iarriba] == nombre)
			return Iarriba;
		else if (personajes[Iabajo] == nombre)
			return Iabajo;
		else
		{
			Iabajo++;
			Iarriba--;
		}
	}
	return -1;
}

void QuienEsQuien::elimina_personaje(string nombre)
{
	if(personajes.size() > 1)
	{
		bintree<Pregunta>::node nodo_guia = arbol.root();
		bintree<Pregunta> 		arbol_apoyo_1,
								arbol_apoyo_2;
		bool 					continuar = true;
		int 					fila = return_fila_personaje(nombre);

		for(int j = 0 ; j < atributos.size() && continuar ; ++j)
		{
			if ((*nodo_guia.left()).es_personaje() && (*nodo_guia.left()).obtener_personaje() == nombre)
				{
					(*nodo_guia.left().parent()).set_num_personajes( (*nodo_guia.left().parent()).obtener_num_personajes()-1);
					arbol.prune_left(nodo_guia, arbol_apoyo_1);
					continuar = false;
					personajes.erase(personajes.begin() + fila);
					tablero.erase(tablero.begin()+fila);
				}
			else if ((*nodo_guia.right()).es_personaje() && (*nodo_guia.right()).obtener_personaje() == nombre)
				{
					(*nodo_guia.right().parent()).set_num_personajes((*nodo_guia.right().parent()).obtener_num_personajes() - 1);
					arbol.prune_right(nodo_guia, arbol_apoyo_1);
					continuar = false;
					personajes.erase(personajes.begin() + fila);
					tablero.erase(tablero.begin() + fila);
				}
			else
			{
				if(tablero[fila][j] && atributos[j] == (*nodo_guia).obtener_pregunta())
					nodo_guia = nodo_guia.left();
				else if (atributos[j] == (*nodo_guia).obtener_pregunta())
					nodo_guia = nodo_guia.right();
			}
		}

		//Personaje_

		if(!continuar)
			while (!nodo_guia.parent().null())
			{
				(*nodo_guia.parent()).set_num_personajes((*nodo_guia.parent()).obtener_num_personajes() - 1);
				nodo_guia = nodo_guia.parent();
			}


		bool raiz_borrada = false;
		if(arbol.root().left().null())
		{
			arbol_apoyo_1.assign_subtree(arbol, arbol.root());
			arbol_apoyo_1.prune_right(arbol_apoyo_1.root(), arbol_apoyo_2);
			arbol.assign_subtree(arbol_apoyo_2, arbol_apoyo_2.root());
			raiz_borrada = true;
		}
		else if (arbol.root().right().null())
		{
			arbol_apoyo_1 = arbol;
			arbol_apoyo_1.prune_left(arbol_apoyo_1.root(), arbol_apoyo_2);
			arbol = arbol_apoyo_2;
			raiz_borrada = true;
		}

		if(raiz_borrada)
		{
			atributos.erase(atributos.begin());
			for(int i = 0 ; i < personajes.size() ; ++i)
			{
				tablero[i].erase(tablero[i].begin());
			}
		}


		if(!continuar)
			eliminar_nodos_redundantes(arbol.root());

		cout << "Al eliminar un personaje comenzamos de el juego desde el principio" << endl << endl;
		jugada_actual = arbol.root();
	}
	else
		cout << "Solo queda un jugador. No se puede eliminar" << endl << endl;
}

void QuienEsQuien::aniade_personaje(string nombre, const vector<bool> &caracteristicas)
{
	bool insertado = false;

	bintree<Pregunta>::node nodo_guia = arbol.root();
	if(!nodo_guia.left().null())
		(*nodo_guia.left().parent()).set_num_personajes((*nodo_guia.left().parent()).obtener_num_personajes()+1);
	else if (!nodo_guia.left().null())
		(*nodo_guia.right().parent()).set_num_personajes((*nodo_guia.right().parent()).obtener_num_personajes() + 1);

		for (int j = 0; j < caracteristicas.size() && !insertado; ++j)
		{
			if ((contar_false_en_columna(j) + (caracteristicas[j] ? 1 : 0)) != 0 && (contar_false_en_columna(j) + (caracteristicas[j] ? 1 : 0)) != personajes.size() - 1)
			{
				if (caracteristicas[j])
				{
					if (nodo_guia.left().null())
					{
						if (j == atributos.size() - 1)
						{
							Pregunta nuevo_nodo(nombre, 0);
							arbol.insert_left(nodo_guia, nuevo_nodo);
							personajes.push_back(nombre);
							tablero.push_back(caracteristicas);
							insertado = true;
						}
						else
						{
							Pregunta nuevo_nodo(atributos[j + 1], 0);
							arbol.insert_left(nodo_guia, nuevo_nodo);
						}
					}
					else if ((*nodo_guia.left()).es_personaje())
					{
						if (j != atributos.size() - 1)
						{
							Pregunta personaje_guardado = (*nodo_guia.left());
							int fila = return_fila_personaje(personaje_guardado.obtener_personaje());
							bool para = false;

							for (int k = j; k < caracteristicas.size() && !para; ++k)
							{
								if (caracteristicas[j + 1] != tablero[fila][j + 1])
									para = true;
							}

							if (para)
							{
								Pregunta nuevo_nodo(atributos[j + 1], 1);
								arbol.insert_left(nodo_guia, nuevo_nodo);
								if (tablero[fila][j + 1])
									arbol.insert_left(nodo_guia.left(), personaje_guardado);
								else
									arbol.insert_left(nodo_guia.right(), personaje_guardado);
							}
						}
					}
					(*nodo_guia.left()).set_num_personajes((*nodo_guia.left()).obtener_num_personajes() + 1);
					nodo_guia = nodo_guia.left();
				}
				else
				{
					if (nodo_guia.right().null())
					{
						if (j == atributos.size() - 1)
						{
							Pregunta nuevo_nodo(nombre, 0);
							arbol.insert_right(nodo_guia, nuevo_nodo);
							personajes.push_back(nombre);
							tablero.push_back(caracteristicas);
							insertado = true;
						}
						else
						{
							Pregunta nuevo_nodo(atributos[j + 1], 0);
							arbol.insert_right(nodo_guia, nuevo_nodo);
						}
					}
					else if ((*nodo_guia.right()).es_personaje())
					{
						if (j != atributos.size() - 1)
						{
							Pregunta personaje_guardado = (*nodo_guia.right());
							int fila = return_fila_personaje(personaje_guardado.obtener_personaje());
							bool para = false;

							for (int k = j; k < caracteristicas.size() && !para; ++k)
							{
								if (caracteristicas[j + 1] == tablero[fila][j + 1])
									para = true;
							}

							if (!para)
							{
								Pregunta nuevo_nodo(atributos[j + 1], 1);
								arbol.insert_right(nodo_guia, nuevo_nodo);
								if (tablero[fila][j + 1])
									arbol.insert_left(nodo_guia.left(), personaje_guardado);
								else
									arbol.insert_left(nodo_guia.right(), personaje_guardado);
							}
						}
					}
					(*nodo_guia.right()).set_num_personajes((*nodo_guia.right()).obtener_num_personajes() + 1);
					nodo_guia = nodo_guia.right();
				}
			}
	}
	escribir_arbol_completo();
	cout << endl << endl;
	eliminar_nodos_redundantes(arbol.root());

	cout << "Al añadir un personaje comenzamos de el juego desde el principio" << endl << endl;
	jugada_actual = arbol.root();
}

bool QuienEsQuien::menu()
{
	int seleccion = -5;
	vector<string> preguntas, respuestas;

	do
	{
		cout << endl
			 << endl
			 << "\t[1]Siguiente pregunta\n\t[2]Personajes sin tumbar(?)\n\t[3]Jugadas hechas\n\t[4]Añadir personaje\n\t[5]Eliminar personaje" << endl;

		cin >> seleccion;
	} while (seleccion != 1 && seleccion != 2 && seleccion != 3 && seleccion != 4 && seleccion != 5);

	if (seleccion == 2)
	{
		set<string> personajes_sin_tumbar(informacion_jugada());

		cout << endl
			 << endl
			 << "+++++++ Quedan en pie los siguientes personajes +++++++" << endl
			 << "\t";

		for (auto it = personajes_sin_tumbar.cbegin(); it != personajes_sin_tumbar.cend(); ++it)
		{
			cout << *it << ", ";
		}
		cout << endl;

		return false;
	}
	else if(seleccion == 3)
	{
		preguntas_formuladas(preguntas, respuestas);

		if(preguntas.size() == 0)
		{
			cout << endl
					<< endl
					<< "/////// Todavía no se ha hecho ninguna pregunta sobre el personaje ///////" << endl;
		}
		else
		{
			cout << endl
				<< endl
				<< "/////// El personaje oculto tiene las siguientes características: ///////" << endl;

			assert(preguntas.size() == respuestas.size());

			for(int i =0 ; i < preguntas.size() ; ++i)
			{
				cout << "\t" << preguntas[i] << "\t" << respuestas[i] << endl;
			}
		}

		return false;
	}
	else if(seleccion == 4)
	{
		string nombre;
		vector<bool> caracteristicas;

		introducir_datos_personaje(nombre, caracteristicas);

		aniade_personaje(nombre, caracteristicas);

		cout << "Hemos acabado el proceso de adición del personaje" << endl << endl;


		cout << "=========== Nuevo Arbol ====================" << endl;
		escribir_arbol_completo();
		cout << "Profundidad promedio de las hojas del arbol: ";
		cout << profundidad_promedio_hojas()<<endl; 
		cout << "============================================" << endl << endl << endl;
	}
	else if(seleccion == 5)
	{
		string nombre;

		do
		{
			cout << "Indica el nombre del jugador que quieres eliminar:	";
			cin >> nombre;
		} while (return_fila_personaje(nombre) < 0);

		elimina_personaje(nombre);
		cout << "Hemos acabado el proceso de eliminación" << endl << endl;

		cout << "=========== Nuevo Arbol ====================" << endl;
		escribir_arbol_completo();
		cout << "Profundidad promedio de las hojas del arbol: ";
		cout << profundidad_promedio_hojas() << endl;
		cout << "============================================" << endl
			 << endl
			 << endl;
	}
	else
		return true;
}

void QuienEsQuien::introducir_datos_personaje(string &nombre, vector<bool> &caracteristicas)
{
	int seleccion;
	bool valido = true;


	cout << "Introduce el nombre del jugador:	";
	cin >> nombre;

	do
	{
		valido = true;
		cout << "Responde a estas preguntas sobre sus características: " << endl << endl;
		
		for(int i = 0 ; i < atributos.size() ; ++i)
		{
			do{
				cout << endl
					<< endl
					<< "----- Tiene/Es... " << atributos[i] << "?   Sí<1> / No<2>" << endl;

				cin >> seleccion;
			} while (seleccion != 1 && seleccion != 2);
			caracteristicas.push_back(seleccion == 1? true : false);
		}

		for(int i = 0 ; i < personajes.size() && valido ; ++i)
		{

			if(tablero[i] == caracteristicas)
			{
				valido = false;
				caracteristicas.clear();
			}
		}
		
		if(!valido)
			cout << "\n->Ya existe un personaje con esas características. Introduce otras.<-" << endl << endl;

	}while(!valido);

	cout << "Hemos acabado con las preguntas. Pasamos a insertar tu personaje..." << endl;
}

bool QuienEsQuien::tiene_el_atributo()
{
	int seleccion = -5;

	if(!(*jugada_actual).es_personaje())
	{
		do
		{
			cout << endl
				<< endl
				<< "----- Tiene/Es... " << (*jugada_actual).obtener_pregunta() << "?   Sí<1> / No<2>" << endl;

			cin >> seleccion;
		} while (seleccion != 1 && seleccion != 2);

		if (seleccion == 2)
		{
			jugada_actual = jugada_actual.right();
			return false;
		}
		else
		{
			jugada_actual = jugada_actual.left();
			return true;
		}
	}
}

void QuienEsQuien::preguntas_formuladas(vector<string> &preguntas, vector<string> &respuestas)
{
	bintree<Pregunta>::node nodo = jugada_actual;

	while(!nodo.parent().null())
	{
		preguntas.insert( preguntas.begin(), (*nodo.parent() ).obtener_pregunta() );
		respuestas.insert( respuestas.begin(), nodo.parent().left() == nodo? "SI" : "NO");
		nodo = nodo.parent();
	}
}

void QuienEsQuien::iniciar_juego(){
	//TODO :)
	bool continuar  = true,
		 acabar 	= false;

	do
	{
		jugada_actual = arbol.root();

		continuar = nueva_partida();
		acabar = !continuar;

		if (continuar)
		{
			while((*jugada_actual).es_pregunta())
			{
				while(!menu()){}

				tiene_el_atributo();
			}

			cout << "									LO TENGO!!" << endl
				 << "								Tu personaje es..." << (*jugada_actual).obtener_personaje() << "!" << endl;
		}
	}
	while (!acabar);
}

set<string> QuienEsQuien::informacion_jugada(){
	
	//TODO :)
	set<string> personajes_levantados;

	bintree<Pregunta>::level_iterator level_it(jugada_actual);
	int contador = 0;
	while(contador != (*jugada_actual).obtener_num_personajes() && level_it != arbol.end_level())
	{
		if((*level_it).es_personaje())
		{
			contador++;
			personajes_levantados.insert((*level_it).obtener_personaje());
		}

		++level_it;
	}

	return personajes_levantados;
}

void escribir_esquema_arbol(ostream& ss,
					  const bintree<Pregunta>& a, 
		    		  bintree<Pregunta>::node n,
					  string& pre){
	if (n.null()){
	    ss << pre << "-- x" << endl;
	} else {
	    ss << pre << "-- " << (*n) << endl;
	    if ( !n.right().null() || !n.left().null()) {// Si no es una hoja
			pre += "   |";
	    	escribir_esquema_arbol(ss,a, n.right(), pre);
	     	pre.replace(pre.size()-4, 4, "    ");
	      	escribir_esquema_arbol (ss,a, n.left(), pre);
	      	pre.erase(pre.size()-4, 4);    
	    }
  	}
}

void QuienEsQuien::escribir_arbol_completo() const{
	string pre = "";
	escribir_esquema_arbol(cout,this->arbol,this->arbol.root(),pre);
}

bintree<Pregunta>::node QuienEsQuien::raiz()
{
	return arbol.root();
}

void QuienEsQuien::eliminar_nodos_redundantes(bintree<Pregunta>::node post_it)
{
	if (post_it.null())
		post_it = arbol.root();

	if (!post_it.left().null())
	{
		eliminar_nodos_redundantes(post_it.left());
	}
	if (!post_it.right().null())
	{
		eliminar_nodos_redundantes(post_it.right());
	}

	if (post_it.left().null() && !post_it.right().null())
	{
		bintree<Pregunta> arbol_podado;
		arbol.prune_right(post_it, arbol_podado);

		if (es_izquierda(post_it))
			arbol.insert_left(post_it.parent(), arbol_podado);
		else
			arbol.insert_right(post_it.parent(), arbol_podado);
	}
	else if (!post_it.left().null() && post_it.right().null())
	{
		bintree<Pregunta> arbol_podado;
		arbol.prune_left(post_it, arbol_podado);

		if (es_izquierda(post_it))
			arbol.insert_left(post_it.parent(), arbol_podado);
		else
			arbol.insert_right(post_it.parent(), arbol_podado);
	}
}

float QuienEsQuien::profundidad_promedio_hojas(){
	//TODO :)

	bintree<Pregunta>::node post_it = arbol.root();
	int profundidad_total = 0;

	do
	{
		while (!post_it.left().null())
			post_it = post_it.left();
		if (!post_it.right().null())
			post_it = post_it.right();

	} while (!post_it.left().null() || !post_it.right().null());

	while (!post_it.null())
	{
		if((*post_it).es_personaje() && post_it.left().null() && post_it.right().null())
		{
			bintree<Pregunta>::node nodo_contador = post_it;
			while(!nodo_contador.null())
			{
				nodo_contador = nodo_contador.parent();
				profundidad_total++;
			}
			profundidad_total--;
		}

		if (post_it.parent().null())
		{
			post_it = bintree<Pregunta>::node();
		}
		else if (post_it.parent().left() == post_it)
		{
			if (!post_it.parent().right().null())
			{
				post_it = post_it.parent().right();
				do
				{
					while (!post_it.left().null())
						post_it = post_it.left();
					if (!post_it.right().null())
						post_it = post_it.right();
				} while (!post_it.left().null() ||
						!post_it.right().null());
			}
			else
				post_it = post_it.parent();
		}
		else // post_it es hijo a la derecha de su padre
			post_it = post_it.parent();
	}

	//cout << endl << profundidad_total << endl << personajes.size() << endl;

	return profundidad_total/personajes.size();
}

/**
 * @brief Genera numero enteros positivos aleatorios en el rango [min,max).
**/

int generaEntero(int min, int max){
    int tam= max -min;
    return ((rand()%tam)+min);
}

void QuienEsQuien::tablero_aleatorio(int numero_de_personajes){
	srand(0);

	this->limpiar();

	float log_2_numero_de_personajes = log(numero_de_personajes)/log(2);

	int numero_de_atributos = ceil(log_2_numero_de_personajes);

	cout << "Petici�n para generar "<< numero_de_personajes<<" personajes ";
	cout << "con "<<numero_de_atributos<< " atributos"<<endl;
	cout << "Paso 1: generar "<< pow(2,numero_de_atributos) << " personajes"<<endl;

	//Fase 1: completar el tablero con todos los personajes posibles
	//Completo el tablero y los nombres de personajes a la vez
	for(int indice_personaje=0;indice_personaje< pow(2,numero_de_atributos);indice_personaje++)
	{
		vector<bool> atributos_personaje = convertir_a_vector_bool(indice_personaje,numero_de_atributos);
		string nombre_personaje = "Personaje_"+to_string(indice_personaje);

		this->personajes.push_back(nombre_personaje);
		this->tablero.push_back(atributos_personaje);
	}

	// Completo los nombres de los atributos.
	for(int indice_atributo=0;indice_atributo<numero_de_atributos;indice_atributo++){
		string nombre_atributo = "Atr_"+to_string(indice_atributo);
		this->atributos.push_back(nombre_atributo);
	}

	cout << "Paso 2: eliminar "<< (pow(2,numero_de_atributos)-numero_de_personajes) << " personajes"<<endl;
	//Fase 2. Borrar personajes aleatoriamente hasta que quedan solo los que hemos pedido.
	while(personajes.size()>numero_de_personajes){
		int personaje_a_eliminar = generaEntero(0,personajes.size());

		personajes.erase(personajes.begin()+personaje_a_eliminar);
		tablero.erase(tablero.begin()+personaje_a_eliminar);
	}
}
