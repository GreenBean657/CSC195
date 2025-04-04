#include "GuessingGame.h"

#include <algorithm>
#include <array>
#include  <ctime>
#include <iostream>
#include <cstdlib>

unsigned short GuessingGame::randomNumber = 0;
unsigned short GuessingGame::maxNumber = 0;


/**
 * Get a random number.
 * @param min Lower bound of the random number.
 * @param max Upper bound of the random number.
 * @return Random Number
 */
int GuessingGame::getRandomNumber(const int min, const int max) {
    srand(time(nullptr));
    return rand() % (max - min + 1) + min;
}

/**
 * Internally handle the game.
 * @return TRUE/FALSE Continue playing or not.
 */
bool GuessingGame::run() {
    int guessesLeft = 5;
    std::array<unsigned short, 6> guessArray{0,0,0,0,0,0};
    bool success = false;
    while (guessesLeft > 0) {
        std::cout << "Guess the number between 1 and " << maxNumber << std::endl;
        std::string guess;
        while (true) {
            try {
                std::cin >> guess;

                const unsigned short guessNumber = std::stoi(guess);

                if (guessNumber < 1 || guessNumber > maxNumber) {
                    std::cout << "That wasn't a valid number! Try again." << std::endl;
                    guessesLeft++;
                    continue;
                }

                if (guessNumber == randomNumber) {
                    success = true;
                    break;
                }

                bool stopDeplete = false;
                for (int i = 0; i < guessArray.size(); i++) {
                    if (guessArray[i] == guessNumber) {
                        stopDeplete = true;
                        break;
                    }
                    if (i == guessesLeft) {
                        guessArray[i] = guessNumber;
                    }
                }
                if (stopDeplete) {
                    std::cout << "You already guessed that number!" << std::endl;
                    guessesLeft++;
                } else {
                    if (guessNumber < randomNumber) {
                        std::cout << "Your guess was too low!" << std::endl;
                    } else if (guessNumber > randomNumber) {
                        std::cout << "Your guess was too high!" << std::endl;
                    }
                }
                break;
            } catch (const std::exception &exception) {
                std::cout << "That wasn't a number! Try again." << std::endl;
                guessesLeft++;
                break;
            }
        }
        if (!success) {
            guessesLeft--;
            std::cout << "You have " << guessesLeft << " guesses left." << std::endl;
        } else {
            break;
        }
    }
    if (success) {
        std::cout << "You Won! The number was " << GuessingGame::randomNumber << std::endl;
    } else {
        std::cout << "You Lost! The number was " << GuessingGame::randomNumber << std::endl;
    }

    while (true) {
        std::string playAgain;
        std::cout << "Would you like to play again? (y/n): ";
        std::cin >> playAgain;

        if (playAgain == "y" || playAgain == "Y") {
            return true;
        } else if (playAgain == "n" || playAgain == "N") {
            std::cout << "I hope you had fun!" << std::endl;
            return false;
        }
        std::cout << "Invalid input. Please enter 'y' or 'n'." << std::endl;
    }
}

/**
 * Play the game.
 * @return TRUE: player Requested to play again, FALSE: player does not want to keep playing.
 */
bool GuessingGame::play() {
    bool success = false;
    while (!success) {
        std::string difficulty;
        std::cout << "Select a difficulty (1 = easy/2 = medium/3 = hard): ";
        std::cin >> difficulty;

        if (difficulty == "1" || difficulty == "easy") {
            maxNumber = 10;
            randomNumber = getRandomNumber(1, maxNumber);
            success = true;
        } else if (difficulty == "2" || difficulty == "medium") {
            maxNumber = 50;
            randomNumber = getRandomNumber(1, maxNumber);
            success = true;
        } else if (difficulty == "3" || difficulty == "hard") {
            maxNumber = 100;
            randomNumber = getRandomNumber(1, maxNumber);
            success = true;
        } else {
            std::cout << "Invalid difficulty. Try again." << std::endl;
        }
    }
    return run();
}


