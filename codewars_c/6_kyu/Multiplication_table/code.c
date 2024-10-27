#include <stdlib.h>

int **multiplication_table(int n) 
{
	int **table = (int **)malloc(n * sizeof(int *));
	int i = 0, j = 0;

	while (i < n)
	{
		table[i] = (int *)malloc(n * sizeof(int));
		while (j < n)
		{
			table[i][j] = (i + 1) * (j + 1);
			j++;
		}
		j = 0;
		i++;
	}
	return (table);
}

#include <stdio.h>
int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int **table = multiplication_table(atoi(argv[1]));
		int i = 0, j = 0;
		while (i < atoi(argv[1]))
		{
			while (j < atoi(argv[1]))
			{
				printf("%d	", table[i][j]);
				j++;
			}
			printf("\n");
			j = 0;
			i++;
		}
		free(table);
	}
}
