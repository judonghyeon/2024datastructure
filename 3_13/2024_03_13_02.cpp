/*
* 프로그램: 13일 실습 프로그램 3개
* 실습일: 2024/03/13
* 실습자: 주동현
* 학번: 202311442
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ARMAX 50
int copy();
int find_max_score(int score[], int n);
int copy() {
	int a[] = { 10,20,30 };
	int b[5], i, x=2018, y=0;
	y = x;
	for (i = 0;i < 5;i++) {
		b[i] = a[i];
	}
	printf("변수 복사 결과: x = %d, y = %d\t",x,y );
	printf("배열 복사 결과:\n");
	for (i = 0;i < 5;i++) {
		printf("a[%d] = %d\t", i, a[i]);
		printf("a[%d] = %d\n", i, b[i]);
	}
	return 0;
}
int find_max_score(int score[], int n) {
	int max = 0;
	for (int i = 0;i < n;i++) {
		score[i] = rand();
	}
	for (int i = 0;i < n; i++){
		if (score[i] > max) {
			max = score[i];
		}
	}
	for (int i = 0;i < n;i++) {
		printf("score[%d] = %d\n", i, score[i]);
	}
	printf("가장 큰 수는 %d 입니다.",  max);
	return 0;
}
int find_larger_array(int score2[], int score3[], int z) {
	int max2 = 0, max3 = 0;
	for (int i = 0;i < z;i++) {
		score2[i] = rand();
	}
	for (int i = 0;i < z;i++) {
		score3[i] = rand();
	}
	for (int i = 0;i < z;i++) {
		if (score2[i] > max2) {
			max2 = score2[i];
		}
		if (score3[i] > max3) {
			max3 = score3[i];
		}
	}
	if (max2 > max3) {
		printf("가장 큰 숫자는 score2의 %d 입니다.", max2);
	}
	else {
		printf("가장 큰 숫자는 score3의 %d 입니다.", max3);
	}
	return 0;
}
int main() {
	int score[ARMAX] = {};
	int score2[ARMAX] = {};
	int score3[ARMAX] = {};
	srand(time(NULL));

	find_larger_array(score2, score3, 5);// score2, score3, 시행 횟수
	find_max_score(score, 5);// score 리스트, 시행 횟수
	copy();// 변수, 배열 복사
}