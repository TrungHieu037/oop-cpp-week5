#include <stdio.h>

int main() {
    int N;
    float scores[20];

    // 1. Nhập số lượng học sinh (2 <= N <= 20)
    do {
        printf("How many students? ");
        scanf("%d", &N);
        if (N < 2 || N > 20) {
            printf("Invalid input! Please enter a number from 2 to 20.\n");
        }
    } while (N < 2 || N > 20);

    // 2. Nhập điểm từng học sinh (0 <= score <= 10)
    for (int i = 0; i < N; i++) {
        do {
            printf("Enter score for student %d: ", i + 1);
            scanf("%f", &scores[i]);
            if (scores[i] < 0 || scores[i] > 10) {
                printf("Invalid score! Please enter a value from 0 to 10.\n");
            }
        } while (scores[i] < 0 || scores[i] > 10);
    }

    // 3. Hiển thị mảng điểm
    printf("\n===== STUDENT SCORES =====\n");
    for (int i = 0; i < N; i++) {
        printf("Student %d: %.1f\n", i + 1, scores[i]);
    }

    // 4. Kết quả Pass / Fail
    printf("\n===== RESULTS =====\n");
    for (int i = 0; i < N; i++) {
        if (scores[i] >= 5.0) {
            printf("Student %d: %.1f -> PASS\n", i + 1, scores[i]);
        } else {
            printf("Student %d: %.1f -> FAIL\n", i + 1, scores[i]);
        }
    }

    // 5, 6 & 7. Thống kê, Tìm Max/Min và Xếp loại (Gộp chung trong 1 vòng lặp)
    int passed = 0, failed = 0;
    float max = scores[0], min = scores[0];

    for (int i = 0; i < N; i++) {
        // Đếm Pass/Fail
        if (scores[i] >= 5.0) passed++;
        else failed++;

        // Tìm Max/Min
        if (scores[i] > max) max = scores[i];
        if (scores[i] < min) min = scores[i];
    }

    // In thống kê
    printf("\n===== STATISTICS =====\n");
    printf("Passed   : %d students\n", passed);
    printf("Failed   : %d students\n", failed);
    printf("Pass rate: %.0f%%\n", ((float)passed / N) * 100);

    // In Max/Min
    printf("\nHighest score: %.1f\n", max);
    printf("Lowest score : %.1f\n", min);

    // In xếp loại
    printf("\n===== CLASSIFICATION =====\n");
    for (int i = 0; i < N; i++) {
        printf("Student %d: %.1f -> ", i + 1, scores[i]);
        if (scores[i] >= 9.0) printf("Excellent\n");
        else if (scores[i] >= 8.0) printf("Very Good\n");
        else if (scores[i] >= 6.5) printf("Good\n");
        else if (scores[i] >= 5.0) printf("Average\n");
        else printf("Fail\n");
    }

    return 0;
}