/*
* 2��° �ǽ�
* ���α׷�:�迭�� ����� ���� ������ �ִ��� ���ϴ� ����
* �ǽ���: 2024/03/08
* �ǽ���: �ֵ���
* �й�: 202311442
*/
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define MAX 10000
// 100�� ���� ���� �߻�
int find_max_score(int* score, int n);

int main()
{
	int i, result;
	int score[MAX];
	long seed;
	seed = time(NULL);
	srand(seed);
	for (i = 0; i < MAX; i++) {
		/*
		printf("Enter a score:");
		scanf_s("%d", &score[i]);
		*/
		score[i] = rand() % 101;
	}
	result = find_max_score(score, MAX);
	printf("Highest score is: %d", result);
	return 0;
}

int find_max_score(int* score, int n) {
	int i, tmp;
	tmp = *score;
	for (i = 0; i < n; i++) {
		if (*(score + i) > tmp) {
			tmp = *(score + i);
		}
		//printf("%d ", score[i]);
	}
	return tmp;
}