#include "buffer.h"

#include <gl.h>

void createBuffer(buffer_t* buffer, u16 type, const void* data, u32 size)
{
    glGenBuffers(1, &buffer->ID);
    glBindBuffer(type, buffer->ID);
    glBufferData(type, size, data, GL_STATIC_DRAW);

    buffer->type = type;
}

void deleteBuffer(const buffer_t* buffer)
{
    glDeleteBuffers(1, &buffer->ID);
}

void bindBuffer(const buffer_t* buffer)
{
    glBindBuffer(buffer->type, buffer->ID);
}

void unbindBuffer(const buffer_t* buffer)
{
    glBindBuffer(buffer->type, 0);
}