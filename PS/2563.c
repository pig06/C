#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX 100

int main() {
	int board[MAX][MAX];
	int n, x, y;
	int i, j;
	int result = 0;
	int a, b;
	scanf("%d", &n);

	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			board[i][j] = FALSE;
		}
	}

	for (i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		
		for (a = x; a < x + 10; a++) {
			for (b = y; b < y + 10; b++) {
				board[a][b] = TRUE;
			}
		}
	}
	
	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			if (board[i][j] == TRUE)
				result++;
		}
	}

	printf("%d", result);


}