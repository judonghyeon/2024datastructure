/*
* ���α׷�: 13�� 1�� ������ �ǽ� ���α׷� 
* �ǽ���: 2024/03/13
* �ǽ���: �ֵ���
* �й�: 202311442
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
    int attempt = 10; // �ʱ� �õ� Ƚ�� ����
    int lastSuccessfulAttempt = attempt; // ���������� ������ �õ� Ƚ��
    double lastDuration = 0; // ���������� ������ �õ��� ���� �ð�

    while (1) {
        start = clock();
        for (int i = 0; i < attempt; i++) {
            func(2000); // �Լ� ����
        }
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;
        printf("%d��, %lf��\n",attempt, duration);
        if (duration > 1.0) { // ���� �ð��� 1�ʸ� �ʰ��� ���
            printf("%d ���� �õ����� 1�� �����Դϴ�. ������ �õ� �ð�: %f ��\n", lastSuccessfulAttempt, lastDuration);
            printf("%d ���� �õ��� �ɸ� �ð�: %f ���̸� 1�ʸ� �ʰ��߽��ϴ�.\n", attempt, duration);
            break; // �ݺ��� Ż��
        }
        lastSuccessfulAttempt = attempt; // ������ �õ� Ƚ�� ����
        lastDuration = duration; // ������ �õ��� �ð� ����
        attempt *= 10; // �õ� Ƚ�� 10�� ����
    }
}

int main() {
    printf("sum1 �Լ��� �ִ� �õ� Ƚ�� ã��\n");
    findMaxAttempts(sum1);

    printf("sum2 �Լ��� �ִ� �õ� Ƚ�� ã��\n");
    findMaxAttempts(sum2);

    printf("sum3 �Լ��� �ִ� �õ� Ƚ�� ã��\n");
    findMaxAttempts(sum3);

    return 0;
}
