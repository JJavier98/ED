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
	anio = an;
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
  anio = f.anio;
  acontecimientos = f.acontecimientos;
}

// Devuelve acontecimientos
vector<string> FechaHistorica::get_acontecimientos()
{
	return acontecimientos;
}

//Asignación
int FechaHistorica::getAnio(){
  return anio;
}

//Comparación
void FechaHistorica::mostrarSucesos(ostream & os){
  	os << anio << endl;
	for (auto it = acontecimientos.cbegin() ; it < acontecimientos.cend() ; ++it)
	{
		os << *it << endl;
	}
}

void FechaHistorica::elimina_repetido()
{
	for (unsigned int i = 0 ; i < acontecimientos.size() ; ++i)
	{
		for (unsigned int j = i+1 ; j < acontecimientos.size() ; ++j)
		{
			if(acontecimientos[i] == acontecimientos[j])
			{
				acontecimientos.erase(acontecimientos.begin()+j);
			}
		}
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
	
	
	acontecimientos.push_back(suceso);

	elimina_repetido();
	
}

// Elñimina el último suceso de la FechaHistorica
void FechaHistorica::pop_back()
{
	acontecimientos.pop_back();
}

// Elimina el suceso 'n' de la FechaHistorica
void FechaHistorica::pop_n(int n)
{
	acontecimientos.erase(acontecimientos.begin()+n-1);
}

//Operador <
bool FechaHistorica::operator<(const FechaHistorica & f){
  	return anio < f.anio;
}

//Operador <=
bool FechaHistorica::operator<=(const FechaHistorica & f){
  	return anio <= f.anio;
}

//Operador >
bool FechaHistorica::operator>(const FechaHistorica & f){
	return anio > f.anio;
}

//Operador >=
bool FechaHistorica::operator>=(const FechaHistorica & f){
	return anio >= f.anio;
}

//Operador ==
bool FechaHistorica::operator==(const FechaHistorica & f){
  return anio == f.anio; 
}

FechaHistorica & FechaHistorica::operator=(const FechaHistorica & f)
{
	acontecimientos.clear();
	anio = f.anio;
	acontecimientos = f.acontecimientos;

	return *this;
}

//Operador <<
ostream& operator<< (ostream & os, const FechaHistorica & f){

	string aux = "";
  for(auto it = f.acontecimientos.cbegin() ; it < f.acontecimientos.cend() ; ++it)
  {
  	aux += *it;
  }
  os << f.anio << aux;
  return os;	
}

//Operador >>
istream& operator>> (istream& is, FechaHistorica& f){
	is >> f.anio;

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
