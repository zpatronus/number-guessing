# Demo Project: Number Guessing Game - Milestone 3

## Tips

If you are confusing about the specific format, check out the full feature demonstration in the project description.

## Task 1: Implement `makeGuess`

This function accepts a pointer to a `Game` struct `game`, and returns an integer, representing the number suggested by AI. 

To lighten your workload, **we will use a unified strategy** that is to pick a random number that is still possible to be the final answer. 

Check out references for [srand()](https://en.cppreference.com/w/cpp/numeric/random/srand) and [rand()](https://en.cppreference.com/w/cpp/numeric/random/rand) to generate random numbers. 

> If you are interested in the best AI algorithm of this game, check out [this video](https://www.youtube.com/watch?v=v68zYyaEmEA) by 3Blue1Brown which might give you some inspiration. [The webpage](https://blog.zpatronus.top/2022/04/28/A-Number-Guessing-Game-Bot/) shown in the project description is an implementation of that algorithm and can guess the answer in an average of 5.3 turns. 

## Task 2: Implement `beforeTurn`

This function accepts a pointer to a `Game` struct `game` and is responsible for printing the following information onto the screen:

```plain
------------------------------
Turn #1. The number of possible answer is 5040. AI's choice is to guess 3716

```

**Notice that there's a new line at the end.**

The turn count, possible number count and AI's choice is determined by `game`.

The function returns an integer representing the number AI chooses. 

## Task 3: Implement `requestNewGuess`

The function accepts an integer `aiGuess` which is the AI's choice in this turn. 

It is responsible for printing the following information onto the screen:

```plain
Input a guess or press enter to take AI's choice; or input '-' to revert 1 turn:
```

**Notice that there are some spaces after the string, and together they have a width of 85.** 

This function handles what the user choose to guess and returns the number the user choose. 

If the user inputs some invalid numbers, the function should keep asking the user to reinput the number until it is valid. 

```plain
Your guess is invalid. Input again:
```

**Notice that there are some spaces after the string, and together they have a width of 85.** 

If the user inputs nothing but directly presses the enter, the function should take the AI's choice as user's choice. 

If the user inputs `-`, print `Revert to last turn.` with a new line at the end and return `-1` (which means that the user wants to revert 1 turn).

## Task 4: Implement `requestNewGuessResult`

The function accepts one parameter `guess` which is corresponds to the comparing result requested by this function. 

The function handles the input of the comparing result. It should print the following information onto the screen:

```plain
Input the result of the new guess 1687:
```

**Notice that there are some spaces after the string, and together they have a width of 85.** 

Bob guarantees that he will input two integers at a time. If the comparing result inputted is valid, the function should return it. If it is not, the function should print the following information and keep asking the user to reinput the comparing result until it is valid:

```plain
Your result is invalid. Input again:
```

**Notice that there are some spaces after the string, and together they have a width of 85.** 

## Task 5: Implement `endGame`

This function accepts two parameters, a pointer to a `Game` struct `game` and an `enum GameResult` `gameResult`.

The function is called when the game is end and is responsible for displaying some information.

If the Bob guessed the correct number, it should display:

```plain
------------------------------
Congratulations! You've guessed the correct number in 1 steps!

```

**Notice that there's a new line at the end.**

The turn count is determined by `game`.

If there's something wrong with the inputs and thus there does not exist a number satisfying all the inputs, it should display:

```plain
Oops! It seems that there's something wrong with the input, since a number satisfying such input does not exist.

```

**Notice that there's a new line at the end.**

## Coding strategy: separating model and view

In this demo project, we basically separate the program into 2 parts:

- The part that handles the hidden logic, such as updating the game, suggesting a guess or judging a guess. Programmers usually abstract the parts related to the hidden data and logic as **models**. 
- The part that handles interactions with users, such as printing out information and accepting user inputs. Programmers usually calls the parts related to displaying the hidden data and handling interactions as **views**. 

There are several benefits in dealing with models and views separately rather than mixing them together:

- It is easy to debug. The responsibility between each part is crystal clear and thus it is easy to locate which part of the program goes wrong. 
- It is friendly to future upgrades. If the performance of handling data is bad or the hidden logic needs to be changed, simply upgrade the model part; if the user interface needs some adjustments to catch the trend, simply upgrade the view part. 

This strategy is going to be useful in the C & C++ project you are going to complete this semester. 

If you want to learn more about software architecture, check out this wiki page about [MCV](https://en.wikipedia.org/wiki/Model–view–controller). 