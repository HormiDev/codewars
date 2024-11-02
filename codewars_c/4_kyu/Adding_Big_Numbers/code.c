#include <stdlib.h>
#include <string.h>

char *add(const char *a, const char *b)
{
	char	*res;
	char	*tmp;
	int		alen;
	int		blen;
	int		rlen;
	int 	i;
	int 	sum;

	if (a == NULL || b == NULL)
		return NULL;
	alen = strlen(a);
	blen = strlen(b);
	if (alen > blen)
		rlen = alen + 1;
	else
		rlen = blen + 1;
	tmp = calloc(rlen + 1, sizeof(char));
	if (tmp == NULL)
		return NULL;
	i = 0;
	while (i < alen || i < blen)
	{
		sum = 0;
		if (i < alen)
			sum += a[alen - i - 1] - '0';
		if (i < blen)
			sum += b[blen - i - 1] - '0';
		if (tmp[i] > 0)
			sum += tmp[i] - '0';
		if (sum >= 10)
		{
			tmp[i + 1] = '1';
			sum -= 10;
		}
		tmp[i] = sum + '0';
		i++;
	}
	rlen = strlen(tmp);
	res = calloc(rlen + 1, sizeof(char));
	if (res == NULL)
	{
		free(tmp);
		return NULL;
	}
	i = 0;
	while (i < rlen)
	{
		res[i] = tmp[rlen - i - 1];
		i++;
	}
	free(tmp);
	return (res);
}

#include <stdio.h>
int main(int argc, char **argv)
{
	char	*res;

	if (argc != 3)
	{
		printf("Usage: %s <num1> <num2>\n", argv[0]);
		return 1;
	}
	res = add(argv[1], argv[2]);
	printf("%s\n", res);
	free(res);
	return 0;
}