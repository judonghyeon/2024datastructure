/*
* ���α׷�:�迭�� ����� ���� ������ �ִ��� ���ϴ� ����
* �ǽ���: 2024/03/08
* �ǽ���: �ֵ���
* �й�: 202311442
*/
#include <stdio.h>
#define MAX 5
int find_max_score(int* score, int n);

int main()
{
	int i, result;
	int score[MAX];
	for (i = 0; i < MAX; i++) {
		printf("Enter a score:");
		scanf_s("%d", &score[i]);
	}
	result = find_max_score(score, MAX);
	printf("\nHighest score is: %d", result);
	return 0;
}

int find_max_score(int *score, int n) {
	int i, tmp;
	tmp = *score;
	for (i = 1; i < n; i++) {
		if (*(score+i) > tmp) {
			tmp = *(score+i);
		}
	}
	return tmp;
}
