#include <stdio.h>

int main() {
	int n, i , m = 0 , l = 1000;
	int num[1000];

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		if (m < num[i]) m = num[i];
		if (l > num[i]) l = num[i];
	}
	printf("%d", m - l);
	
	


}