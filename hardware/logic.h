#ifndef LOGIC_H
#define LOGIC_H

typedef enum {false = 0, true } bool;

bool NAND(bool x, bool y);
bool NOT(bool x);
bool AND(bool x, bool y);
bool OR(bool x, bool y);
bool XOR(bool x, bool y);
bool MUX(bool a, bool b, bool sel);
void DMUX(bool i, bool sel, bool * a, bool * b);


/* Multi-bit versions
 * Parameters are the same as above, except most are arrays and
 * there is out parameter as we can not return arrays, output will
 * be saved there */
void not16(bool*, bool*);
void and16(bool*, bool*, bool*);
void or16(bool*, bool*, bool*);
void nand16(bool*, bool*, bool*); 
void xor16(bool*, bool*, bool*);
void mux16(bool*, bool*, bool, bool*);

/*
 * Multi-way versions
 *
 */
bool or8way(bool [8]);
bool mux4way16(bool [4],bool sel[2]);
bool mux8way16(bool [8],bool sel[3]);
void dmux4way(bool i, bool sel[2], bool out[4]);
void dmux8way(bool i, bool sel[2], bool out[8]);

#endif
