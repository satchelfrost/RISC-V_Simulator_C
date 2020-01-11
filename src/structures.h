typedef unsigned char   u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct instruction
{
	u8 byte0;
	u8 byte1;
	u8 byte2;
	u8 byte3;
} typedef instruction;

struct field
{
	u32      rs1;
	u32      rs2;
	u32       rd;
	u32   opcode;
	u32   funct3;
	u32   funct7;
	u32      imm;
	u32 splitImm;
	u32    imm20;
	u32    shamt;
} typedef field;
