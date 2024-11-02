# Digital cypher

## DESCRIPCIÓN
Digital Cypher asigna a cada letra del alfabeto un número único. Por ejemplo:
```
 a  b  c  d  e  f  g  h  i  j  k  l  m
 1  2  3  4  5  6  7  8  9 10 11 12 13
 n  o  p  q  r  s  t  u  v  w  x  y  z
14 15 16 17 18 19 20 21 22 23 24 25 26
```
En lugar de letras en una palabra cifrada, escribimos el número correspondiente, por ejemplo, la palabra scout:
```
 s  c  o  u  t
19  3 15 21 20
```
Luego, a cada dígito obtenido, le sumamos los dígitos consecutivos de la clave. Por ejemplo, en caso de clave igual a 1939:
```
   s  c  o  u  t
  19  3 15 21 20
 + 1  9  3  9  1
 ---------------
  20 12 18 30 21
  
   m  a  s  t  e  r  p  i  e  c  e
  13  1 19 20  5 18 16  9  5  3  5
+  1  9  3  9  1  9  3  9  1  9  3
  --------------------------------
  14 10 22 29  6 27 19 18  6  12 8
```
## Entrada / Salida
La strcadena de entrada consta únicamente de caracteres en minúscula.
El keynúmero de entrada es un entero positivo.

## Ejemplo
```
Encode("scout",1939);  ==>  [ 20, 12, 18, 30, 21]
Encode("masterpiece",1939);  ==>  [ 14, 10, 22, 29, 6, 27, 19, 18, 6, 12, 8]
```
### TEMAS `FUNDAMENTALS` `CIPHERSCRYP` `TOGRAPHY`

<a href="https://www.codewars.com/users/HormiDev"><img src="https://www.codewars.com/users/HormiDev/badges/micro" alt="HormiDev codewars stats"></a>
