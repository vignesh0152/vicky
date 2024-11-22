#include <stdio.h>
void printPattern1() {
    int rows = 5;
    for (int i = 1; i <= rows; i++) {
        int count = i <= 3 ? (2 * i - 1) : (2 * (rows - i) + 1);
        for (int j = 1; j <= count; j++) {
            printf("%d", j);
        }
        printf("\n");
    }
}
void printPattern2() {
    int width = 5, height = 5;

    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= width; j++) {
            if (i == 1 || i == height || j == 1 || j == width) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
int main() {
    printf("Pattern 1:\n");
    printPattern1();

    printf("\nPattern 2:\n");
    printPattern2();

    return 0;
}
