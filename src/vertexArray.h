#ifndef _VERTEX_ARRAY_H_
#define _VERTEX_ARRAY_H_

#include "types.h"

#define PACKED __attribute__((__packed__))

typedef struct vertexArray_s
{
    u32 ID;
} vertexArray_t;

void createVertexArray(vertexArray_t* va);
void bindVertexArray(const vertexArray_t* va);
void unbindVertexArray(void);

#endif // _VERTEX_ARRAY_H_