#include "Game.h"

int main() {
    bool rungame = true;
    while(rungame) {
        Game game;
        rungame = game.run();
    }
    return 0;
}