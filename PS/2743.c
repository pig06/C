#include <stdio.h>

int main()
{
	char str[101];
	int i = 0;

	gets(str);

	while (str[i] != NULL) {
		i++;
	}

	printf("%d", i);
}