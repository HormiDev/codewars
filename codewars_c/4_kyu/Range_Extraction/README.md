# Range Extraction

## DESCRIPCIÓN
Un formato para expresar una lista ordenada de números enteros es utilizar una lista separada por comas de cualquiera de los siguientes:

- números enteros individuales
- o un rango de números enteros representado por el número entero inicial separado del número entero final del rango por un guión, '-'. El rango incluye todos los números enteros del intervalo, incluidos ambos puntos finales. No se considera un rango a menos que abarque al menos 3 números. Por ejemplo, "12,13,15-17".
Complete la solución para que tome una lista de números enteros en orden creciente y devuelva una cadena con el formato correcto en el formato de rango.

## Ejemplos
```c
range_extraction((const []){-10, -9, -8, -6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20}, 23);
/* returns "-10--8,-6,-3-1,3-5,7-11,14,15,17-20" */
```

### TEMAS `Algorithms`

<a href="https://www.codewars.com/users/HormiDev"><img src="https://www.codewars.com/users/HormiDev/badges/micro" alt="HormiDev codewars stats"></a>
