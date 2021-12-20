cmake_minimum_required(VERSION 3.21)
project(2021_12_19 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(2021_12_19
        main.c
        utils.c
        utils.h)
