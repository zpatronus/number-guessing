# Demo Project: Number Guessing Game - Milestone 2

## Tips and Tricks

Try to reuse code as much as possible, i.e. **use functions you have implemented**. This not only allows you to write fewer lines of code but also provides convenience and efficiency when debugging.

## Task 0: Understand `Game` Struct

You can find the declaration of the `Game` struct in `Game.h` header file. All the variables in this abstract data type are commented. We think `num[]` is probably the most confusing one to understand so we are going to explain more about it here and in the lab session. 

It is obvious that not all the 4-digit number is valid. Number like 1223 has a repeated digit 2. The integer array `num[]` stores all the valid number in an ascending order from index=0, i.e.

```plain
num[0]=123
num[1]=124
num[2]=125
...
```

You can think of this array as a map that links a valid number with an index.

`isPossible[]`, a boolean array, as commented in the header file, stores whether a number is possible to be the final answer given a set of guesses and comparing results. 

## Task 1: Implement `initGame`

This function accepts a pointer to a `Game` struct `game` and initializes it. 

*Hint: if your initialization is correct, `possibleCnt` should be 5040, exactly equal MAX_POSSIBLE defined at the beginning of the header file, and `num[5039]` should be 9876, the max possible number.*

## Task 2: Implement `judgeGuess`

This function accepts two integers, one is the correct number `correctNum` and the other is the guessed number `guessNum`. 

The function should return the comparing result between the two numbers. 

## Task 3: Implement `updateGameWithTurn`

This function accepts a pointer to a `Game` struct `game` and an integer `turn`. It updates `possibleCnt` and `isPossible[]` in `game` by the set of guess and result of `turn`. 

That is to say, if `num[i]` does not satisfy `game->guesses[turn]` and `game->results[turn]`, `isPossible[i]` should be assigned `false`, meaning `num[i]` is impossible to be the final answer.

You do not need to update `game` with other set of guess and result in `game`. 

## Task 4: Implement `takeGuessResult`

This function accepts a pointer to a `Game` struct `game`, an integer `guess` representing the guessed number, and a `Result` struct `result` representing the comparing result. 

The function updates `game` given `guess` and `result`, and then returns the status of the game. 

## Task 5: Implement `revert1Turn`

This function accepts a pointer to a `Game` struct `game` and reverts `game` by 1 turn, i.e. delete the last set of `guess` and `result`.

If there's no `guess` and `result`, i.e. `turnCnt == 0`, print `This is turn #1. Cannot revert.` onto the screen with a new line at the end.
