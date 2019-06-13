/* There will be read, write, acces functions, 
 * read will load the data in one part of the memory to another
 * write will write a constant to one part of the memory
 * access will access a memory part with a address in other register, e.g. Mem[R1]
 */
#include "arithmetic.h"
#include "sequential.h"

#ifndef CPU_H
#define CPU_H

reg NULLREG;
bool NULLBOOL;

short regtoi(reg bin);
void load(reg * source, reg * dest);
void write(reg data, reg * dest);
void access(reg index, union ram_t ram, reg dest);
void add(reg a, reg b, reg res);
void bitnegate(reg source, reg dest);
void bitshift(reg shiftrate, reg source, reg dest);
void substract(reg a, reg b, reg res);
void cpu(reg instruction, reg data, bool setzero);

#endif
