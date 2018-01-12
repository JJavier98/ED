# Quien es Quien #

***

Enlaces hacia los codigos c++

>[QuienEsQuien](https://github.com/JJavier98/ETSIIT/blob/master/2%C2%BA%20a%C3%B1o/1er%20Semestre/ED/Practica5/practica_final_material/src/quienesquien.cpp)
>[Bintree](https://github.com/JJavier98/ETSIIT/blob/master/2%C2%BA%20a%C3%B1o/1er%20Semestre/ED/Practica5/practica_final_material/include/bintree.hxx)
>[Node](https://github.com/JJavier98/ETSIIT/blob/master/2%C2%BA%20a%C3%B1o/1er%20Semestre/ED/Practica5/practica_final_material/include/node.hxx)
>[Pregunta](https://github.com/JJavier98/ETSIIT/blob/master/2%C2%BA%20a%C3%B1o/1er%20Semestre/ED/Practica5/practica_final_material/src/pregunta.cpp)

***

* Se han implementado todos los métodos obligatorios del guión de prácticas, así como 4 de los 5 métodos adicionales que se proponen (todos excepto `elegir_la_pregunta_mas_adecuada`). Se han implementado a su vez diversos métodos auxiliares que han ayudado al desarrollo y comprensión del programa; algunos de los cuales son:

```c++
bool es_izquierda(bintree<Pregunta>::node n);
int contar_true_en_columna(int col);
int contar_false_en_columna(int col);
bool nueva_partida();
bool menu();
bool tiene_el_atributo();
bintree<Pregunta>::node raiz();
int return_fila_personaje(string nombre);
void introducir_datos_personaje(string &nombre, vector<bool> &caracteristicas);
```

* El juego consta de un MENU que otorga al jugador la oportunidad de elegir su próxima acción.

> 1. Siguiente pregunta
> 1. Jugadores en pie
> 1. Preguntas ya respondidas
> 1. Añadir un nuevo personaje
> 1. Eliminar un personaje existente

* Dado que los iteradores de `bintree` devuelven un objeto `Pregunta` en vez de `node` he utilizado en muchos casos un _nodo_guia_ el cual he usado como iterador.
* Tambien en la clase `bintree` he hecho publico un constructor del iterador por niveles: `level_iterator(node n)` Ya que su uso me resultaba muy beneficioso en el método `informacion_jugada` que corresponde a la selección __2__ del MENU.
