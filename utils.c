#include "utils.h"
#include <math.h>
#include <stdbool.h>
int getDigit(int num, int digitPos) {
    return (num / (int)pow(10, 4 - digitPos)) % 10;
}
bool isValidNum(int num) {
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
