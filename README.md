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


**Logica**

Divide y vencerás. 

Dividir el Stack a tantas veces necesarias hasta que no quede ningún elemento en ella.

La forma que implenté fue escoger un pivote en el stack a por cada división, en un punto estratégico del array ordenado.

En el caso de 100 fue en las pociciones 20, 40, 60, 80 y 100. Los menores a cada iteración pasan al stack b y los mayores al fondo de la pila.

Cuando el stack b es mayor a 2 de longitud, escojo un pivote en el stack b, preferiblemente el del bloque_n[LEN/2] por ejemplo: si los numeros a pasar al stack b son el blocke_n = "3 4 5 1 2" mi pivote en el sentido ordenado sería el numero 3. 1 2 [[3]] 4 5. Esto con el fin de hacer un pre ordenamiento tipo sandwich. Todos los números menores al pivote pasan al fondo de la pila. El pivote se recalcula por cada bloque nuevo que llega al stack b.

Cuando el stack a esté vacío, implemento un algoritmo de búsqueda basado en la longitud del stack, teniendo en cuenta que en la parte menor a len/2 quedarán los números mayores y en el otra parate los numero menores al pivote final. haciendo que el número de rotaciones disminuyan. 

El algoritmo de búsqueda es muy sencillo. Básicamente es calcular el nùmero de rotaciones para posicionar el número mayor al top del satck b y hacer un push al stack a.

Mejoras que implemente en este algoritmo es: si en el transcurso de las rotaciones llega a estar el segundo mayor en el top, envío este número primero al stack a y cuando llegue el número mayor hago un swap a (sa) en el stack para dejarlo en el orden correspondiente.

Al finalizar hago un check. 
