#include <stdio.h>

// Hàm 1: Nhập số lượng học sinh
int inputStudentCount() {
    int n;
    do {
        printf("How many students? ");
        scanf("%d", &n);
        if (n < 2 || n > 20) {
            printf("Invalid input! Please enter a number from 2 to 20.\n");
        }
    } while (n < 2 || n > 20);
    return n;
}