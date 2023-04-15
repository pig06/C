#include <stdio.h>

int main() {
	int avr = 0, max = 0, i, j = 0, a=0;//avr ��� max�ֺ����� j�� �Է� �޴¼� a �� 
	int num[100] = { 0 };

	for (i = 0; i < 10; i++) {
		scanf_s("%d", &j);
		avr += j;
		num[j / 10]++;
	}
	
	avr /= 10;

	for (i = 0; i < 100; i++) {
		if (max < num[i]) {
			max = num[i];
			a = i;
		}

	}

	printf("%d\n%d", avr, a*10);
}