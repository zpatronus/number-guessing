#include "Game.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
void initGame(Game* const game) {
    // Implement this function in milestone 2. It takes about 11 lines of code.
    game->turnCnt = 0;
    game->possibleCnt = MAX_POSSIBLE;
    for (int i = 0; i < MAX_POSSIBLE; i++) {
        game->isPossible[i] = true;
    }
    int cnt = 0;
    for (int i = 123; i <= 9876; i++) {
        if (isValidNum(i)) {
            game->num[cnt++] = i;
        }
    }
    assert(cnt == MAX_POSSIBLE);
}
Result judgeGuess(const int correctNum, const int guessNum) {
    // Implement this function in milestone 2. It takes about 10 lines of code.
    Result res = {0};
    for (int i = 1; i <= 4; i++) {
        res.A += getDigit(correctNum, i) == getDigit(guessNum, i);
    }
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            res.B += (i != j) && (getDigit(correctNum, i) == getDigit(guessNum, j));
        }
    }
    return res;
}
void updateGameWithTurn(Game* const game, const int turn) {
    // Implement this function in milestone 2. It takes about 10 lines of code.
    game->possibleCnt = 0;
    int theGuess = game->guesses[turn];
    Result theResult = game->results[turn];
    for (int i = 0; i < MAX_POSSIBLE; i++) {
        Result judge = judgeGuess(theGuess, game->num[i]);
        if (judge.A != theResult.A || judge.B != theResult.B) {
            game->isPossible[i] = false;
        }
        game->possibleCnt += game->isPossible[i];
    }
}
GameResult takeGuessResult(Game* const game, const int guess, const Result result) {
    // Implement this function in milestone 2. It takes about 11 lines of code.
    game->turnCnt++;
    game->guesses[game->turnCnt] = guess;
    game->results[game->turnCnt] = result;
    updateGameWithTurn(game, game->turnCnt);
    if (result.A == 4) {
        return Correct;
    }
    if (game->possibleCnt == 0) {
        return Impossible;
    }
    return Ongoing;
}
void revert1Turn(Game* const game) {
    // Implement this function in milestone 2. It takes about 12 lines of code.
    if (game->turnCnt == 0) {
        printf("This is turn #1. Cannot revert.\n");
        return;
    }
    game->turnCnt--;
    for (int i = 0; i < MAX_POSSIBLE; i++) {
        game->isPossible[i] = true;
    }
    game->possibleCnt = MAX_POSSIBLE;
    for (int i = 1; i <= game->turnCnt; i++) {
        updateGameWithTurn(game, i);
    }
}
int makeGuess(const Game* const game) {
    // Implement this function in milestone 3. It takes about 5 lines of code.
    int i = rand() % 5040;
    while (!game->isPossible[i]) {
        i = (i + 1) % 5040;
    }
    return game->num[i];
}
