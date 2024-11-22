#include <stdio.h>

int main() {
    FILE *inputFile, *outputFile;
    char ch;
    int vowels[5] = {0, 0, 0, 0, 0}; // a, e, i, o, u
    int consonantCount = 0;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Cannot open input file.\n");
        return 1;
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: Cannot open output file.\n");
        fclose(inputFile);
        return 1;
    }

    while ((ch = fgetc(inputFile)) != EOF) {
        if (ch >= 'A' && ch <= 'Z') ch = ch + 32;
        if (ch == 'a') vowels[0]++;
        else if (ch == 'e') vowels[1]++;
        else if (ch == 'i') vowels[2]++;
        else if (ch == 'o') vowels[3]++;
        else if (ch == 'u') vowels[4]++;
        else if ((ch >= 'a' && ch <= 'z')) consonantCount++;
    }

    fprintf(outputFile, "Frequency of vowels:\n");
    fprintf(outputFile, "a: %d\n", vowels[0]);
    fprintf(outputFile, "e: %d\n", vowels[1]);
    fprintf(outputFile, "i: %d\n", vowels[2]);
    fprintf(outputFile, "o: %d\n", vowels[3]);
    fprintf(outputFile, "u: %d\n", vowels[4]);
    fprintf(outputFile, "Total consonants: %d\n", consonantCount);

    fclose(inputFile);
    fclose(outputFile);

    return  0;
}

