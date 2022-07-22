#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "shaders.h"
struct Renderer
{
    struct Shaders shaders;
};

void rendererInit(struct Renderer* renderer);

#endif // _RENDERER_H_