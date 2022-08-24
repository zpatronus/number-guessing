#ifndef EEA23FAF_CC23_4072_838D_FCC8847BD8F2
#define EEA23FAF_CC23_4072_838D_FCC8847BD8F2
#define MAX_TURN (20)
#define MAX_POSSIBLE (5040)
#include <stdbool.h>
typedef enum {
    Ongoing,
    Correct,
    Impossible
} GameResult;
typedef struct {
    int A, B;
} Result;
typedef struct {
    int turnCnt;
    int possibleCnt;
    int num[MAX_POSSIBLE];
    bool isPossible[MAX_POSSIBLE];
    int guesses[MAX_TURN];
    Result results[MAX_TURN];
} Game;
void initGame(Game* game);
Result judgeGuess(int correctNum, int guessNum);
void updateGameWithLastTurn(Game* game);
GameResult takeGuessResult(Game* game, int guess, Result result);
int makeGuess(Game* game);
#endif /* EEA23FAF_CC23_4072_838D_FCC8847BD8F2 */
