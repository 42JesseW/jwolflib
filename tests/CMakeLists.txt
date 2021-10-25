cmake_minimum_required(VERSION 3.10.2)
project(libft C)

set(CMAKE_C_STANDARD 99)
set(LIBFT libft.a)
set(LIBFT_DIR ${PROJECT_SOURCE_DIR}/..)

add_custom_target(
    ${LIBFT} ALL
    COMMAND make
    WORKING_DIRECTORY ${LIBFT_DIR}
)

link_directories(..)
link_libraries(ft criterion)

file(GLOB_RECURSE SRCS *.c)

add_executable(tests ${SRCS})

add_dependencies(tests ${LIBFT})

target_link_libraries(tests criterion ft)