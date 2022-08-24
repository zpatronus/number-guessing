/**
 * @file terminal.h
 * @brief contains everything related with I/O and terminal operations
 */
#ifndef AD4F26AC_95E9_4F12_A2FD_84EF02868891
#define AD4F26AC_95E9_4F12_A2FD_84EF02868891
#include "Game.h"
/**
 * @brief print information of the game and the smart guess chosen by AI
 *
 * @param game the pointer of the game
 * @return int the smart guess chosen by AI
 */
int beforeTurn(Game* game);
/**
 * @brief request a valid guess from the user;
 * if the user press enter without inputting anything, use the AI's guess as user's guess
 *
 * @param aiGuess the smart guess chosen by AI
 * @return int the number chosen by the user
 */
int requestNewGuess(int aiGuess);
/**
 * @brief request a valid comparing result of the user's guess and the correct answer
 *
 * @return Result  the comparing result of the user's guess and the correct answer
 */
Result requestNewGuessResult();
/**
 * @brief print information when the game is end
 *
 * @param game the pointer of the game
 * @param gameResult the game's result
 */
void endGame(Game* game, GameResult gameResult);
#endif /* AD4F26AC_95E9_4F12_A2FD_84EF02868891 */
