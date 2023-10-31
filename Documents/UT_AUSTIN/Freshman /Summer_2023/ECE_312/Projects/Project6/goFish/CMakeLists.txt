cmake_minimum_required(VERSION 3.25)
project(goFish)

set(CMAKE_CXX_STANDARD 23)

add_executable(goFish card_demo.cpp deck.cpp player.cpp card.cpp card.h deck.h player.h go_fish.cpp)
