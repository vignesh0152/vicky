// Write a C program that reads a text file and computes the frequency of each of the vowels and total count of consonants? Write the output in output.txt file.

#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *inputFile, *outputFile;
    char ch;
    int vowels[5] = {0}; // Array to store count of a, e, i, o, u
    int consonants = 0;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Cannot open input file.\n");
        return 1;
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Cannot open output file.\n");
        return 1;
    }

    while ((ch = fgetc(inputFile)) != EOF) {
        ch = tolower(ch);
        if (ch == 'a') vowels[0]++;
        else if (ch == 'e') vowels[1]++;
        else if (ch == 'i') vowels[2]++;
        else if (ch == 'o') vowels[3]++;
        else if (ch == 'u') vowels[4]++;
        else if (isalpha(ch)) consonants++;
    }

    fprintf(outputFile, "Frequency of vowels:\n");
    fprintf(outputFile, "a: %d\n", vowels[0]);
    fprintf(outputFile, "e: %d\n", vowels[1]);
    fprintf(outputFile, "i: %d\n", vowels[2]);
    fprintf(outputFile, "o: %d\n", vowels[3]);
    fprintf(outputFile, "u: %d\n", vowels[4]);
    fprintf(outputFile, "Total count of consonants: %d\n", consonants);

    fclose(inputFile);
    fclose(outputFile);

    printf("Output written to output.txt\n");

    return 0;
}   	