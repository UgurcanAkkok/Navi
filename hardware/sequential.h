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
typedef reg ram[65536];
 /*if load is 1, inval (in value) is written to bit, register, or ram
  * Otherwise it doesnt write any value, in both cases output is the
  * latest value in the given memory 
  */
bool bitchip(bit * b, bool inval, bool load);
void regchip(reg * r, bool inval[16], bool load, bool out[16]);
void ramchip(ram M, bool inval[16], 
         unsigned short addr, bool load, bool out[16]);
#endif

