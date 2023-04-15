#include <stdio.h>

int main() {
	char str[101];
	int i = 1;

	scanf_s("%s", str);

	printf("%c", str[0]);

	while (str[i] != NULL) {
		if (str[i] == '-') {
			i++;
			printf("%c", str[i]);
		}

		i++;
	}

	return 0;
	

}