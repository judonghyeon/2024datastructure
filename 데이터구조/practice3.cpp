/*
* 2번째 실습
* 프로그램:배열에 저장된 정수 점수의 최댓값을 구하는 문제
* 실습일: 2024/03/08
* 실습자: 주동현
* 학번: 202311442
*/
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define MAX 100000
int find_max_score(int* score, int n);

int main()
{
	clock_t start, finish;
	double duration;
	start = clock();
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
	printf("Highest score is: %d\n", result);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%f 초 입니다.\n", duration);
	return 0;
	
}

int find_max_score(int* score, int n) {
	int i, tmp;
	tmp = *score;
	for (i = 1; i < n; i++) {
		if (*(score + i) > tmp) {
			tmp = *(score + i);
		}
	}
	return tmp;
}
