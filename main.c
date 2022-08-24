#include <stdio.h>
#include "Game.h"
int main(void) {
    Game game;
    initGame(&game);
    while (1) {
        int guess = makeGuess(&game);
        printf("%d ", guess);
        Result res;
        scanf("%d %d", &res.A, &res.B);
        GameResult res2 = takeGuessResult(&game, guess, res);
        if (res2 == Correct) {
            printf("Correct\n");
        }
    }
    return 0;
}
