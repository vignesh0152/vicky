#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    if (!input || !output) return 1;

    int num, total_count = 0, prime_count = 0;
    while (fscanf(input, "%d", &num) == 1) {
        total_count++;
        if (is_prime(num)) prime_count++;
    }

    fprintf(output, "Total Count: %d\nPrime Numbers Count: %d\n", total_count, prime_count);

    fclose(input);
    fclose(output);
    return 0;
}
