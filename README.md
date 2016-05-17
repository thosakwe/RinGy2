# RinGy 2.0
A C++ VM for a re-thought [RinGy](https://esolangs.org/wiki/RinGy).

# Stack
Rin

# New Opcodes
To make this an actually usable VM, I added the following opcodes:

| Command    | Description 
| ---------- | ----------  
| [          | Push the value of the current memory cell to the stack.
| ]          | Pop the last stack value into the current memory cell.
| ~          | Jump to the offset pointed to by the memory pointer. Places the prior offset into the current memory cell.
| #          | Store the value of the memory pointer into the current cell.
| $          | Compare the top two stack values, and puts 0 or 1 into the current cell, depending on if they are equal.
| (          | Jump to the offset in the last stack value, only if current cell == 0.
| )          | Same as above, but only if cell != 0.
| ^          | Read a single char from stdin, place it into the current cell, and increment memory pointer.

'c' may be any character, and 'n' may be any integer.

*Go bananas*. Currently planning an assembler for this.
