#include "GuessingGameExecute.h"
#include "GuessingGame.h"

/**
 * Play the guessing game, and continue until the player
 * requests a game over.
 */
void GuessingGameExecute::run() {
    do {
        if (!GuessingGame::play()) {break;}
    } while (true);
}
