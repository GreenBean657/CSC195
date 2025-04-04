cmake_minimum_required(VERSION 3.30)
project(NumberGuessingGame)

set(CMAKE_CXX_STANDARD 20)

add_executable(NumberGuessingGame main.cpp
        GuessingGame.cpp
        GuessingGame.h
        GuessingGameExecute.cpp
        GuessingGameExecute.h)
