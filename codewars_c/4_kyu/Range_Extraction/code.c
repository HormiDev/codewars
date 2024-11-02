#include <stdlib.h>
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	cont;

	dstlen = strlen(dst);
	srclen = strlen(src);
	cont = 0;
	if (dstsize == 0)
		return (srclen);
	while (dstlen + cont < dstsize - 1 && src[cont] != '\0')
	{
		dst[dstlen + cont] = src[cont];
		cont++;
	}
	dst[dstlen + cont] = '\0';
	if (dstsize < dstlen)
		return (dstsize + srclen);
	return (dstlen + srclen);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	cont;
	size_t	srclen;

	cont = 0;
	srclen = strlen(src);
	if (dstsize > 0)
	{
		while (cont < srclen && cont < dstsize - 1)
		{
			dst[cont] = src[cont];
			cont++;
		}
		dst[cont] = 0;
	}
	return (srclen);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	cont;

	cont = 0;
	str = malloc((strlen(s1) + 1) * sizeof(char));
	if (str == 0)
		return (0);
	while (cont < strlen(s1))
	{
		str[cont] = s1[cont];
		cont++;
	}
	str[cont] = 0;
	return (str);
}

static int	ft_intlen(int n)
{
	int	len;
	int	mult;

	if (n == -2147483648)
		return (11);
	len = 1;
	mult = 1;
	if (n < 0)
	{
		len++;
		n = n * -1;
	}
	while (n / mult > 9)
	{
		len++;
		mult = mult * 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_intlen(n);
	str = calloc((len + 1), sizeof(char));
	if (str == 0)
		return (NULL);
	str[len] = 0;
	if (n >= 0)
		n = n * -1;
	else
		str[0] = '-';
	while ((len > 0 && str[0] == 0) || (len > 1 && str[0] == '-'))
	{
		str[len - 1] = ((n % 10) * -1 + '0');
		n = n / 10;
		len--;
	}
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	str = malloc((strlen(s1) + strlen(s2) + 1) * sizeof(char));
	if (str == 0)
		return (0);
	ft_strlcpy(str, s1, strlen(s1) + 1);
	ft_strlcat(str, s2, strlen(s1) + strlen(s2) + 1);
	return (str);
}

void ft_add_num(char **str, int num)
{
	char *tmp;
	char *tmp2;

	tmp = *str;
	tmp2 = ft_itoa(num);
	*str = ft_strjoin(*str, tmp2);
	free(tmp);
	free(tmp2);
}

void ft_add_range(char **str, int min, int max)
{
	char *tmp;
	char *tmp2;

	tmp = *str;
	tmp2 = ft_itoa(min);
	*str = ft_strjoin(*str, tmp2);
	free(tmp);
	free(tmp2);
	tmp = *str;
	*str = ft_strjoin(*str, "-");
	free(tmp);
	tmp = *str;
	tmp2 = ft_itoa(max);
	*str = ft_strjoin(*str, tmp2);
	free(tmp);
	free(tmp2);
}

void ft_add_comma(char **str)
{
	char *tmp;

	tmp = *str;
	*str = ft_strjoin(*str, ",");
	free(tmp);
}

char *range_extraction(const int *args, size_t n)
{
	char	*res;
	size_t	i;
	int 	min_range;
	int		max_range;

	res = ft_strdup("");
	if (res == NULL)
		return NULL;
	i = 0;
	min_range = args[i];
	max_range = args[i];
	while (i < n - 1)
	{
		if (args[i + 1] == args[i] + 1)
		{
			max_range = args[i + 1];
		}
		else
		{
			if (min_range == max_range)
			{
				ft_add_num(&res, min_range);
				ft_add_comma(&res);
			}
			else if (max_range == min_range + 1)
			{
				ft_add_num(&res, min_range);
				ft_add_comma(&res);
				ft_add_num(&res, max_range);
				ft_add_comma(&res);
			}
			else
			{
				ft_add_range(&res, min_range, max_range);
				ft_add_comma(&res);
			}
			min_range = args[i + 1];
			max_range = args[i + 1];
		}
		i++;
	}
	if (min_range == max_range)
		ft_add_num(&res, min_range);
	else if (max_range == min_range + 1)
	{
		ft_add_num(&res, min_range);
		ft_add_comma(&res);
		ft_add_num(&res, max_range);
	}
	else
		ft_add_range(&res, min_range, max_range);
	return (res);
}

#include <stdio.h>
int main(int argc, char **argv)
{
	int		*args;
	size_t	n;
	size_t	i;
	char	*res;

	n = argc - 1;
	args = malloc(sizeof(int) * n);
	i = 0;
	while (i < n)
	{
		args[i] = atoi(argv[i + 1]);
		i++;
	}
	res = range_extraction(args, n);
	printf("%s\n", res);
	free(res);
	free(args);
	return 0;
}