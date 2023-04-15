#include <stdio.h>
#include <string.h>

#define MAX 81

int main() {
	int T;
	char str[MAX];
	int mispell;
	int i;
	scanf("%d", &T);
	while (T > 0) {
		memset(str, NULL, MAX * sizeof(char));
		scanf("%d %s", &mispell , str);
		mispell--;

		for (i = mispell; i < MAX - 1; i++) {
			str[i] = str[i + 1];
		}
		printf("%s\n", str);
		
		T--;
	}

	return 0;
}

