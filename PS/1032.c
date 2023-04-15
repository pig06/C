//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define SIZE 50
//
//char check(char file[SIZE][SIZE + 1], int idx , int n);
//
//
//int main() {
//	int n, i ,len;
//
//	char file[SIZE][SIZE + 1];
//	char result[SIZE + 1];
//
//	memset(file, NULL, sizeof(char) * SIZE * (SIZE + 1));
//	memset(result, NULL, sizeof(char) *(SIZE + 1));
//
//	scanf("%d", &n);
//	for (i = 0; i < n; i++) {
//		scanf("%s", &file[i]);
//	}
//
//	len = strlen(file[0]);
//
//	for (i = 0; i < len; i++) {
//		result[i] = check(file, i, n);
//	}
//
//	printf("%s", result);
//	
//	return EXIT_SUCCESS;
//}
//
//char check(char file[SIZE][SIZE + 1], int idx , int n) {
//	int i;
//	for (i = 0; i < n; i++) {
//		if ( file[0][idx] != file[i][idx]) return '?';
//	}
//	return file[0][idx];
//	
//}