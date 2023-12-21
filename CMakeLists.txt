cmake_minimum_required(VERSION 3.27)
project(Matrixmulti C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ansi -Wall -Wextra -Wpedantic -Werror  -fopenmp" )

add_executable(Matrixmulti main.c)
