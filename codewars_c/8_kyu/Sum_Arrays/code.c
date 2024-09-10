#include <stddef.h>

int sum_array(const int *values, size_t count)
{
  int num;
  
  num = 0;
  if (values == 0 || count < 1)
    return (0);
  while (count > 0)
    num = num + values[--count];
  return (num);
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	// Verificar que se hayan proporcionado suficientes argumentos
	if (argc < 2)
	{
		printf("Se requiere al menos un argumento.\n");
		return 1;
	}

	// Convertir los argumentos en enteros y almacenarlos en un arreglo
	int values[argc - 1];
	for (int i = 1; i < argc; i++)
	{
		values[i - 1] = atoi(argv[i]);
	}

	// Calcular la suma de los valores y mostrar el resultado
	int result = sum_array(values, argc - 1);
	printf("La suma de los valores es: %d\n", result);

	return 0;
}
