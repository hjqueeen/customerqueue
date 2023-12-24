cmake_minimum_required(VERSION 3.26)
project(CustomerQueue C)

set(CMAKE_C_STANDARD 11)

add_executable(CustomerQueue main.c
        queue.h
        queue.c
        random.h
        random.c)
