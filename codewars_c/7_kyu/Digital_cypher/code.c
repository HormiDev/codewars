#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

unsigned char *encode(const char *s, unsigned k)
{
    unsigned char	*result;
	int				i;
	char			*key;
	int				j;

	if (s == NULL)
		return (NULL);
	result = calloc(strlen(s) + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	key = calloc(30, sizeof(char));
	sprintf(key, "%u", k);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		result[i] = (s[i] - 'a') + 1 + key[j] - '0';
		i++;
		j++;
		if (key[j] == '\0')
			j = 0;
	}
	return (result);
}

#include <stdio.h>
int main(int argc, char *argv[])
{
	int i;

	unsigned char	*result;
	if (argc != 3)
	{
		printf("Usage: %s <string> <key>\n", argv[0]);
		return (1);
	}
	result = encode(argv[1], atoi(argv[2]));
	i = 0;
	while (result[i] != '\0')
	{
		printf("[%d] ", result[i]);
		i++;
	}
	free(result);
	return (0);
}
