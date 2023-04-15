#include <stdio.h>

int main() {
	int i, n, result = 0 ,t;
	int num[101] = { 0 };
	scanf_s("%d", &n);

	for (i = 0; i < n; i++) {
		scanf_s("%d", &t);
		if (num[t] == 0) {
			num[t]++;
		}
		else result++;
	}

	printf("%d", result);
}