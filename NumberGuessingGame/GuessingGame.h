#pragma once


class GuessingGame {

public:
    static bool play();
private:
    static int getRandomNumber(int min, int max);
    static bool run();

    static unsigned short randomNumber;
    static unsigned short maxNumber;
};
