cmake_minimum_required(VERSION 3.0.0)
project(numberGuessing VERSION 0.1.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# add_compile_options(-lm -Wall -Werror -Wextra -Wpedantic -O2)
add_compile_options(-lm -Wall -Wextra -Wpedantic)

set(all_valid_files valid_Game.c valid_Game.h valid_terminal.c valid_terminal.h valid_utils.c valid_utils.h)

add_executable(numberGuessing valid_main.c ${all_valid_files})
add_executable(varify_utils_getDigit.c ${all_valid_files})

target_link_libraries(numberGuessing m)
