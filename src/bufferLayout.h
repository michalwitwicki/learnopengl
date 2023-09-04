#ifndef _BUFFER_LAYOUT_H_
#define _BUFFER_LAYOUT_H_

#include "types.h"

#define PACKED __attribute__((__packed__))

typedef struct bufferLayout_s
{
    u32 ID;
} bufferLayout_t;

void createBufferLayout(bufferLayout_t* bl, u16 dataType, u16 valuesCount, u32 stride, u32 offset);
void enableBufferLayout(const bufferLayout_t* bl);

#endif // _BUFFER_LAYOUT_H_