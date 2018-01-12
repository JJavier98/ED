#!/bin/csh
@ inicio = 100
@ fin = 30000
@ incremento = 500
@ i = $inicio

g++ ordenacion.cpp -o ordenacion

echo > tiempos2.dat

while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./ordenacion $i 10000` >> tiempos2.dat
  @ i += $incremento
end
