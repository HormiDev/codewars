// Memory model of `pyramid`:
// `pyramid` is a one-dimensional array containing the elements of a pyramid with `rows` levels,
// in direct succession from left to right, top to bottom
#include <stdio.h>
/*
int pyramid_slide_up(int num_elements, const int pyramid[num_elements], int rows, int i) {
	int result;
	int row;

	result = 0;
	row = rows;
	while (row > 0)
	{
		//printf("%d + ", pyramid[num_elements - 1 - row + i]);
		result += pyramid[num_elements - 1 - row + i];
		num_elements -= row;
		row--;
		if (row == 0)
			break;
		
		if (i > row)
			i = row;
		else if (i < 1 && pyramid[num_elements - 1 - row + i] < pyramid[num_elements - 1 - row + i - 1])
			i = i - 1;
	}
	//printf("= %d\n", result);
	return (result);
}

int pyramid_slide_down_2(int num_elements, const int pyramid[num_elements], int rows) {
	int result;
	int i;
	int row;

	result = 0;
	i = 0;
	row = 0;
	while (row < rows)
	{
		result += pyramid[i];
		row++;
		i += row;
		if (i >= num_elements)
			break;
		if (pyramid[i] < pyramid[i + 1])
			i++;
	}
	return (result);
}

int pyramid_slide_down(int num_elements, const int pyramid[num_elements], int rows) {
	int result;
	int max_result;
	int i;

	max_result = 0;
	i = 1;
	while (i <= rows)
	{
		result = pyramid_slide_up(num_elements, pyramid, rows, i);
		if (result > max_result)
			max_result = result;
		i++;
	}
	result = pyramid_slide_down_2(num_elements, pyramid, rows);
	if (result > max_result)
		max_result = result;
	return (max_result);
}*/

int pyramid_slide_down_recursive(int num_elements, const int pyramid[num_elements], int rows, int i, int row) {
	int result1;
	int result2;

	if (row == rows)
		return (pyramid[i]);
	result1 = pyramid_slide_down_recursive(num_elements, pyramid, rows, i + row, row + 1);
	result2 = pyramid_slide_down_recursive(num_elements, pyramid, rows, i + row + 1, row + 1);
	if (result1 > result2)
		return (pyramid[i] + result1);
	return (pyramid[i] + result2);
}

int pyramid_slide_down(int num_elements, const int pyramid[num_elements], int rows) {
	int result;

	result = pyramid_slide_down_recursive(num_elements, pyramid, rows, 0, 1);
	return (result);
}

#include <stdio.h>
int main(void) {
	int pyramid1[] = {	     3, 
						   7, 4, 
						  2, 4, 6, 
						8, 5, 9, 3};
	int pyramid2[] = {                            75, 
						                        95, 64,
						                      17, 47, 82, 
						                    18, 35, 87, 10, 
						                  20,  4, 82, 47, 65, 
						                19,  1, 23, 75,  3, 34, 
						              88,  2, 77, 73,  7, 63, 67, 
						            99, 65,  4, 28,  6, 16, 70, 92, 
						          41, 41, 26, 56, 83, 40, 80, 70, 33, 
						         41, 48, 72, 33, 47, 32, 37, 16, 94, 29, 
						       53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14, 
						     70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57, 
						   91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48, 
						  63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31, 
						 4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23};
	printf("%d\n", pyramid_slide_down(10, pyramid1, 4)); // 23
	printf("%d\n", pyramid_slide_down(120, pyramid2, 15)); // 1074
	return 0;
}