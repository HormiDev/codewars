#include <stdio.h>
#include <stdbool.h>

int ft_strlen(const char *str)
{
	int len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return len;
}

bool solution(const char *string, const char *ending)
{
	int string_len;
	int ending_len;

	if (string == NULL || ending == NULL)
		return false;
	string_len = ft_strlen(string);
	ending_len = ft_strlen(ending);
	if (ending_len > string_len)
		return false;
	while (ending_len > 0 && string_len > 0)
	{
		if (string[--string_len] != ending[--ending_len])
			return false;
	}
	return true;
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("se requieren 2 argumentos\n");
		return 1;
	}
	if (solution(argv[1], argv[2]))
		printf("true\n");
	else
		printf("false\n");
	return 0;
}
