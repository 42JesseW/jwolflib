cmake_minimum_required(VERSION 3.10.2)
project(libft C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra")
set(HEADERS includes)

include_directories(${HEADERS})
file(GLOB_RECURSE SRCS printf/*.c printf/**/*.c get_next_line/*.c srcs/*.c)

add_library(libft ${SRCS})
target_include_directories(libft PUBLIC ${HEADERS})

add_subdirectory(tests)
