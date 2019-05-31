#include "logic.h"
#include <stdio.h>

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
int main(void){
    logic();
    return 0;
}
