#include "terminal.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#define WIDTH (85)
int beforeTurn(const Game* const game) {
    // Implement this function in milestone 3. It takes about 6 lines of code.
    printf("------------------------------\n");
    printf("Turn #%d. The number of possible answer is %d. AI's choice is to guess ", game->turnCnt + 1, game->possibleCnt);
    int aiGuess = makeGuess(game);
    printNum(aiGuess);
    puts("");
    return aiGuess;
}
int requestNewGuess(const int aiGuess) {
    // Implement this function in milestone 3. It takes about 17 lines of code.
    int newGuess = 0;
    printWithWidth("Input a guess, press enter to take AI's choice, or input '-' to revert 1 turn:", WIDTH);
    do {
        fflush(stdin);
        char s[10];
        fgets(s, 10, stdin);
        s[strlen(s) - 1] = '\0';
        if (strlen(s) == 1 && s[0] == '-') {
            printf("Revert to last turn.\n");
            return -1;
        }
        newGuess = strlen(s) == 0 ? aiGuess : atoi(s);
        if (!isValidNum(newGuess)) {
            printWithWidth("Your guess is invalid. Input again:", WIDTH);
        }
    } while (!isValidNum(newGuess));
    return newGuess;
}
Result requestNewGuessResult(const int guess) {
    // Implement this function in milestone 3. It takes about 12 lines of code.
    Result newResult = {0};
    char info[50];
    sprintf(info, "Input the result of the new guess %d%d%d%d:", getDigit(guess, 1), getDigit(guess, 2), getDigit(guess, 3), getDigit(guess, 4));
    printWithWidth(info, WIDTH);
    do {
        fflush(stdin);
        scanf("%d%d", &newResult.A, &newResult.B);
        if (!isValidResult(newResult)) {
            printWithWidth("Your result is invalid. Input again:", WIDTH);
        }
    } while (!isValidResult(newResult));
    return newResult;
}
void endGame(const Game* const game, const GameResult gameResult) {
    // Implement this function in milestone 3. It takes about 6 lines of code.
    printf("------------------------------\n");
    if (gameResult == Correct) {
        printf("Congratulations! You've guessed the correct number in %d steps!\n", game->turnCnt);
    } else if (gameResult == Impossible) {
        printf("Oops! It seems that there's something wrong with the input, since a number satisfying such input does not exist.\n");
    }
}
