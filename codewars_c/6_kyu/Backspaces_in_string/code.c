#include <stdlib.h>
#include <string.h>

char *strclr(const char *s)
{
	char *dup;
	char *result;
	int i = 0;

	if (s == NULL)
		return (NULL);
	dup = strdup(s);
	if (dup == NULL)
		return (NULL);
	while (dup[i] != '\0')
	{
		if (dup[i] == '#')
		{
			if (i > 0)
			{
				memmove(dup + i - 1, dup + i + 1, strlen(dup) - i);
				i--;
			}
			else
			{
				memmove(dup, dup + 1, strlen(dup));
				i = 0;
			}
		}
		else
			i++;
	}
	result = strdup(dup);
	free(dup);
	return (result);
}

#include <stdio.h>
int main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("%s\n", strclr(argv[1]));
	}
	return (0);
}