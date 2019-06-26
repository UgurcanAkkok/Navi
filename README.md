# Navi

This projects is inspired by Nand2tetris, creates an entire computer system with using ANSI C. From the very bottom, logic gates, to operating system, some programs and games.

This project doesnot entirely follows Nand2Tetris, rather it creates it's own environment with the guide of _Elements of Computing System_ book. 

The main reason why i do such a project is to learn C, gain knowledge in the mechanics of computing. 

And finally, any contribution and guidance is indeed welcome.

## Documentation

### Hardware
1. Logic

Includes _logic.c_ and _logic.h_. Capitalized functions are the basic logic gates. Others are created with using them. If a function returns void, it is most probably saves the output to given last parameters. The reason is there is more than one value or array that must be returned. The Navi will be 16 bit computer, that is why multi bit functions assumes 16 length array. _bool_ type emulates bool type from C99/C++. 

2. Arithmetic

Full Adder and Half Adder is implemented like a logic circuit. 
Adder first uses halfadder for right most bit, then full adder for others, with possible carry bit.
Increment function adds 1 to given binary number and saves the output to second parameter.
ALU takes 2 main input, and 3 option parameter, and 3 output parameter. See _arithmetic.h_ for details. And outputs out,zr,ng to parameters. zr is true if output is zero. ng is true if output is negative. 

3. Sequential

Includes _sequential.c_ and _sequential.h_. Defines register and ram. Ram is arbitrary sized array of reg (register). _regchip_ function controls registers, like an interface.It can read or write to given registers.
_ramchip_ pretty much does the same thing, it uses the register at the given address and calls regchip with that.

4. CPU

Declares  A, D, M, IP registers and a RAM. 
A will be mostly used for storing addresses and sometimes values.
D will be used for holding values only.
M is the pointed memory location, a register, in the ram.
IP is the instruction pointer, points to the next instruction.
Mem is the ram, when accessing ram, A register's value is used as the address.
_loadconst_ is for writing a constant value to a register.
_regtoi_ translates a register's value to integer.
_load_ writes the information in one register to other.
_access_ reads the value at the ram, writes it to the register given in second parameter.
_bitshift_ shifts the bits in the register.
_cpu_ is the main function of this file, it handles all the instructions. For more detail, go to source and see comments.
### Software

___Not implemented___
