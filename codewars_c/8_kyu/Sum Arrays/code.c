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