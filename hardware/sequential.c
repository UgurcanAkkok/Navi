#include "sequential.h"
#include <stdio.h>

bool bitchip(bit * b, bool inval, bool load){
    *b = MUX(*b, inval, load);
    return *b;
}

void regchip(reg * r, bool inval[16], bool load, bool out[16]){
    mux16(*r, inval, load, *r);
    mux16(*r, out, 0, out);
}

void ramchip(union ram_t ram, bool inval[16],
         unsigned short addr, bool load, bool out[16]){
    reg * r;
    if (ram.size == 8)
        r = &ram.r8[addr];
    if (ram.size == 64)
        r = &ram.r64[addr];
    if (ram.size == 512)
        r = &ram.r512[addr];
    if (ram.size == 4096)
        r = &ram.r4k[addr];
    if (ram.size == 16384)
        r = &ram.r8[addr];
    regchip(r,inval,load, out);

}






