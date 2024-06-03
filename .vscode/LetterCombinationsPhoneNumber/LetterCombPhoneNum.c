#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to map digit to corresponding letters
const char* getLetters(char digit) {
    switch (digit) {
        case '2': return "abc";
        case '3': return "def";
        case '4': return "ghi";
        case '5': return "jkl";
        case '6': return "mno";
        case '7': return "pqrs";
        case '8': return "tuv";
        case '9': return "wxyz";
        default: return "";
    }
}

// Recursive function to generate combinations
void backtrack(char** result, int* returnSize, char* currentCombination, int index, const char* digits) {
    if (index == strlen(digits)) {
        result[*returnSize] = strdup(currentCombination);
        (*returnSize)++;
        return;
    }

    const char* letters = getLetters(digits[index]);
    for (int i = 0; i < strlen(letters); i++) {
        currentCombination[index] = letters[i];
        backtrack(result, returnSize, currentCombination, index + 1, digits);
    }
}

// Main function to return all possible letter combinations
char** letterCombinations(char* digits, int* returnSize) {
    *returnSize = 0;
    if (strlen(digits) == 0) return NULL;

    int maxCombinations = 1;
    for (int i = 0; i < strlen(digits); i++) {
        const char* letters = getLetters(digits[i]);
        maxCombinations *= strlen(letters);
    }

    char** result = (char**)malloc(maxCombinations * sizeof(char*));
    char* currentCombination = (char*)malloc((strlen(digits) + 1) * sizeof(char));
    currentCombination[strlen(digits)] = '\0';

    backtrack(result, returnSize, currentCombination, 0, digits);

    free(currentCombination);
    return result;
}

// Helper function to print the result
void printResult(char** result, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s\n", result[i]);
        free(result[i]);
    }
    free(result);
}

int main() {
    char digits[] = "29";
    int returnSize;
    char** result = letterCombinations(digits, &returnSize);

    if (result != NULL) {
        printResult(result, returnSize);
    } else {
        printf("No combinations found.\n");
    }

    return 0;
}