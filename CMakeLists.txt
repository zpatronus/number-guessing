cmake_minimum_required(VERSION 3.0.0)
project(numberGuessing VERSION 0.1.0)

# add_compile_options(-Wall -Werror -Wextra -Wpedantic)
add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(numberGuessing main.c Game.c Game.h utils.c utils.h)
