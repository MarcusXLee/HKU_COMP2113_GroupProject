#include <ctime>
#include <cstdlib>
#include "GameManager.h"

int main() {
    srand(time(NULL));//Initialize random seed
    GameManager game;
    game.start();
    return 0;
}