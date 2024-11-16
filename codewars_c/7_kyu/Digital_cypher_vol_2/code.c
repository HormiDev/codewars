#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

char *decode(const unsigned char *code, size_t n, unsigned key)
{
	char		*result;
	size_t		i;
	char		*key_str;
	int			j;

	if (code == NULL)
		return (NULL);
	result = calloc(n + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	key_str = calloc(30, sizeof(char));
	sprintf(key_str, "%u", key);
	i = 0;
	j = 0;
	while (i < n)
	{
		result[i] = (code[i] - key_str[j] + '0') + 'a' - 1;
		i++;
		j++;
		if (key_str[j] == '\0')
			j = 0;
	}
	return (result);
}

int main(int argc, char *argv[])
{
	int				i;
	char			*result;
	unsigned char	*code;
	if (argc < 3)
	{
		printf("Usage: %s <n1> <n2> <n3> ... <key>\n", argv[0]);
		return (1);
	}
	code = calloc(argc - 2, sizeof(unsigned char));
	i = 1;
	while (i < argc - 1)
	{
		code[i - 1] = atoi(argv[i]);
		i++;
	}
	result = decode(code, argc - 2, atoi(argv[argc - 1]));
	printf("%s\n", result);
	free(result);
	return (0);
}
