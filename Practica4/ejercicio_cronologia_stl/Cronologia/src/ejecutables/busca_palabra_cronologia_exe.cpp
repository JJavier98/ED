#include "../../includes/TDA_cronologia.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[])
{
	if (argc!=2 && argc!=3 && argc!=4)
	{
		cout << "Error: debe dar al menos el nombre del fichero con una cronología. " << endl;
		cout << "[Opcional]: una palabra a buscar en la cronología y un segundo nombre de fichero para guardar la cronología resultante." << endl;
		return 0;
	}

	string PALABRA;
	ofstream f2;
	bool fichero = false;

	ifstream f1 (argv[1]);	//FICHERO DE ENTRADA
	if (!f1)
	{
		cout << "No puedo abrir el fichero " << argv[1] << endl;
		return 0;
	}

	if(argc == 2)
	{
		cout << "Palabra a buscar --> ";
		cin >> PALABRA;	//TERMINO DE BUSQUEDA
	}
	else if (argc == 3)
	{
		PALABRA = argv[2];	//TERMINO DE BUSQUEDA
	}
	else if(argc == 4)
	{
		PALABRA = argv[2];	//TERMINO DE BUSQUEDA

		f2.open(argv[3]);	//POSIBLE FICHERO DE SALIDA
		if(!f2)
		{
			cout << "No puedo abrir el fichero " << argv[1] << endl;
			return 0;
		}
		else
			fichero = true;
	}

	Cronologia c1, cBusqueda;
	f1 >> c1;    // Cargamos los datos del fichero en la cronología.

	cBusqueda = c1.buscaPalabra(PALABRA);

	if (!fichero)   //No se dio fichero de salida, imprimimos en cout
	{
		cout << cBusqueda << endl;
	}
	else
	{          
		f2 << cBusqueda << endl;
	}
}