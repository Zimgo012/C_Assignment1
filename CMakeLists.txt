cmake_minimum_required(VERSION 3.29)
project(C_Assignment1 C)

set(CMAKE_C_STANDARD 99)

add_executable(C_Assignment1 main.c
        printMap.h
        printMap.c
        checkEOF.c
        checkEOF.h
)
