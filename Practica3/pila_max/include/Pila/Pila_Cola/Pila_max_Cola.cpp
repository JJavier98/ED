#include <iostream>
#include <cassert>
//#include "../include/Pila/Pila_max_Cola.h"

using namespace std;


Pila_Max::Pila_Max(){}


Pila_Max::~Pila_Max()
{
	pila.~Cola();
}


int Pila_Max::util() const
{
	return pila.num_elementos();
}


int Pila_Max::max()
{
	//if(pila.vacia())
		//return -1;

	return pila.frente().max_actual;
}


int Pila_Max::tope()
{
	//if(pila.vacia())
		//return -1;

	return pila.frente().elemento;
}


void Pila_Max::quitar()
{
	assert(!pila.vacia());
	pila.quitar();
}


void Pila_Max::poner(int elem)
{
	if(pila.vacia())
	{
		interior_pila aux;
		aux.elemento = aux.max_actual = elem;

		pila.poner(aux);
	}
	else
	{
		int max = ( elem > pila.frente().max_actual ? elem : pila.frente().max_actual );

		interior_pila tope;
		tope.elemento = elem;
		tope.max_actual = max;

		pila.poner(tope);

		for(int i = 0 ; i < pila.num_elementos()-1 ; ++i)
		{
			interior_pila aux;

			aux = pila.frente();
			pila.quitar();
			pila.poner(aux);	
		}
	}
}


bool Pila_Max::vacia() const
{
	return pila.vacia();
}

interior_pila Pila_Max::topeCompleto()
{
	assert(!pila.vacia());
	
	return pila.frente();
}

ostream& operator<< (ostream& os, const interior_pila& p)
{
	os << //"(elemento, max_actual) => " << 
		"(" << p.elemento << ", " << p.max_actual << ")";

	return os;
}