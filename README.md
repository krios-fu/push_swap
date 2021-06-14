# push_swap
Este proyecto se trata de ordenar datos en una pila, con un conjunto limitado de instrucciones, utilizando el menor número posible de acciones.

**Nota final:  125%** 

**Hacer:** 

`make && make run && make bonus`

**Para ejecutar:** 

**1** `./push_swap 1 3 2 ` 

**2** `ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l`

**3** `ARG=$(seq 0 1000 | sort -R | tail -n 100 | tr '\n' ' ') ; ./push_swap $ARG | wc -l`  

**4** `ARG=$(seq -1000 1000 | sort -R | tail -n 500 | tr '\n' ' ') ; ./push_swap $ARG | ./checker $ARG` 


**Número de aproximaciones en movimientos:**

**2n** : 2 Movimientos

**3n** : Entre 2 y 3 movimientos

**5n** : Entre 7 y 12 movimietnos

**100n** : Entre 500 y 700 movimientos

**500n** : Entre 5100 y 5500 movimientos
