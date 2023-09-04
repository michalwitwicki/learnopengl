#ifndef _BUFFER_H_
#define _BUFFER_H_

#include "types.h"

#define PACKED __attribute__((__packed__))

typedef struct buffer_s
{
    u32 ID;
    u16 type;
} buffer_t;

void createBuffer(buffer_t* buffer, u16 type, const void* data, u32 size);
void deleteBuffer(const buffer_t* buffer);
void bindBuffer(const buffer_t* buffer);
void unbindBuffer(const buffer_t* buffer);

#endif // _BUFFER_H_