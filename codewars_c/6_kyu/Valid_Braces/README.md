# Valid Braces

## DESCRIPCIÓN
Escriba una función que tome una cadena de llaves y determine si el orden de las llaves es válido. Debe devolver `true`si la cadena es válida y 'false' si no lo es.

Este kata es similar al kata de paréntesis válidos , pero introduce nuevos caracteres: corchetes `[]` y llaves `{}`.

Todas las cadenas de entrada no estarán vacías y solo consistirán en paréntesis, corchetes y llaves: `()[]{}`.

## ¿Qué se considera válido?
Una cadena de llaves se considera válida si todas las llaves coinciden con la llave correcta.
```
"(){}[]"   =>  True
"([{}])"   =>  True
"(}"       =>  False
"[(])"     =>  False
"[({})](]" =>  False
```
### TEMAS `Algorithms`

<a href="https://www.codewars.com/users/HormiDev"><img src="https://www.codewars.com/users/HormiDev/badges/micro" alt="HormiDev codewars stats"></a>
