#ifndef SEQUENTIAL_H
#define SEQUENTIAL_H
#include "logic.h"

typedef bool bit;
typedef bit reg[16];
typedef reg ram8[8];
typedef reg ram64[64];
typedef reg ram512[512];
typedef reg ram4k[4096];
typedef reg ram16k[16384];
union ram_t {
    ram8 r8;
    ram64 r64;
    ram512 r512;
    ram4k r4k;
    ram16k r16k;
    int size;
};

bool bitchip(bit * b, bool inval, bool load);
void regchip(reg * r, bool inval[16], bool load, bool out[16]);
void ramchip(union ram_t ram, bool inval[16], 
         unsigned short addr, bool load, bool out[16]);
#endif

