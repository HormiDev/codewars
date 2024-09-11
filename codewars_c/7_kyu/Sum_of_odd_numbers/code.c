#include <inttypes.h>

uint64_t rowSumOddNumbers(uint32_t n)
{
  long odd = 1;
  int line = 1;
  long num = 0;
  
  while (line < n)
    odd = odd + (2 * line++);
  while (line > 0)
  {
    num = num + odd;
    odd = odd + 2;
    line--;
  }
    return num;
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Se requiere 1 argumento.\n");
		return 1;
	}

	uint32_t n = atoi(argv[1]);
	uint64_t result = rowSumOddNumbers(n);
	printf("La suma de los números impares en la fila %d es: %lu\n", n, result);

	return 0;
}