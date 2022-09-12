# Demo Project: Number Guessing Game

## Brief Introduction to the Game

The AB Number Guessing Game is played with two people. One person chooses a 4-digit number in which no digit is repeated, say X, and the other person tries to guess it in as few turns as possible. After the guesser guesses some number, say Y, the other person gives information on how closely Y matched with X:

- If some digit in Y coincides with a digit in X (in the same position), then it counts an `A`.
- If some digit in Y exists in X but is in the wrong place, then it counts a `B`.

The guesser should be informed of how many `A` and `B` he/she can get. 

For instance, if X is 0123 (yes, starting with 0 is valid in this game) and we guess 1263, we get `1A` and `2B`, because the 3 is in the right place and the 1 and 2 are the right numbers but not in the right place. 

This proceeds until the guesser gets the exact number.

If you are still confusing about the procedure of the game, check out [this page](https://blog.zpatronus.top/2022/04/28/A-Number-Guessing-Game-Bot/) by coming up with a number in your mind and letting the bot guess your number. 

## Background and Goals of the Project

Bob is playing this game with Alice. He finds it quite hard to get the exact number. He reaches out for your help hoping that you can make a program that can record the game and give him some suggestions on which number he should guess. 

```plain
------------------------------
Turn #1. The number of possible answer is 5040. AI's choice is to guess 5943
Input a guess, press enter to take AI's choice, or input '-' to revert 1 turn:
```

At the beginning of every turn, Bob wants to know:

- How many turns of guessing this is. This is shown as `Turn #1.` in the figure.
- How many numbers are still possible to be the correct answer. This is shown as `The number of possible answer is 5040.` in the figure. 
- Which number the smart AI suggests him to guess. This is shown as `AI's choice is to guess 5943` in the figure. 

The program should then ask Bob to guess a number, **and if Bob decides to use the AI's choice**, he can simply press `enter`, without inputting the number.

```plain
------------------------------
Turn #1. The number of possible answer is 5040. AI's choice is to guess 5943
Input a guess, press enter to take AI's choice, or input '-' to revert 1 turn:       1234
Input the result of the new guess 1234:                                              0 2
```

If Bob wants to revert to the last turn he can input `-`.

After Bob guesses a number, Alice should give him the information. The program should require Bob to input the information. For example, if Alice's number is 2468, then Bob gets `0A` and `2B`, which means he should input `0 2` to the program. 

```plain
------------------------------
Turn #1. The number of possible answer is 5040. AI's choice is to guess 5943
Input a guess, press enter to take AI's choice, or input '-' to revert 1 turn:       1234
Input the result of the new guess 1234:                                              0 2
------------------------------
Turn #2. The number of possible answer is 1260. AI's choice is to guess 2450
Input a guess, press enter to take AI's choice, or input '-' to revert 1 turn:
```

After Bob inputs the comparing result, a new turn starts...

### End of the Program

The program ends in two situations:

- If Bob guesses the exact number, i.e. the comparing result is `4A 0B`, the program should end with an information showing how many times he has guessed.

  ```plain
  ------------------------------
  Turn #1. The number of possible answer is 5040. AI's choice is to guess 0697
  Input a guess, press enter to take AI's choice, or input '-' to revert 1 turn:
  Input the result of the new guess 0697:                                              2 0
  ------------------------------
  Turn #2. The number of possible answer is 180. AI's choice is to guess 2597
  Input a guess, press enter to take AI's choice, or input '-' to revert 1 turn:
  Input the result of the new guess 2597:                                              1 0
  ------------------------------
  Turn #3. The number of possible answer is 48. AI's choice is to guess 8617
  Input a guess, press enter to take AI's choice, or input '-' to revert 1 turn:
  Input the result of the new guess 8617:                                              2 1
  ------------------------------
  Turn #4. The number of possible answer is 6. AI's choice is to guess 8691
  Input a guess, press enter to take AI's choice, or input '-' to revert 1 turn:
  Input the result of the new guess 8691:                                              0 2
  ------------------------------
  Turn #5. The number of possible answer is 1. AI's choice is to guess 0817
  Input a guess, press enter to take AI's choice, or input '-' to revert 1 turn:
  Input the result of the new guess 0817:                                              4 0
  ------------------------------
  Congratulations! You've guessed the correct number in 5 steps!
  ```

- If there's something wrong with the information given by Alice, the number of possible answers can be 0. In this case, the program should end with an information showing that something is wrong.

  ```plain
  ------------------------------
  Turn #1. The number of possible answer is 5040. AI's choice is to guess 1687
  Input a guess, press enter to take AI's choice, or input '-' to revert 1 turn:
  Input the result of the new guess 1687:                                              0 0
  ------------------------------
  Turn #2. The number of possible answer is 360. AI's choice is to guess 9023
  Input a guess, press enter to take AI's choice, or input '-' to revert 1 turn:
  Input the result of the new guess 9023:                                              0 0
  ------------------------------
  Oops! It seems that there's something wrong with the input, since a number satisfying such input does not exist.
  ```

### Safe Input

Bob is careless. He once inputted `1233` as the number he guessed into the program and led the program to crash. He wants you to write a safe input mechanism to ask him to reinput if he inputs something wrong. 

```plain
------------------------------
Turn #1. The number of possible answer is 5040. AI's choice is to guess 8761
Input a guess, press enter to take AI's choice, or input '-' to revert 1 turn:       -1234
Your guess is invalid. Input again:                                                  7777
Your guess is invalid. Input again:                                                  3212
Your guess is invalid. Input again:                                                  1234
Input the result of the new guess 1234:                                              0 5
Your result is invalid. Input again:                                                 -1 2
Your result is invalid. Input again:
```

Bob is not that careless, however, and he promises that all the inputs will be integer. 

## Milestones and Grading Policy

At the end of each lab session, you are expected to complete a part of this project, called **milestone**. The requirements for each milestone will be documented in the corresponding lab worksheet. 

To finish this project, you are expected to write about 140 lines of code. This is not a big amount, but also not a small one, so we have divided it into several lab sessions. 

1. It will last for 3 lab sessions. 
2. Each milestone is worth some marks for the corresponding lab. 

Each milestone is due Friday at 23:59. For this demo project, you should submit your code on JOJ. The testcase tests every function that we implement in the lab. 

Demo projects are aimed to help you get a sense of **what a software project is like** and also hone your programming skills learnt from the lectures. The goal is not to judge your ability. So you will not need to worry about your grade as long as you try your best to follow the TAs during the lab. 

## Full Feature Demonstration

```plain
------------------------------
Turn #1. The number of possible answer is 5040. AI's choice is to guess 7146
Input a guess, press enter to take AI's choice, or input '-' to revert 1 turn:       -
Revert to last turn.
This is turn #1. Cannot revert.
------------------------------
Turn #1. The number of possible answer is 5040. AI's choice is to guess 0945
Input a guess, press enter to take AI's choice, or input '-' to revert 1 turn:       1111
Your guess is invalid. Input again:                                                  1234
Input the result of the new guess 1234:                                              2 3
Your result is invalid. Input again:                                                 2 2
------------------------------
Turn #2. The number of possible answer is 6. AI's choice is to guess 1243
Input a guess, press enter to take AI's choice, or input '-' to revert 1 turn:       -
Revert to last turn.
------------------------------
Turn #1. The number of possible answer is 5040. AI's choice is to guess 9217
Input a guess, press enter to take AI's choice, or input '-' to revert 1 turn:
Input the result of the new guess 9217:                                              4 0
------------------------------
Congratulations! You've guessed the correct number in 1 steps!

```

```plain
------------------------------
Turn #1. The number of possible answer is 5040. AI's choice is to guess 7298
Input a guess, press enter to take AI's choice, or input '-' to revert 1 turn:       1234
Input the result of the new guess 1234:                                              0 0
------------------------------
Turn #2. The number of possible answer is 360. AI's choice is to guess 6507
Input a guess, press enter to take AI's choice, or input '-' to revert 1 turn:       5678
Input the result of the new guess 5678:                                              0 0
------------------------------
Oops! It seems that there's something wrong with the input, since a number satisfying such input does not exist.

```

## Tasks

### Milestone 1

In this milestone, implement the following functions in `utils.c`:

- `getDigit`
- `isValidNum`
- `isValidRequest`
- `printNum`
- `printWithWidth`

### Milestone 2

In this milestone, implement the following functions in `Game.c`:

- `initGame`
- `judgeGuess`
- `updateGameWithLastTurn`
- `takeGuessResult`
- `revert1Turn`

### Milestone 3

In this milestone, implement the following functions in `Game.c` and `terminal.c`:

- `makeGuess`
- `beforeTurn`
- `requestNewGuess`
- `requestNewGuessResult`
- `endGame`

## Reference

Demo Project 2 Description VG101 SU 2022