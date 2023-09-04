#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include "types.h"

#define PACKED __attribute__((__packed__))

typedef struct texture_s
{
    u32 ID;
} texture_t;

void createTexture(texture_t* t, const char* filename);

#endif // _TEXTURE_H_