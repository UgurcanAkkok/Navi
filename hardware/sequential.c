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

void ramchip(ram M, bool inval[16],
         unsigned short addr, bool load, bool out[16]){
    reg * r = &M[addr];
    regchip(r,inval,load, out);

}






