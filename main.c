#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Game.h"
#include "terminal.h"
#include "utils.h"
int main(void) {
    srand(time(NULL));
    Game game;
    initGame(&game);
    while (1) {
        int aiGuess = beforeTurn(&game);
        int guess = requestNewGuess(aiGuess);
        Result res = requestNewGuessResult();
        GameResult gameResult = takeGuessResult(&game, guess, res);
        if (gameResult != Ongoing) {
            endGame(&game, gameResult);
            break;
        }
    }
    return 0;
}
