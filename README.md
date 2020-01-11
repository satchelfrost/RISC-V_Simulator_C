# RISC-V_Simulator

This project aims to create a RISC-V instruction set simulator (ISS).

### RV32I As described in the specification:

"Although it is convenient to speak of the RISC-V ISA, RISC-V is actually a family of related ISAs, of which there are currently four base ISAs. Each base integer instruction set is characterized by the width of the integer registers and the corresponding size of the address space and by the number of integer registers. There are two primary base integer variants, RV32I and RV64I ..."

Currently I'm only interested in implementing RV32I (without ecall, ebreak, or fence). Eventually I may look into adding these along with extensions later (such as multiplication, division, floating point numbers etc.)
