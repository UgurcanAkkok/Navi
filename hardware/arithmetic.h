#ifndef ARITHMETIC_H
#define ARITHMETIC_H
#include "./logic.h"
#define CHECKBIT(val,pos) ((val & (1 << (pos))) != 0)

void halfAdder(bool a, bool b, bool * s, bool * c);
void fullAdder(bool a, bool b,bool ci, bool * s, bool * co);
void adder(bool a[16], bool b[16], bool out[16]);
void increment(bool a[16], bool out[16]);
void alu(bool x[16], bool y[16], unsigned short option, 
        bool funcCode, bool no, bool out[16], bool * zr, bool *ng);
/* 
 Option : 0001 -> x = 0
          0010 -> x = -x
          0100 -> y = 0
          1000 -> y = -y

 funcCode : if false, operate and
           if true   operate add
 no :  negate output
*/

#endif
