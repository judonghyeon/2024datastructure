/*
* 프로그램: 13일 1장 마무리 실습 프로그램 
* 실습일: 2024/03/13
* 실습자: 주동현
* 학번: 202311442
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int sum1(int n) {
    int sum = 0;
    sum = (n * (n + 1)) / 2;
    return sum;
}

int sum2(int n) {
    int sum = 0;
    for (int i = 0; i <= n; i++) {
        sum = sum + i;
    }
    return sum;
}

int sum3(int n) {
    int sum = 0;
    for (int i = 0; i <= n; i++) {
        sum = sum + (i * 1);
    }
    return sum;
}

void findMaxAttempts(int (*func)(int)) {
    clock_t start, finish;
    double duration;
    int attempt = 10; // 초기 시도 횟수 설정
    int lastSuccessfulAttempt = attempt; // 마지막으로 성공한 시도 횟수
    double lastDuration = 0; // 마지막으로 성공한 시도의 실행 시간

    while (1) {
        start = clock();
        for (int i = 0; i < attempt; i++) {
            func(2000); // 함수 실행
        }
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;
        printf("%d번, %lf초\n",attempt, duration);
        if (duration > 1.0) { // 실행 시간이 1초를 초과할 경우
            printf("%d 번의 시도까지 1초 이하입니다. 마지막 시도 시간: %f 초\n", lastSuccessfulAttempt, lastDuration);
            printf("%d 번의 시도에 걸린 시간: %f 초이며 1초를 초과했습니다.\n", attempt, duration);
            break; // 반복문 탈출
        }
        lastSuccessfulAttempt = attempt; // 성공한 시도 횟수 갱신
        lastDuration = duration; // 성공한 시도의 시간 갱신
        attempt *= 10; // 시도 횟수 10배 증가
    }
}

int main() {
    printf("sum1 함수의 최대 시도 횟수 찾기\n");
    findMaxAttempts(sum1);

    printf("sum2 함수의 최대 시도 횟수 찾기\n");
    findMaxAttempts(sum2);

    printf("sum3 함수의 최대 시도 횟수 찾기\n");
    findMaxAttempts(sum3);

    return 0;
}
