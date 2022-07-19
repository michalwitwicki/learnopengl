#ifndef _GAME_H_
#define _GAME_H_

#include "window.h"
#include "renderer.h"

struct Game
{
    struct Window window;
    struct Renderer renderer;
};

void gameInit(struct Game* game);
void gameRun(struct Game* game);

#endif // _GAME_H_
