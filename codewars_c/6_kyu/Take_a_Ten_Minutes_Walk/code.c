#include <stdbool.h>
#include <string.h>

bool isValidWalk(const char *walk) {
	int len = strlen(walk);
	if (len != 10)
		return false;
	int x = 0, y = 0;
	while (len > 0) {
		if (walk[len - 1] == 'n')
			y++;
		else if (walk[len - 1] == 's')
			y--;
		else if (walk[len - 1] == 'e')
			x++;
		else if (walk[len - 1] == 'w')
			x--;
		else
			return false;
		len--;
	}
	if (x == 0 && y == 0)
		return true;
	return false;
}

#include <stdio.h>
int main(int argc, char const *argv[])
{
	if (argc != 2)
		return 1;
	if (isValidWalk(argv[1]))
		printf("ruta valida\n");
	else
		printf("ruta invalida\n");
}