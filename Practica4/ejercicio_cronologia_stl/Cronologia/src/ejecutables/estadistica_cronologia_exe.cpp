#include "../../includes/TDA_cronologia.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[])
{
	if (argc!=2)
	{
		cout<<"Error: debe dar al menos el nombre del fichero con cronología sobre la que mostrar las estadísticas. "<<endl;
		return 0;
	}

	ifstream f1 (argv[1]);
	if (!f1)
	{
		cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
		return 0;
	}

	Cronologia c1;
	f1 >> c1;    // Cargamos los datos de los ficheros en las cronologías.

	c1.recuentoDeEventos(cout);
}