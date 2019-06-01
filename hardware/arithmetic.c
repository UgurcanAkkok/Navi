#include "./arithmetic.h"

void halfAdder(bool a, bool b, bool * s, bool * c){
    *s = XOR(a,b);
    *c = AND(a,b);
}
void fullAdder(bool a, bool b,bool ci, bool * s, bool * co){
    *s = XOR(ci, XOR(a,b));
    *co = OR(AND(a,b),AND(XOR(a,b),ci));
}
void adder(bool a[16], bool b[16], bool out[16]){
    bool c;
    int i;
    halfAdder(a[15], b[15], &out[15], &c);
    for (i = 14; i >= 0; i--){
        fullAdder(a[i], b[i], c, &out[i], &c);
    }
}
void increment(bool a[16], bool out[16]){
    bool b[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
    adder(a, b, out);

}

void alu(bool x[16], bool y[16], unsigned short option, 
        bool funcCode, bool no, bool out[16], bool * zr, bool * ng){
    int i;
    if (CHECKBIT(option, 0)){
        for (i = 0; i < 16; i++){ x[i] = 0; }
    }
    if (CHECKBIT(option, 1)){
        for (i = 0; i < 16; i++){ x[i] = !x[i]; }
    }
    if (CHECKBIT(option, 2)){
        for (i = 0; i < 16; i++){ y[i] = 0; }
    }
    if (CHECKBIT(option, 3)){
        for (i = 0; i < 16; i++){ y[i] = !y[i]; }
    }
    if (funcCode){
        adder(x,y,out);
    }
    if(!funcCode){
        and16(x,y,out);
    }
    if(no){
        not16(out,out);
    }
    *zr = 1;
    for(i = 0; i < 16; i++){
        if (out[i] == 1) *zr = 0;
    }
    *ng = out[15];
    return;
}
