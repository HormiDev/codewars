//  do not allocate memory for the result
//  write to pre-allocated pointer *camel

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c = c - 32);
	return (c);
}

void to_camel_case(const char *text, char *camel)
{
	if (!text || !camel)
		return ;
	while (*text)
	{
		if (*text == '-' || *text == '_')
		{
			text++;
			*camel = ft_toupper(*text);
		}
		else
			*camel = *text;
		if (*text)
			text++;
		camel++;
	}
	*camel = '\0';
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *camel = (char *)malloc(100);
	to_camel_case("the-stealth_warrior", camel);
	printf("%s\n", camel);
	free(camel);
	return (0);
}