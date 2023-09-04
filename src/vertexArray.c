#include "vertexArray.h"

#include <gl.h>

void createVertexArray(vertexArray_t* va)
{
    glGenVertexArrays(1, &va->ID);
    glBindVertexArray(va->ID);
}

void bindVertexArray(const vertexArray_t* va)
{
    glBindVertexArray(va->ID);
}

void unbindVertexArray(void)
{
    glBindVertexArray(0);
}