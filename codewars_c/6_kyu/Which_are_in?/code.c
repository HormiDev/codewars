#include <stdlib.h>
#include <string.h>

void	ft_lexicographical_ordered(char ***array, int size)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (strcmp((*array)[i], (*array)[j]) > 0)
			{
				tmp = (*array)[i];
				(*array)[i] = (*array)[j];
				(*array)[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

char** inArray(char* array1[], int sz1, char* array2[], int sz2, int* lg) {
	char **result;
	int result_size = 0;
	int i = 0;
	int j = 0;

	while (i < sz1)
	{
		j = 0;
		while (j < sz2)
		{
		if (strstr(array2[j], array1[i]) != NULL)
		{
			result_size++;
			break;
		}
		j++;
		}
		i++;
	}
	*lg = result_size;
	result = malloc(sizeof(char *) * (result_size));
	i = 0;
	result_size = 0;
	while (i < sz1)
	{
		j = 0;
		while (j < sz2)
		{
		if (strstr(array2[j], array1[i]) != NULL)
		{
			result[result_size] = strdup(array1[i]);
			result_size++;
			break;
		}
		j++;
		}
		i++;
	}
	ft_lexicographical_ordered(&result, *lg);
	return (result);
}

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char *a1[] = {"arp", "live", "strong"};
	char *a2[] = {"lively", "alive", "harp", "sharp", "armstrong"};
	int lg;
	char **result = inArray(a1, 3, a2, 5, &lg);
	int i = 0;
	while (i < lg)
	{
		printf("%s\n", result[i]);
		i++;
	}
	return 0;
}