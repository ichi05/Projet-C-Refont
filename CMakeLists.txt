cmake_minimum_required(VERSION 3.28)
project(Project_C_main__1_ C)

set(CMAKE_C_STANDARD 11)

include_directories(Project-C-main)

add_executable(Project_C_main__1_
        Project-C-main/Fonction.c
        Project-C-main/Fonction.h
        Project-C-main/main.c)
