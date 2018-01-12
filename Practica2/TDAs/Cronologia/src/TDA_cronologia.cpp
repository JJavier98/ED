#include<iostream>
#include <list>
#include <fstream>
#include "../../FechaHistorica/includes/TDA_fechahistorica.h"
#include "../includes/TDA_cronologia.h"

using namespace std;

//Constructor por defecto
Cronologia::Cronologia(){} 

//Constructor
Cronologia::Cronologia(const FechaHistorica & f){
	lista_cronologia.push_back(f);
}

Cronologia::Cronologia(string fichero)
{
	ifstream fich(fichero);
	fich >> *this;
}

//Constructor de copia
Cronologia::Cronologia (const Cronologia& c){
  lista_cronologia = c.lista_cronologia;
}

//Muestra sucesos de un año concreto
void Cronologia::mostrarSucesosAnio(ostream & os, int an){
	bool encontrado = false;
	FechaHistorica aux;
  	for(auto it = lista_cronologia.cbegin() ; it != lista_cronologia.cend() && !encontrado ; ++it)
  	{
  		aux = *it;
  		if(aux.getAnio() == an)
  		{
  			encontrado = true;
  			aux = *it;
  		}
  	}

  	if(encontrado)
  		aux.mostrarSucesos(os);
  	else
  		os << "No encontramos datos sobre ese año en la cronología" << endl;
}

//Añade FH a la cronologia
void Cronologia::add(FechaHistorica f){
	bool encontrado = false;
	FechaHistorica aux_1;
	string aux_2;

	for(auto it = lista_cronologia.cbegin() ; it != lista_cronologia.cend() && !encontrado ; ++it)
  	{
  		aux_1 = *it;
  		if(aux_1.getAnio() == f.getAnio())
  		{
  			encontrado = true;
  			vector<string> v = f.get_acontecimientos();
  			for(auto iter = v.cbegin() ; iter != v.cend() ; ++iter)
  			{
  				aux_2 = *iter;
  				aux_1.add(aux_2);
  			}

  			lista_cronologia.insert(it, aux_1);
  			lista_cronologia.erase(it);
  		}
  	}

  	if(!encontrado)
  	{
		lista_cronologia.push_back(f);

		lista_cronologia.sort();

		lista_cronologia.unique();
	}
}

Cronologia unir(const Cronologia& cron_1, const Cronologia& cron_2)
{
	Cronologia c(cron_1);

	for(auto it = cron_2.lista_cronologia.cbegin() ; it != cron_2.lista_cronologia.cend() ; ++it)
	{
		c.add(*it);
	}

	c.lista_cronologia.sort();
	c.lista_cronologia.unique();

	return c;
}

Cronologia Cronologia::buscaPalabra(string palabra)
{
	list<FechaHistorica> lista;
	FechaHistorica fecha;

	for (auto it = lista_cronologia.cbegin() ; it != lista_cronologia.cend() ; ++it)
	{
		bool encontrado = false;
		bool salir = false;
		string completo = "";

		fecha = *it;
		vector<string> v = fecha.get_acontecimientos();
		
		for(auto iter = v.cbegin() ; iter != v.cend() ; ++iter)
  		{
  			completo += *iter;
  		}

  		for(auto i = completo.cbegin() ; i != completo.cend() && !encontrado && !salir ; ++i)
  		{
  			if (*i == palabra.front())
  			{
  				bool continua = true;
  				bool entra_bucle = false;

  				++i;
  				if(i == completo.cend())
  				{
  					salir = true;
  				}

  				for(auto j = palabra.cbegin()+1 ; j != palabra.cend() && continua && !salir ; ++j)
  				{
  					entra_bucle = true;

  					if( !(*i == *j) )
  						continua = false;

					++i;
					if(i == completo.cend())
						salir = true;
  				}

  				if(continua && entra_bucle)
  				{
  					salir = true;
  					lista.push_back(fecha);
  				}
  			}
  		}
	}
	Cronologia c;
	c.lista_cronologia = lista;

	return c;
}

//Busca una cadena de texto dentro de la cronologia y devuelve las FH relacionadas
void Cronologia::buscaPalabraMuestra(ostream & os, string palabra)
{
	Cronologia c = (*this).buscaPalabra(palabra);

	for(auto it = c.lista_cronologia.cbegin() ; it != c.lista_cronologia.cend() ; ++it)
	{
		os << *it << endl;
	}
}

void Cronologia::buscaPalabraBorra(string palabra)
{
	Cronologia c = (*this).buscaPalabra(palabra);
	FechaHistorica f, f1;

	for(auto it = c.lista_cronologia.cbegin() ; it != c.lista_cronologia.cend() ; ++it)
	{
		bool salir = false;
		f = *it;
		for(auto iter = lista_cronologia.cbegin() ; iter != lista_cronologia.cend() && !salir ; ++iter)
		{
			f1 = *iter;
			if(f == f1)
			{
				salir=true;
				lista_cronologia.remove(f1);
			}
		}
	}
}

FechaHistorica Cronologia::buscaAnio(int anio)
{
	FechaHistorica fecha;
	bool salir = false;

	for (auto it = lista_cronologia.cbegin() ; it != lista_cronologia.cend() && !salir ; ++it)
	{
		fecha = *it;
		if(fecha.getAnio() == anio)
			salir = true;
	}

	return fecha;
}

void Cronologia::buscaAnioBorra(int anio)
{
	FechaHistorica fecha;
	bool salir = false;

	for (auto it = lista_cronologia.cbegin() ; it != lista_cronologia.cend() && !salir ; ++it)
	{
		fecha = *it;
		if(fecha.getAnio() == anio)
		{
			salir = true;
			lista_cronologia.remove(fecha);
		}
	}
}

void Cronologia::buscaAnioMuestra(ostream & os, int anio)
{
	FechaHistorica f = (*this).buscaAnio(anio);

	os << f << endl;
}

//Operador ==
bool Cronologia::operator==(const Cronologia & c){

	if(lista_cronologia.size() == c.lista_cronologia.size())
	{
		bool iguales;

		auto it_1 = lista_cronologia.cbegin();
		auto it_2 = c.lista_cronologia.cbegin();
		FechaHistorica f1, f2;

		while(it_1 != lista_cronologia.cend() && iguales)
		{
			f1 = *it_1;
			f2 = *it_2;

			if(f1 == f2)
				iguales = true;
			else
				iguales = false;

			it_1++; it_2++;
		}
		return iguales;
	}
	else
		return false; 
}

//Operador <<
ostream& operator<< (ostream & os, const Cronologia & c){

  for(auto it = c.lista_cronologia.cbegin() ; it != c.lista_cronologia.cend() ; ++it)
  {
  	os << *it << endl;
  }
  
  return os;	
}

//Operador >>
istream& operator>> (istream& is, Cronologia& c){
	
	while (!is.eof())
	{
		FechaHistorica aux;
		is >> aux;
		c.add(aux);
	}
	
	return is;
}
