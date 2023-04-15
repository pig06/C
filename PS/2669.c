#include <stdio.h>

#define SIZE 100

int main() {
	int coor[SIZE][SIZE];
	int i, j;
	int x1, y1, x2, y2 ,a , b, c ,d;
	int surface = 0;

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++)
			coor[i][j] = 0;
	}

	for (i = 0; i < 4; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		
		for (a = x1; a < x2; a++) {
			for (b = y1; b < y2; b++) {
				coor[a][b] = 1;
			}
		}
	}

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			if (coor[i][j] == 1)
				surface++;
		}
	}

	printf("%d\n", surface);
	return 0;
}