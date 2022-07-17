#ifndef _GAME_H_
#define _GAME_H_

#include "window.h"
#include "shader.h"
#include "renderer.h"

struct Game
{
    struct Window window;
    // struct Renderer renderer;
};

void initGame(struct Game* game);

#endif // _GAME_H_
