#!/bin/csh
@ inicio = 100
@ fin = 10500
@ incremento = 50
@ i = $inicio

g++ ejercicio_desc.cpp -o ejercicio_desc

echo > tiempos.dat

while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./ejercicio_desc $i` >> tiempos.dat
  @ i += $incremento
end
