#include <stdlib.h>

int *snail(size_t *outsz, const int **mx, size_t rows, size_t cols) {
	*outsz = rows * cols;
	size_t min_rows = 0, min_cols = 0, i, j, count = 0;
	int *result;
	
	result = (int *)malloc(sizeof(int) * *outsz);
	while (count < *outsz)
	{
		i = min_rows;
		j = min_cols;
		while (j < cols && count < *outsz)
			result[count++] = mx[i][j++];
		min_rows++;
		j--;
		i++;
		while (i < rows && count < *outsz)
			result[count++] = mx[i++][j];
		cols--;
		i--;
		j--;
		while (j >= min_cols && count < *outsz)
		{
			result[count++] = mx[i][j];
			if (j == min_cols)
				break;
			j--;
		}
		rows--;
		i--;
		while (i >= min_rows && count < *outsz)
			result[count++] = mx[i--][j];
		min_cols++;
	}
 	return (result);
}

#include <stdio.h>
int main()
{
	int	*result;
	const int *mx[3] = {	(int[]){1, 2, 3},
							(int[]){4, 5, 6},
							(int[]){7, 8, 9} };
	int i, j;
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
			printf("%d ", mx[i][j++]);
		printf("\n");
		i++;
	}
	printf("\n");
	size_t outsz, rows = 3, cols = 3;
	result = snail(&outsz, mx, rows, cols);
	for (size_t i = 0; i < outsz; i++)
		printf("%d ", result[i]);
	free(result);
	return 0;
}
