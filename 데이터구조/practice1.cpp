/*
* 프로그램:배열에 저장된 정수 점수의 최댓값을 구하는 문제
* 실습일: 2024/03/08
* 실습자: 주동현
* 학번: 202311442
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
