cmake_minimum_required(VERSION 3.30)
project(followAlong)

set(CMAKE_CXX_STANDARD 20)

add_executable(followAlong main.cpp
        Animal.cpp
        Animal.h
        Snake.cpp
        Snake.h
)
