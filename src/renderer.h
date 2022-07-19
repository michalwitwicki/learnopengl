#ifndef _RENDERER_H_
#define _RENDERER_H_

struct Renderer
{
    unsigned int shaderProgram;
};

void rendererInit(struct Renderer* renderer);

#endif // _RENDERER_H_