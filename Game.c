#include "Game.h"
#include <assert.h>
#include "utils.h"
void initGame(Game* game) {
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
Result judgeGuess(int correctNum, int guessNum) {
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
void updateGameWithLastTurn(Game* game) {
    game->possibleCnt = 0;
    int theGuess = game->guesses[game->turnCnt];
    Result theResult = game->results[game->turnCnt];
    for (int i = 0; i < MAX_POSSIBLE; i++) {
        Result judge = judgeGuess(theGuess, game->num[i]);
        if (judge.A != theResult.A || judge.B != theResult.B) {
            game->isPossible[i] = false;
        }
        game->possibleCnt += game->isPossible[i];
    }
}
GameResult takeGuessResult(Game* game, int guess, Result result) {
    game->turnCnt++;
    game->guesses[game->turnCnt] = guess;
    game->results[game->turnCnt] = result;
    updateGameWithLastTurn(game);
    if (result.A == 4) {
        return Correct;
    }
    if (game->possibleCnt == 0) {
        return Impossible;
    }
    return Ongoing;
}
int makeGuess(Game* game) {
    for (int i = 0; i < MAX_POSSIBLE; i++) {
        if (game->isPossible[i]) {
            return game->num[i];
        }
    }
    return 0;
}
