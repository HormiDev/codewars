#include <stdbool.h>

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != 0)
	{
		len++;
	}
	return (len);
}

bool solution(const char *string, const char *ending)
{
  int string_len;
  int ending_len;
  
  if (string == 0 || ending == 0)
    return(0);
  string_len = ft_strlen(string);
  ending_len = ft_strlen(ending);
  if (ending_len > string_len)
    return (false);
  while (ending_len > 0 && string_len > 0)
  {
    if (string[--string_len] != ending[--ending_len])
      return false;
  }
  return true;
}