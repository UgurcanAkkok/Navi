#include "logic.h"
#include "arithmetic.h"
#include <stdio.h>
#include <string.h>

int btoi(bool a[16]);
void printBin(bool bin[16]);
void logic(){
    bool res, a, b, i, sel;
    for (a = 0; a < 2; a++){
        for (b = 0; b < 2; b++){
            for (i = 0; i < 2; i++){
                for (sel = 0; sel < 2; sel++){
                    printf("a is %d \nb is %d\n", a, b);
                    res = AND(a,b);
                    printf("a and b = %d\n", res);
                    res = NOT(a);
                    printf("not a = %d\n", res);
                    res = OR(a,b);
                    printf("a or b = %d\n", res);
                    res = NAND(a,b);
                    printf("a nand b = %d\n", res);
                    res = XOR(a,b);
                    printf("a xor b = %d\n", res);
                    
                    res = MUX(a,b,sel);
                    printf("a mux b (sel %d)  = %d\n", sel, res);
                    bool a_cp = a;
                    bool b_cp = b;
                    DMUX(i, sel, &a_cp, &b_cp);
                    printf("DMUX with i is %d, sel is %d \ta turns to %d\tb turns to %d\n", i, sel, a_cp, b_cp);
                }
            }
        }
    }

    return;
}

void arithmetic(){
    bool sum, carry, a, b, c;
    for (a = 0; a < 2; a++){
        for (b = 0; b < 2; b++){
            halfAdder(a, b, &sum, &carry);
            printf("a = %d, b = %d, a HA b = %d%d\n", a, b, carry, sum);
            for (c = 0; c < 2; c++){
                fullAdder(a, b, c, &sum, &carry);
                printf("a = %d, b = %d, carryin = %d,\
                        a FA b with carryin  = %d%d\n",
                        a, b, c, carry, sum);
            }
        }
    }
    bool a16[16] = {0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1};
    printf("a is ");
    printBin(a16);
    printf("\n");

    bool b16[16] = {0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1};
    printf("b is ");
    printBin(b16);
    printf("\n");

    bool out[16] = {0};
    adder(a16, b16, out);
    printf("a + b is ");
    printBin(out);
    printf("\n");

    increment(a16,out);
    printf("a + 1 is ");
    printBin(out);
    printf("\n");
    
    printf("=============ALU==========\n");
    bool x[16] = {0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1};
    bool x_def[16] = {0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1};
    printf("x is ");
    printBin(x);
    printf("\n");

    bool y[16] = {0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1};
    bool y_def[16] = {0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1};
    printf("y is ");
    printBin(y);
    printf("\n");

    bool zr;
    bool ng;
    unsigned short opt;
    int funcCode;
    int no;
    for(opt = 0; opt < 16; opt++){
        for (funcCode = 0; funcCode < 2; funcCode++){
            for (no = 0; no < 2; no++){
                alu(x,y,opt,funcCode,no,out,&zr,&ng);
                printf("-------\n");
                printf("x is ");
                printBin(x);
                printf("\t%d",btoi(x));
                printf("\n");
                printf("y is ");
                printBin(y);
                printf("\t%d",btoi(y));
                printf("\n");
                printf("Option is %u\n", opt);
                if (no) printf("Negate output is true\n");
                if(zr) printf("Output is zero\n");
                if(ng) printf("Output is negative\n");
                if(funcCode) printf("X + Y = ");
                else printf("X & Y = ");
                printBin(out);
                printf("\t%d",btoi(out));
                printf("\n");
                if(funcCode){
                    if (btoi(out) == btoi(x) + btoi(y))
                        printf("CORRECT\n");
                }
                else {
                    if (btoi(out) == (btoi(x) & btoi(y)))
                        printf("CORRECT\n");
                }

                memcpy(x, x_def, sizeof(x_def));
                memcpy(y, y_def, sizeof(y_def));
                printf("-------\n");
            }
        }
    }
}




int main(void){
    /*logic();*/
    arithmetic();
    /*bool a[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0};
    printf("%d", btoi(a));*/
    return 0;
}

void printBin(bool *a){
    int i;
    for (i = 0; i < 16; i++){
        printf("%d", a[i]);
    }
}
int btoi(bool a[16]){
    int result = 0;
    int i,j = 0;
    for (i = 15; i > 0; i--){
        result += a[i] * ( 1 << j);
        j++;
    }
    if(a[0] == 1)
        result -= -1 + (1 << 15);

    return result;
}

