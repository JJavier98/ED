#include<iostream>
#include <vector>
#include <string>
#include <climits>
#include "../includes/TDA_fechahistorica.h"

using namespace std;

//Constructor por defecto
FechaHistorica::FechaHistorica(){} 

//Constructor
FechaHistorica::FechaHistorica(int an, string sucesos ){
	fecha.first = an;
	string aux = "";

	if(sucesos.front() != '#')
	{
		string aux_2 = "#";
		aux_2 += sucesos;
		sucesos = aux_2;
	}

	for (auto it = sucesos.cbegin()+1 ; it < sucesos.cend() ; ++it)
	{
		if(*it == '#')
		{
			add(aux);
			aux = "";
		}
		else
		{
			aux += *it;
		}
	}
	add(aux);
} 

//Constructor de copia
FechaHistorica::FechaHistorica (const FechaHistorica& f){
  fecha.first = f.fecha.first;
  fecha.second = f.fecha.second;
}

// Devuelve second
set<string> FechaHistorica::get_acontecimientos () const
{
	return fecha.second;
}

set<string> FechaHistorica::get_acontecimientos ()
{
	return fecha.second;
}

//Asignación
int FechaHistorica::getAnio()const
{
  return fecha.first;
}

//Comparación
void FechaHistorica::mostrarSucesos(ostream & os){
  	os << fecha.first << endl;

	for (FechaHistorica::const_iterator it = begin() ; it != end() ; ++it)
	{
		os << *it << endl;
	}
}

//Escribe
void FechaHistorica::add(string suceso){

	if(suceso.front() != '#')
	{
		string aux = "#";
		aux += suceso;
		suceso = aux;
	}
	
	
	fecha.second.insert(suceso);	
}

// Elñimina el último suceso de la FechaHistorica
void FechaHistorica::pop_back()
{
	fecha.second.erase(--fecha.second.end());
}

// Elimina el suceso 'n' de la FechaHistorica
void FechaHistorica::pop_n(int n)
{
	FechaHistorica::const_iterator it = begin();
	for (int i = 0; i < n; ++i)
	{
		it++;
	}
	fecha.second.erase(it);
}

//Operador <
bool FechaHistorica::operator<(const FechaHistorica & f){
  	return fecha.first < f.fecha.first;
}

//Operador <=
bool FechaHistorica::operator<=(const FechaHistorica & f){
  	return fecha.first <= f.fecha.first;
}

//Operador >
bool FechaHistorica::operator>(const FechaHistorica & f){
	return fecha.first > f.fecha.first;
}

//Operador >=
bool FechaHistorica::operator>=(const FechaHistorica & f){
	return fecha.first >= f.fecha.first;
}

//Operador ==
bool FechaHistorica::operator==(const FechaHistorica & f){
  return fecha.first == f.fecha.first; 
}

FechaHistorica & FechaHistorica::operator=(const FechaHistorica & f)
{
	fecha.second.clear();
	fecha.first = f.fecha.first;
	fecha.second = f.fecha.second;

	return *this;
}

//Operador <<
ostream& operator<< (ostream & os, const FechaHistorica & f){

	string aux = "";
	for(FechaHistorica::const_iterator it = f.begin() ; it != f.end() ; ++it)
	{
		aux += *it;
	}
	os << f.fecha.first << aux;
	return os;	
}

//Operador >>
istream& operator>> (istream& is, FechaHistorica& f){
	is >> f.fecha.first;

	string hechos = "";
	string aux = "";

	getline(is, hechos, '\n');

	if(hechos.front() != '#')
	{
		string aux_2 = "#";
		aux_2 += hechos;
		hechos = aux_2;
	}

	for(auto it = hechos.begin()+1 ; it < hechos.end() ; ++it)
	{
		if (*it == '#' || *it == hechos.back())
		{
			f.add(aux);
			aux = "";
		}
		else
			aux += *it;
	}
	
	return is;
}
