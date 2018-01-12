#include<iostream>
#include <list>
#include <fstream>
#include "../includes/TDA_fechahistorica.h"
#include "../includes/TDA_cronologia.h"

using namespace std;

int main(int argc, char const *argv[])
{
	/* SE HAN IMPLEMENTADO LOS OPERADORES << Y
	 >> COMO SE VERÁ A LO LARGO DEL EJEMPLO DE UTILIZACIÓN*/

	////////////////CONSTRUCTORES////////////
	Cronologia c;
	ifstream fich(argv[1]);
	fich >> c;

	FechaHistorica f(2017, "Se ha creado el TDA Cronología");
	Cronologia c_1(f);

	Cronologia c_2(argv[2]);
	
	Cronologia c_3(c);

	//////////////////MÉTODOS - CONSULTORES y MODIFICADORES//////////////////////////
	c.add(f);
	c.mostrarSucesosAnio(cout, 2017);cout << endl << endl;

	Cronologia c_4 = unir(c, c_2);
	cout << c_4 << endl << endl;

	Cronologia c_5 = c.buscaPalabra("developed");
	cout << c_5 << endl << endl;

	c_4.buscaPalabraMuestra(cout, "algorithm"); cout << endl << endl;

	c_4.buscaPalabraBorra("algorithm");
	cout << c_4 << endl << endl;

	FechaHistorica f_1 = c.buscaAnio(2017);
	cout << f_1 << endl << endl;

	c.buscaAnioBorra(2017);
	cout << c << endl << endl;

	c_4.buscaAnioMuestra(cout, 2017);

	//////////////////MÉTODOS - COMPARADORES//////////////////////////
	Cronologia c_6(c_2);
	if (c_6 == c_2)
		cout << "1" << endl << endl;

	return 0;
}