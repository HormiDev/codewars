int paperwork(int n, int m)
{
  if(n <= 0 || m <= 0)
    return (0);
  return (n * m); 
}

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
  if(argc == 3)
	printf("%d\n", paperwork(atoi(argv[1]), atoi(argv[2])));
  return (0);
}
