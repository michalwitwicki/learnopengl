#include "game.h"

int main()
{
    struct Game game;
    gameInit(&game);
    gameRun(&game);

    return 0;
}