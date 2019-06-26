#include "arithmetic.h"
#include "sequential.h"

#ifndef CPU_H
#define CPU_H

reg NULLREG;
bool NULLBOOL;
reg A; /* A register can hold both addr and val */
reg D; /* D register can hold only value */
ram Mem; /* Memory register */
reg M;
reg IP; /* Instruction Pointer */

void loadconst(short n, reg bin);
short regtoi(reg bin);
void load(reg * source, reg * dest);
void write(reg data, reg * dest);
void access(ram M, reg dest);
void bitshift(reg shiftrate, reg source, reg dest);
void substract(reg a, reg b, reg res);
void cpu(reg instruction[]);
unsigned short btoi_partial(reg val, unsigned short init, unsigned short final);

#endif
