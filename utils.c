#include "utils.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "Game.h"
int getDigit(int num, int digitPos) {
    return (num / (int)pow(10, 4 - digitPos)) % 10;
}
bool isValidNum(int num) {
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
bool isValidResult(Result res) {
    if (res.A + res.B > 4 || res.A < 0 || res.B < 0) {
        return false;
    }
    if (res.A == 3 && res.B == 1) {
        return false;
    }
    return true;
}
void printNum(int num) {
    for (int i = 1; i <= 4; i++) {
        printf("%d", getDigit(num, i));
    }
}
void printWithWidth(char s[], int width) {
    printf("%s", s);
    for (int i = strlen(s) + 1; i <= width; i++) {
        printf(" ");
    }
}
