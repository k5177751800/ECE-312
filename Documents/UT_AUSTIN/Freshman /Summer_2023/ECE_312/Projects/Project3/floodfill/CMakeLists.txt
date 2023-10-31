cmake_minimum_required(VERSION 3.25)
project(floodfill C)

set(CMAKE_C_STANDARD 99)

add_executable(floodfill driver.c stack312_ll.c stack312_ll.h)
