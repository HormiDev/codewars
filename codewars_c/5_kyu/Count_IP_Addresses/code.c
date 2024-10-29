#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

void	ft_change_char(char *str, char c, char new_c)
{
	while (*str)
	{
		if (*str == c)
			*str = new_c;
		str++;
	}
}

void	ft_split_ip(char *ip, char **split)
{
	int	i;

	i = 0;
	split[i] = ip;
	while (*ip)
	{
		if (*ip == '.')
		{
			*ip = '\0';
			split[++i] = ip + 1;
		}
		ip++;
	}
}

uint32_t	ips_between (const char *start, const char *end)
{
	char		*ip1;
	char		*ip2;
	char		*ip1_split[4];
	char		*ip2_split[4];
	uint32_t	res;

	ip1 = strdup(start);
	ip2 = strdup(end);
	ft_split_ip(ip1, ip1_split);
	ft_split_ip(ip2, ip2_split);
	ft_change_char(ip1, '.', '\0');
	ft_change_char(ip2, '.', '\0');
	    res = ((uint32_t)atoi(ip2_split[0]) - (uint32_t)atoi(ip1_split[0])) * 256 * 256 * 256
        + ((uint32_t)atoi(ip2_split[1]) - (uint32_t)atoi(ip1_split[1])) * 256 * 256
        + ((uint32_t)atoi(ip2_split[2]) - (uint32_t)atoi(ip1_split[2])) * 256
        + ((uint32_t)atoi(ip2_split[3]) - (uint32_t)atoi(ip1_split[3]));
	free(ip1);
	free(ip2);
	return (res);
}

#include <stdio.h>
int main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("Usage: %s <start> <end>\n", argv[0]);
		return 1;
	}
	printf("%" PRIu32 "\n", ips_between(argv[1], argv[2]));
	return 0;
}