#include "terminal.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#define WIDTH (55)
int beforeTurn(Game* const game) {
    printf("------------------------------\n");
    printf("Turn #%d. The number of possible answer is %d. AI's choice is to guess ", game->turnCnt + 1, game->possibleCnt);
    int aiGuess = makeGuess(game);
    printNum(aiGuess);
    puts("");
    return aiGuess;
}
int requestNewGuess(int aiGuess) {
    int newGuess = 0;
    printWithWidth("Input a guess or press enter to take AI's choice:", WIDTH);
    do {
        fflush(stdin);
        char s[10];
        fgets(s, 10, stdin);
        s[strlen(s) - 1] = '\0';
        newGuess = strlen(s) == 0 ? aiGuess : atoi(s);
        if (!isValidNum(newGuess)) {
            printWithWidth("Your guess is invalid. Input again:", WIDTH);
        }
    } while (!isValidNum(newGuess));
    return newGuess;
}
Result requestNewGuessResult() {
    Result newResult = {0};
    printWithWidth("Input the result of the new guess:", WIDTH);
    do {
        fflush(stdin);
        scanf("%d%d", &newResult.A, &newResult.B);
        if (!isValidResult(newResult)) {
            printWithWidth("Your result is invalid. Input again:", WIDTH);
        }
    } while (!isValidResult(newResult));
    return newResult;
}
void endGame(Game* const game, GameResult gameResult) {
    printf("------------------------------\n");
    if (gameResult == Correct) {
        printf("Congratulations! You've guessed the correct number in %d steps!\n", game->turnCnt);
    } else if (gameResult == Impossible) {
        printf("Oops! It seems that there's something wrong with the input, since a number satisfying such input does not exist.\n");
    }
}
