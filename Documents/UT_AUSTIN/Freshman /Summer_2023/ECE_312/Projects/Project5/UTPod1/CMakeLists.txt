cmake_minimum_required(VERSION 3.25)
project(UTPod)

set(CMAKE_CXX_STANDARD 20)

add_executable(UTPod UTPod.h UTPodDriver.cpp UTPod.cpp Song.cpp Song.h)
