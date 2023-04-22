cmake_minimum_required(VERSION 3.24)
project(SimpleTail C)

set(CMAKE_C_STANDARD 11)

add_executable(SimpleTail main.c SimpleTail.c SimpleTail.h)
