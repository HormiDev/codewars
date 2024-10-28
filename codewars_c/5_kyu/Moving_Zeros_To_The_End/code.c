#include <stddef.h>

void move_zeros(size_t len, int arr[len])
{
    size_t zeros = 0;
	size_t i = 0;

	while (i < len)
	{
		if (arr[i] == 0)
			zeros++;
		else
		{
			arr[i - zeros] = arr[i];
			if (zeros)
				arr[i] = 0;
		}
		i++;
	}
}


#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	int	*arr = (int *)malloc(sizeof(int) * argc - 1);
	int	i = 1;
	size_t	len = argc - 1;

	while (i < argc)
	{
		arr[i - 1] = atoi(argv[i]);
		i++;
	}
	move_zeros(len, arr);
	i = 0;
	while (i < argc - 1)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("|\n");
	free(arr);
	return (0);
}