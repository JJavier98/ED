#include <iostream>
#include <fstream>
#include "../includes/TDA_fechahistorica.h"

using namespace std;

int main(int argc, char const *argv[])
{
	/* SE HAN IMPLEMENTADO LOS OPERADORES << Y
	 >> COMO SE VERÁ A LO LARGO DEL EJEMPLO DE UTILIZACIÓN*/

	////////////////CONSTRUCTORES////////////
	FechaHistorica f;
	ifstream fich(argv[1]);
	fich >> f;

	FechaHistorica f_1(2017, "Se ha creado TDA-FechaHistorica");

	FechaHistorica f_2(f);

	//////////////////MÉTODOS - CONSULTORES//////////////////////////
	int a = f.getAnio();
	f.mostrarSucesos(cout);
	cout << a << endl << endl;

	//////////////////MÉTODOS - MODIFICADORES//////////////////////////
	cout << f_2 << endl;
	f_2.add("Hemos añadido otro acontecimiento");
	cout << f_2 << endl << endl;

	f_2.add("Este acontecimiento lo vamos a eliminar");
	cout << f_2 << endl;
	f_2.pop_back();
	cout << f_2 << endl << endl;

	f_1.add("Borramos este segundo acontecimiento");
	f_1.add("Vamos a borrar el acontecimiento anterior");
	cout << f_1 << endl;
	f_1.pop_n(2);
	cout << f_1 << endl << endl;

	//////////////////MÉTODOS - COMPARADORES//////////////////////////
	if(f < f_1)
		cout << "1" << endl << endl;
	if(f > f_1)
		cout << "2" << endl << endl;
	if(f <= f_1)
		cout << "3" << endl << endl;
	if(f >= f_1)
		cout << "4" << endl << endl;

	return 0;
}