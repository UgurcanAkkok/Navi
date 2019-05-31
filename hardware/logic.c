#include "logic.h"

bool NAND(bool x, bool y){
    return ! (x & y);
}

bool NOT(bool x){
    return !x;
}
bool AND(bool x, bool y){
    return x&y;
}
bool OR(bool x, bool y){
    return x | y;
}
bool XOR(bool x, bool y){
    return x^y;
}
bool MUX(bool a, bool b, bool sel){
    return (sel ? b : a);
}
void DMUX(bool i, bool sel, bool * a, bool * b){
    if (!sel){
        *a = i; *b = 0;
    }
    else {
        *a = 0; *b = i;
    }
}

//Multibit version
void not16(bool * in, bool * out){
    for (int i = 0; i < 16; i++){
        out[i] = NOT(in[i]);
    }
}

void and16(bool * in1,bool * in2,  bool * out){
    for (int i = 0; i < 16; i++){
        out[i] = AND(in1[i], in2[i]);
    }
}

void or16(bool * in1,bool * in2,  bool * out){
    for (int i = 0; i < 16; i++){
        out[i] = OR(in1[i], in2[i]);
    }
}

void nand16(bool * in1,bool * in2,  bool * out){
    for (int i = 0; i < 16; i++){
        out[i] = NAND(in1[i], in2[i]);
    }
}

void mux16(bool * a, bool * b, bool sel, bool * out){
    for (int i = 0; i < 16; i++){
        out[i] = MUX(a[i], b[i], sel);
    }
}

/*
 * Multiway
 */
bool or8way(bool in[8]){
    for (int i = 0; i < 8; i++){
        if (in[i]){
            return true;
        }
    }
    return false;
}

bool mux4way16(bool in[4],bool sel[2]){
    return in[(sel[1] << 1) + sel[0]];
}
bool mux8way16(bool in[8],bool sel[3]){
    return in[(sel[1] << 1) + sel[0]];
}
void dmux4way(bool i, bool sel[2], bool out[4]){
    out[(sel[1] << 1) + sel[0]] = i;
}
void dmux8way(bool i, bool sel[2], bool out[8]){
    out[(sel[1] << 1) + sel[0]] = i;
}
