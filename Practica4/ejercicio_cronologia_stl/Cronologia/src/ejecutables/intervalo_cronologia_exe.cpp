#include "../../includes/TDA_cronologia.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[])
{
	if (argc!=5 && argc!=4)
	{
		cout<<"Error: debe dar al menos el nombre del fichero con cronología y los límites min y max en los que buscar. "<<endl;
		cout<<"[Opcional]: un segundo nombre de fichero para guardar la cronología resultante."<<endl;
		return 0;
	}

	ifstream f1 (argv[1]);
	if (!f1)
	{
		cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
		return 0;
	}

	const int 	MIN = atoi(argv[2]),
				MAX = atoi(argv[3]);

	Cronologia c1, cIntervalo;
	f1 >> c1;    // Cargamos los datos de los ficheros en las cronologías.

	cIntervalo = c1.filtroIntervalos(MIN, MAX);

	if (argc==4)   //No se dio fichero de salida, imprimimos en cout
	{
		cout << cIntervalo << endl;
	}
	else
	{
		ofstream f2 (argv[4]);
		if (!f2)
		{
			cout<<"No puedo abrir el fichero "<<argv[2]<<endl;
			return 0;
		}

		f2 << cIntervalo << endl;

	}
}