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
	const int anio = f.getAnio();
	cronologia[anio] = f;
}

Cronologia::Cronologia(string fichero)
{
	ifstream fich(fichero);
	fich >> *this;
}

//Constructor de copia
Cronologia::Cronologia (const Cronologia& c){
  cronologia = c.cronologia;
}

//Muestra sucesos de un año concreto
void Cronologia::mostrarSucesosAnio(ostream & os, int an){
	
  	if(cronologia.count(an))
  	{
  		cronologia[an].mostrarSucesos(os);
  	}
  	else
  		os << "No encontramos datos sobre ese año en la cronología" << endl;
}

//Añade FH a la cronologia
void Cronologia::add(const FechaHistorica f){

	if(cronologia.count(f.getAnio()))
  	{
  		FechaHistorica aux( cronologia[ f.getAnio() ] );

  		const set<string> hechos = f.get_acontecimientos();

  		for(auto it = hechos.cbegin() ; it != hechos.cend() ; ++it)
  		{
  			aux.add(*it);
  		}

  		cronologia[f.getAnio()] = aux;
  	}
  	else
  	{
  		cronologia[f.getAnio()] = f;
  	}
}

Cronologia unir(const Cronologia& cron_1, const Cronologia& cron_2)
{
	Cronologia c(cron_1);

	for(Cronologia::const_iterator it = cron_2.begin() ; it != cron_2.end() ; ++it)
	{
		FechaHistorica f = it->second;
		c.add(f);
	}

	return c;
}

Cronologia Cronologia::buscaPalabra(string palabra)
{
	Cronologia c;
	FechaHistorica nuevaFecha;
	int i;

	for (Cronologia::const_iterator it = begin() ; it != end() ; ++it)
	{
		FechaHistorica fecha = it->second;
		i = 0;
		
		for(FechaHistorica::const_iterator iter = fecha.begin() ; iter != fecha.end() ; ++iter)
  		{
  			size_t found = iter->find(palabra);
  			if(found != string::npos)
  			{
  				if(i == 0)
  					nuevaFecha = FechaHistorica(it->first, *iter);
  				else
  					nuevaFecha.add(*iter);
  			}
  		}
  		c.add(nuevaFecha);
	}

	return c;
}

Cronologia Cronologia::filtroIntervalos(int anio_ini, int anio_fin)
{
	Cronologia c;
	Cronologia::const_iterator it = begin();
	Cronologia::const_iterator iter = end();

	if(it->first > anio_fin || (--iter)->first < anio_ini)
	{
		FechaHistorica fecha(0, "MESAJE DE ERROR: Has introducido unos años no válidos para esta cronología");
		c.add(fecha);
	}
	else
	{
		while ( it != iter )
		{
			if( (it->first <= anio_fin) && (it->first >= anio_ini) )
				c.add(it->second);
			it++;
		}
	}

	return c;
}

void Cronologia::recuentoDeEventos(ostream & os)
{
	int num_anios = cronologia.size(),
		num_acontecimientos = 0,
		max_acon = 0,
		max_anio,
		num_acon_promedio;

	for (Cronologia::const_iterator it = begin() ; it != end() ; ++it)
	{
		const FechaHistorica f = it->second;

		if(max_acon < f.get_acontecimientos().size())
		{
			max_anio = it->first;
			max_acon = f.get_acontecimientos().size();
		}
		num_acontecimientos += f.get_acontecimientos().size();
	}

	num_acon_promedio = num_acontecimientos/num_anios;

	os << "-- Hay un total de " << num_anios << " años con Fechas Históricas asignadas." << endl;
	os << "-- Esta cronología tiene un total de " << num_acontecimientos << " acontecimientos." << endl;
	os << "-- El año con mayor número de acontecimientos a destacar es " << max_anio << " con un total de " << max_acon << " acontecimientos." << endl;
}

//Operador <<
ostream& operator<< (ostream & os, const Cronologia & c){

  for(Cronologia::const_iterator it = c.begin() ; it != c.end() ; ++it)
  {
  	os << it->second << endl;
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
