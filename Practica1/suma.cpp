#include <iostream>
#include <ctime>    // Recursos para medir tiempos
#include <cstdlib>  // Para generación de números pseudoaleatorios
#include <fstream>


using namespace std;

void sintaxis()
{
  cerr << "Sintaxis:" << endl;
  cerr << "  fs: Fichero del que se extraen los datos" << endl;
  cerr << "Se genera un vector con los datos del ficheto fs" << endl;
  exit(EXIT_FAILURE);
}

int main(int argc, char * argv[])
{
  // Lectura de parámetros
  if (argc!=2)
    sintaxis();

	ifstream fs(argv[1]); // Creacion de fichero

	double v[5000]; // creacion de vector con un máximo de 5000 elementos
  
  	int c = 0, i = 0; // c: variable tamaño del vector; i: índice del vector
	while(!fs.eof()){ // leemos los datos del fichero hasta el final del mismo
		fs >> v[i];
		c++; i++;
	}


	double suma = 0.0; // inicializamos suma

	for (int j=0; j<c; j++){  // Recorrer vector
		//cout << v[j] << endl;
    	suma += v[j];
    }

  // Mostramos resultados
  cout << endl << endl << suma/c << endl;
}
