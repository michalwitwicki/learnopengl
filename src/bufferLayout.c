
#include "bufferLayout.h"

#include <gl.h>

static u32 layoutCounter = 0;

void createBufferLayout(bufferLayout_t* bl, u16 dataType, u16 valuesCount, u32 stride, u32 offset)
{
    glVertexAttribPointer(layoutCounter, valuesCount, dataType, GL_FALSE, stride, (void*)offset);
    glEnableVertexAttribArray(layoutCounter);

    bl->ID = layoutCounter;
    layoutCounter++;
}

void enableBufferLayout(const bufferLayout_t* bl)
{
    glEnableVertexAttribArray(bl->ID);
}