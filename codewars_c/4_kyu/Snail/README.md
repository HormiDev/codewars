# Snail

## DESCRIPCIÓN
Dada una `n x n` matriz, devuelve los elementos de la matriz ordenados desde los elementos más externos hasta el elemento del medio, viajando en el sentido de las agujas del reloj.
```c
array = [[1,2,3],
         [4,5,6],
         [7,8,9]]
snail(array) #=> [1,2,3,6,9,8,7,4,5]
```
Para una mejor comprensión, siga los números de la siguiente matriz consecutivamente:
```c
array = [[1,2,3],
         [8,9,4],
         [7,6,5]]
snail(array) #=> [1,2,3,4,5,6,7,8,9]
```
NOTA: La idea no es ordenar los elementos desde el valor más bajo al más alto; la idea es recorrer la matriz 2-d siguiendo un patrón de caracol en el sentido de las agujas del reloj.

NOTA 2: La 0x0 (matriz vacía) se representa como una matriz vacía dentro de una matriz [[]].

### TEMAS `Algorithms` `Matrix`

<a href="https://www.codewars.com/users/HormiDev"><img src="https://www.codewars.com/users/HormiDev/badges/micro" alt="HormiDev codewars stats"></a>
