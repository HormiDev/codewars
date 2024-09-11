#include <stdbool.h>
#include <math.h>

bool is_prime(int num)
{
  int mult;
  int maxcmp;
  
  mult = 2;
  maxcmp = sqrt(num);
  if (num < 2)
    return (false);
  if (num == 2)
    return (true);
  if(num % mult == 0)
      return (false);
    mult++;
  while (mult <= maxcmp)
  {
    if(num % mult == 0)
      return (false);
    mult = mult + 2;
  }
  return (true);
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

	int num = atoi(argv[1]);
	if (is_prime(num))
		printf("El número %d es primo.\n", num);
	else
		printf("El número %d no es primo.\n", num);	
	return 0;
}