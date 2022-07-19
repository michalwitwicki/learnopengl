// #include <gl.h>
// #define GLFW_INCLUDE_NONE
// #include <glfw3.h>

// #include <stdlib.h>
// #include <math.h>

// #include "window.h"
#include "game.h"

int main()
{
    struct Game game;
    gameInit(&game);
    gameRun(&game);

    return 0;
}