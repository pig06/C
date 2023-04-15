#include <stdio.h>

void get_avg(int arr[10]);  // 평균을 출력하는 함수
void get_freq(int arr[10]); // 최빈값을 출력하는 함수

int main()
{
	int i, j;
	int arr[10] = { 0 };
	for (i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
		
	}
	get_avg(arr);
	get_freq(arr);
}

void get_avg(int arr[10]) {
	int i, avg;
	for (i = 0; i < 10; i++) {
		avg += arr[i];
	}
	avg /= 10;
	printf("%d", avg);
}


void get_freq(int arr[10]) {
	int arr2[100] = { 0 };
	int i, t, max = 0;

	for (i = 0; i < 10; i++) {
		arr2[arr[i] / 10]++;
	}
	for (i = 0; i < 10; i++) {
		if (max < arr2[i])
		{
			max = arr2[i];
			t = i;
		}
	}
	printf("%d", t * 10);
}