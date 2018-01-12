#include <iostream>
#include <cassert>
#include "../include/Pila/Pila_max.h"

using namespace std;

int main(){

	Pila_Max p;
	int i;
	for ( i=100; i>=0 ; i--)
	p.poner(i);

	while (!p.vacia() )
	{
		interior_pila x = p.topeCompleto();
		cout << x << endl;
		p.quitar();
	}

/*	
	for ( i=0; i<=10 ; i++)
	p.poner(i);

	while (!p.vacia() )
	{
		interior_pila x = p.topeCompleto();
		cout << x << endl;
		p.quitar();
	}
*/

	return 0;
}