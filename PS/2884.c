#include <stdio.h>

int main() {
	int h, m;
	int i;

	scanf("%d %d", &h,&m);

	if ( m >= 45) {
		printf("%d %d", h, m - 45);
		
	}
	else {
		
		if (h == 0) {
			h = 23;
			printf("%d %d", h, 60 + m - 45);
		}
		else {
			printf("%d %d", h - 1, 60 + m - 45);
		}
		
	}

	return 0;
}