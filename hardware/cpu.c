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

void loadconst(short n, reg bin){
    int i;
    for (i = 0; i < 16; i++){
        if (CHECKBIT(n,i)){
            bin[i] = 1;
        }
        else {
            bin[i] = 0;
        }
    }
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

void access(ram Mem, reg dest){
    unsigned short addr = 0;
    addr = regtoi(A);
    ramchip(Mem,NULLREG,addr,0,dest);
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

unsigned short btoi_partial(reg val, unsigned short init, unsigned short final){
    int i,b;
    unsigned short res = 0;
    for (i = final, b = 0; i >= init; i--,b++){
        res |= (val[i] << b);
    }
    return res;

}


void cpu(reg program[]){
    and16(M,NULLREG,M);
    and16(D,NULLREG,D);
    and16(A,NULLREG,A);
    while(program[regtoi(IP)]){
        reg *instruction = &program[regtoi(IP)];
        reg res;
        if (!instruction[0]){
            /* A instruction */
            load( instruction, &A);
        }
        else {
            /* C instruction */
            const int indexa = 3;
            reg one;
            loadconst(1, one);
            if (instruction[indexa]){
                switch (btoi_partial(*instruction, indexa + 1, indexa + 6)){
                    access(Mem, M);
                    case 0:
                        alu(A, M, 0, 0, 0, res, &NULLBOOL, &NULLBOOL);
                        break;
                    case 48:
                        load(&M,&res);
                        break;
                    case 49:
                        not16(M, res);
                    case 51:
                        alu(M, NULLREG, 6, 1, 0, res, &NULLBOOL, &NULLBOOL);
                        break;
                    case 55:
                        increment(M, res);
                        break;
                    case 50:
                        alu(M, one, 8, 1, 0, res, &NULLBOOL, &NULLBOOL);
                        break;
                    case 2:
                        alu(M, D, 0, 1, 0, res, &NULLBOOL, &NULLBOOL);
                        break;
                    case 19:
                        alu(M, D, 2, 1, 0, res, &NULLBOOL, &NULLBOOL);
                        break;
                    case 5:
                        alu(M, D, 8, 1, 0, res, &NULLBOOL, &NULLBOOL);
                        break;
                    case 21:
                        or16(M,D,res);
                        break;
               }
            }
           else {
               switch((int)btoi_partial){
                   case 42:
                       load(&NULLREG,&res);
                       break;
                   case 63:
                       loadconst(1, res);
                       break;
                   case 58:
                       loadconst(-1, res);
                       break;
                   case 12:
                       load(&D,&res);
                       break;
                   case 48:
                       load(&A,&res);
                       break;
                   case 13:
                       not16(D, res);
                       break;
                   case 49:
                       not16(A, res);
                       break;
                   case 15:
                       alu(D, NULLREG, 6, 1, 0, res, &NULLBOOL, &NULLBOOL);
                       break;
                   case 51:
                       alu(A, NULLREG, 6, 1, 0, res, &NULLBOOL, &NULLBOOL);
                       break;
                   case 31:
                       increment(D, res);
                       break;
                   case 55:
                       increment(A, res);
                       break;
                   case 14:
                       alu(D, one, 8, 1, 0, res, &NULLBOOL, &NULLBOOL);
                       break;
                   case 50:
                       alu(A, one, 8, 1, 0, res, &NULLBOOL, &NULLBOOL);
                       break;
                   case 2:
                       alu(A, D, 0, 1, 0, res, &NULLBOOL, &NULLBOOL);
                       break;
                   case 19:
                       alu(A, D, 2, 1, 0, res, &NULLBOOL, &NULLBOOL);
                       break;
                   case 5:
                       alu(A, D, 8, 1, 0, res, &NULLBOOL, &NULLBOOL);
                       break;
                   case 0:
                       alu(A, D, 0, 0, 0, res, &NULLBOOL, &NULLBOOL);
                       break;
                   case 21:
                       or16(A,D,res);
                       break;
               }
           }

           /* Destination instruction */
            switch(btoi_partial(*instruction, indexa + 6, indexa + 9)){
                case 0:
                    /* Value is not stored anywhere */
                    break;
                case 1:
                    load(&res, &M);
                    break;
                case 2:
                    load(&res, &D);
                    break;
                case 3:
                    load(&res, &D);
                    load(&res, &M);
                    break;
                case 4:
                    load(&res, &A);
                    break;
                case 5:
                    load(&res, &A);
                    load(&res, &M);
                    break;
                case 6:
                    load(&res, &A);
                    load(&res, &D);
                    break;
                case 7:
                    load(&res, &A);
                    load(&res, &D);
                    load(&res, &M);
                    break;
 
            }

            bool is_negative = 0;
            bool is_zero = 0;
            switch(btoi_partial(*instruction, indexa + 10, indexa + 12)){
                alu(res, NULLREG, 0, 1, 0, NULLREG, &is_zero, &is_negative);
                case 0:
                    increment(IP, IP);
                    break;
                case 1:
                    if (!is_negative && !is_zero){
                        load(&A, &IP);
                    }
                    break;
                case 2:
                    if (is_zero){
                        load(&A, &IP);
                    }
                    break;
                case 3:
                    if (!is_negative || is_zero){
                        load(&A, &IP);
                    }
                    break;
                case 4:
                    if (is_negative && !is_zero){
                        load(&A, &IP);
                    }
                    break;
                case 5:
                    if (!is_zero){
                        load(&A, &IP);
                    }
                    break;
                case 6:
                    if (is_negative || is_zero){
                        load(&A, &IP);
                    }
                    break;
                case 7:
                    load(&A, &IP);
                    break;
            }
        }
    }
}
