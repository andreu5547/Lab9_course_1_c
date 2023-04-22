cmake_minimum_required(VERSION 3.24)
project(printRandomString2File C)

set(CMAKE_C_STANDARD 11)

add_executable(printRandomString2File main.c RandomString2File.c RandomString2File.h)
