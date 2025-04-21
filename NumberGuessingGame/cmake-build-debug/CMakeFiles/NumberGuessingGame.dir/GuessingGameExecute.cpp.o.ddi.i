# 0 "/home/GreenBean/CLionProjects/CSC195/NumberGuessingGame/GuessingGameExecute.cpp"
# 1 "/home/GreenBean/CLionProjects/CSC195/NumberGuessingGame/cmake-build-debug//"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "/home/GreenBean/CLionProjects/CSC195/NumberGuessingGame/GuessingGameExecute.cpp"
# 1 "/home/GreenBean/CLionProjects/CSC195/NumberGuessingGame/GuessingGameExecute.h" 1
       


class GuessingGameExecute {
public:
    void static run();
};
# 2 "/home/GreenBean/CLionProjects/CSC195/NumberGuessingGame/GuessingGameExecute.cpp" 2
# 1 "/home/GreenBean/CLionProjects/CSC195/NumberGuessingGame/GuessingGame.h" 1
       


class GuessingGame {

public:
    static bool play();
private:
    static int getRandomNumber(int min, int max);
    static bool run();

    static unsigned short randomNumber;
    static unsigned short maxNumber;
};
# 3 "/home/GreenBean/CLionProjects/CSC195/NumberGuessingGame/GuessingGameExecute.cpp" 2





void GuessingGameExecute::run() {
    do {
        if (!GuessingGame::play()) {break;}
    } while (true);
}
