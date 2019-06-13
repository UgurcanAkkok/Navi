#include "cpu.h"

short regtoi(reg bin){
    unsigned char i;
    short result = 0;
    for (i = 0; i < 16; i++){
        if (bin[i] == 1){
            result |= (1 << i);
        }
    }
    return result;

}

void load(reg * source, reg * dest){
    regchip(dest, *source,1,NULLREG);
}

void write(bool data[16], reg * dest){
    /*int i;
    for (i = 15; i >= 0; i--){
        if (data & (1 << (15 - i))){
            binary[i] = 1;
        }
    }*/
    regchip(dest,data,1,NULLREG);
}

void access(reg index, union ram_t ram, reg dest){
    unsigned short addr = 0;
    addr = regtoi(index);
    ramchip(ram,NULLREG,addr,0,dest);
}

void add(reg a, reg b, reg res){
    alu(a, b, 0, 1, 0, res, &NULLBOOL, &NULLBOOL);
}

void bitnegate(reg source, reg dest){
    not16(source,dest);
}

void bitshift(reg shiftrate, reg source, reg dest){
    short shift = regtoi(shiftrate);
    int i;
    for (i = 15; i >= 0; i--){
        if (i + shift < 16 || i + shift >= 0)
        dest[i + shift] = source[i];
    }
}

void substract(reg a, reg b, reg res){
    alu(a, b, 8, 1, 0, res, &NULLBOOL, &NULLBOOL);
}

void cpu(reg instruction, reg data, bool setzero){
    if (instruction[0] == 0){
        /* A instruction, sets 
