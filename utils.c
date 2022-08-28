#include "utils.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "Game.h"
int getDigit(const int num, const int digitPos) {
    // Implement this function in milestone 1. It takes about 1 line of code.
    return (num / (int)pow(10, 4 - digitPos)) % 10;
}
bool isValidNum(int num) {
    // Implement this function in milestone 1. It takes about 13 lines of code.
    if (num < 0 || 9999 < num) {
        return false;
    }
    int digits[5] = {0};
    for (int i = 1; i <= 4; i++) {
        digits[i] = getDigit(num, i);
        for (int j = 1; j < i; j++) {
            if (digits[i] == digits[j]) {
                return false;
            }
        }
    }
    return true;
}
bool isValidResult(const Result res) {
    // Implement this function in milestone 1. It takes about 8 lines of code.
    if (res.A + res.B > 4 || res.A < 0 || res.B < 0) {
        return false;
    }
    if (res.A == 3 && res.B == 1) {
        return false;
    }
    return true;
}
void printNum(const int num) {
    // Implement this function in milestone 1. It takes about 3 lines of code.
    for (int i = 1; i <= 4; i++) {
        printf("%d", getDigit(num, i));
    }
}
void printWithWidth(const char s[], const int width) {
    // Implement this function in milestone 1. It takes about 4 lines of code.
    printf("%s", s);
    for (int i = strlen(s) + 1; i <= width; i++) {
        printf(" ");
    }
}
