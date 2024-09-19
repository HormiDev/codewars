unsigned decode_roman (const char *roman_number)
{
	int result = 0;
	int i = 0;

	while (roman_number[i] != 0)
	{
		if (roman_number[i] == 'M')
		{
			result += 1000;
		}
		else if (roman_number[i] == 'D')
		{
			result += 500;
		}
		else if (roman_number[i] == 'C')
		{
			if (roman_number[i + 1] == 'M')
			{
				result += 900;
				i++;
			}
			else if (roman_number[i + 1] == 'D')
			{
				result += 400;
				i++;
			}
			else
			{
				result += 100;
			}
		}
		else if (roman_number[i] == 'L')
		{
			result += 50;
		}
		else if (roman_number[i] == 'X')
		{
			if (roman_number[i + 1] == 'C')
			{
				result += 90;
				i++;
			}
			else if (roman_number[i + 1] == 'L')
			{
				result += 40;
				i++;
			}
			else
			{
				result += 10;
			}
		}
		else if (roman_number[i] == 'V')
		{
			result += 5;
		}
		else if (roman_number[i] == 'I')
		{
			if (roman_number[i + 1] == 'X')
			{
				result += 9;
				i++;
			}
			else if (roman_number[i + 1] == 'V')
			{
				result += 4;
				i++;
			}
			else
			{
				result += 1;
			}
		}
		i++;
	}
	return result;
}


#include <stdio.h>
int main (int argc, char *argv[])
{
	int i = 1;
	while (argc > i)
	{
		printf("%d\n", decode_roman(argv[i]));
		i++;
	}
	return 0;
}