#include <stdio.h>

int main()
{
	int i;
	int n;
	int h = 0;
	int cnt = 1;
	int num[1000000];

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}

	h = num[n - 1];

	for (i = n - 1; i >=  0;i--) {
		if (h < num[i]) {
			cnt++;
			h = num[i];
		}

	}

	printf("%d", cnt);

}