#include <iostream>
#include <cassert>
//#include "../include/Pila/Pila_max_VD.h"

using namespace std;


Pila_Max::Pila_Max()
{
	elem_util = 0;
}


Pila_Max::~Pila_Max()
{
	vect.~VectorDinamico();
	elem_util = 0;
}


int Pila_Max::util() const
{
	return elem_util;
}


int Pila_Max::max()
{
	//assert(vect.dimension() > 0 && elem_util > 0);
	if(elem_util <= 0)
		return -1;

	return vect[ elem_util-1 ].max_actual;
}


int Pila_Max::tope()
{
	//assert(vect.dimension() > 0 && elem_util > 0);
	if(elem_util <= 0)
		return -1;

	return vect[ elem_util-1 ].elemento;
}


void Pila_Max::quitar()
{
	assert(vect.dimension() > 0 && elem_util > 0);
	//vect[ vect.dimension()-1 ].elemento = 0;
	//vect[ vect.dimension()-1 ].max_actual = 0;
	elem_util--;
}


void Pila_Max::poner(int elem)
{
	if (elem_util == vect.dimension())
		vect.redimensionar(2*elem_util);

	int actual_max = max();

	int max = ( elem > actual_max ? elem : actual_max );

	vect[elem_util].max_actual = max;
	vect[elem_util].elemento = elem;

	elem_util++;
}


bool Pila_Max::vacia() const
{
	if (elem_util > 0)
		return false;
	else
		return true;
}

interior_pila Pila_Max::topeCompleto()
{
	return vect[ elem_util-1 ];
}

ostream& operator<< (ostream& os, const interior_pila& p)
{
	os << //"(elemento, max_actual) => " << 
		"(" << p.elemento << ", " << p.max_actual << ")";

	return os;
}