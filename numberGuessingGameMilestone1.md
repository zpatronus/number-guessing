# Demo Project: Number Guessing Game - Milestone 1

## Tips and Tricks

### Read the comments and make use of them.

For this demo project, we have written some fairly detailed comments in the header file. For instance, you can find the description of the `getDigit` function in the header file that declares the function, which is `utils.h`.

![image-20220826000338638](numberGuessingGameMilestone1.assets/image-20220826000338638.png)

### Hover Peek

The comments follow a certain standard used by [Doxygen](https://en.wikipedia.org/wiki/Doxygen), so with a supportive text editor or IDE, programmers can get some help while writing the code by hovering your cursor onto the name of the function. 

For instance, you are implementing the `getDigit` function and you kind of forget what the function does. To recall it, you don't have to checkout the `utils.h` header file, instead, simply hover your cursor onto the name of the function, and a window will appear. 

![image-20220826001301026](numberGuessingGameMilestone1.assets/image-20220826001301026.png)

The information in this window is exactly the same as the one in the `utils.h` header file, but with some format to improve readability. By doing the hover peek, you can get the information about:

- What does the function do?
- What do the parameters of the function represent?
- What is the return value of the function?

### Make use of pop-up windows in you text editor / IDE

Also, if you are calling the function somewhere else, in some text editor and IDE, a window will pop up, showing what the function does, and depending on how many parameters you have inputted, it highlights the next parameter (which is `digitPos` in the screenshot below) you are going to input and the description of that parameter. 

![image-20220826001630476](numberGuessingGameMilestone1.assets/image-20220826001630476-16614442232912.png)

## Task 1: Implement `getDigit`

This function accepts two parameters, a 4-digit integer `num` and an integer `digitPos` representing the position of the digit starting from the highest digit (from the left). Note that if `num` is less than 4-digit, 0 will be filled at the beginning of the number to make it a 4-digit one. 

The function returns the digit at the position of `digitPos` in the integer `num`.

For instance, 

```plain
getDigit(23,1)		returns 0
getDigit(23,2)		returns 0
getDigit(23,3)		returns 2
getDigit(23,4)		returns 3
getDigit(4321,2)	returns 3
getDigit(123,1)		returns 0
getDigit(123,4)		returns 3
```

## Task 2: Implement `isValidNum`

The function accepts one integer `num` which is the number that is going to be judged. 

To be a valid number, `num` must be a 4-digit number in which no digit is repeated. 

Note that if the number is less than 4-digit, 0 will be filled at the beginning of the number to make it a 4-digit one. 

The function returns `true` if `num` is valid and `false` if not.

For instance, 

```plain
isValidNum(-1234)	returns false
isValidNum(1123)	returns false
isValidNum(1234)	returns true
isValidNum(123)		returns true
isValidNum(12)		returns false
isValidNum(10000)	returns false
```

## Task 3: Implement `isValidResult`

The function accepts one `Result` struct `res` as parameter and returns whether `res` can be a valid comparing result. 

You can find how `Result` struct is defined by hovering your cursor on the word `Result` or by checking out its definition in `Game.h`.

For instance,

```plain
isValidResult((Result){3,1})	returns false
isValidResult((Result){2,3})	returns false
isValidResult((Result){-1,1})	returns false
isValidResult((Result){0,0})	returns true
```

## Task 4: Implement `printNum`

The function accepts one 4-digit integer `num` as parameter and prints the number into 4-digit format onto the screen. `num` is guaranteed to be a valid number. 

Note that if the number is less than 4-digit, 0 will be filled at the beginning of the number to make it a 4-digit one. 

For instance, 

```plain
printNum(1234)	prints 1234
printNum(123)	prints 0123
```

*Hint: try to use functions you have implemented.*

## Task 5: Implement `printWithWidth`

The function accepts a char array `s` and an integer `width` as parameters. 

It will first print `s` onto the screen, and if the length of `s` is less than `width`, it will print space until the width of the string printed by the function is equal to `width`.

For instance, (space will be replaced by `_` in the following example for better readability, but just use space when you are implementing the function)

```plain
printWithWidth("0123456789012345678",20)	prints:
0123456789012345678_
printWithWidth("01234567890123456",20)		prints:
01234567890123456___
printWithWidth("012345678901234567890",20)	prints:
012345678901234567890
```

