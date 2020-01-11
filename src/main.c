#include <stdio.h>
#include <string.h>
#include "structures.h"
#include "coreInstructions.h"
#include "execPath.h"
#include "loadTest.h"

#define MEM_SIZE 200
#define NUM_REGS 32

void fetch(instruction *i, const u8 *mem, u32 *PC);
void decode(instruction i, field *f);
void execute(field f, u8 *mem, u32 *regs, u32 *PC);

int main()
{
	// initialize memory, PC, and regs
	u32         PC = 0;
	u8   mem[MEM_SIZE];
	u32 regs[NUM_REGS];

	memset(mem, 0, MEM_SIZE * sizeof(u8));
	memset(regs, 0, NUM_REGS * sizeof(u32));

	// load test instruction into memory
	loadTestInstr(6, mem, regs);

	// fetch decode and execute instruction
	instruction i;
	fetch(&i, mem, &PC);
	field f;
	decode(i, &f);
	execute(f, mem, regs, &PC);

	// print all registers that are not zero
	for (int i = 0; i < 32; i++)
		if (regs[i] != 0)
			//printf("register x%d = 0x%x\n", i, regs[i]);
			printf("register x%d = %d\n", i, regs[i]);
}

void fetch(instruction *i, const u8 *mem, u32 *PC)
{
	i->byte0 = mem[(*PC)++];
	i->byte1 = mem[(*PC)++];
	i->byte2 = mem[(*PC)++];
	i->byte3 = mem[(*PC)++];
}


void decode(instruction i, field *f)
{
	// decode registers
	f->rs1     = (i.byte1 >> 7) & 1;
	f->rs1    |= ((i.byte2 << 1) & 0x1e); 
	f->rs2     = (i.byte3 & 1) << 4;
	f->rs2    |= i.byte2 >> 4;
	f->rd      = (i.byte0 >> 7) & 1;
	f->rd     |= (i.byte1 << 1) & 0x1e;

	// decode other fields
	f->shamt   = f->rs2;
	f->funct7  = i.byte3 >>  1;
	f->funct3  = (i.byte1 >> 4) & 0x7;
	f->opcode  = i.byte0 & 0x7f;

	// decode immediates
	f->imm       = (i.byte2 >> 4) & 0xf;
	f->imm      |= i.byte3 << 4;
	f->imm20     = i.byte3 << 12;
	f->imm20    |= i.byte2 <<  4;
	f->imm20    |= i.byte1 <<  4;
	f->splitImm  = i.byte3 >> 1;
	f->splitImm  = f->splitImm << 5;
	f->splitImm |= ((i.byte0 >> 7) & 1);
	f->splitImm |= ((i.byte1 << 1) & 0x1e);

	// sign extend the immediates to 32 bits
	if (f->imm >> 11 == 1)
		f->imm |= 0xfffff000;
	if (f->splitImm >> 11 == 1)
		f->splitImm |= 0xfffff000;
	if (f->imm20 >> 19 == 1)
		f->imm20 |= 0xfff00000;
}


void execute(field f, u8 *mem, u32 *regs, u32 *PC)
{
	// function definitions located in execPath.h
	switch (f.opcode) {
	case 0x03: load(f, mem, regs);	break;
	case 0x0f: fence();		break;
	case 0x13: immediate(f, regs);	break; 
	case 0x17: auipc(f, regs, PC);	break;
	case 0x23: store(f, mem, regs);	break;
	case 0x33: rFormat(f, regs);	break;
	case 0x37: lui(f, regs);	break;
	case 0x63: branch(f, regs, PC);	break;
	case 0x67: jalr(f, regs, PC);	break;
	case 0x6f: jal(f, regs, PC);	break;
	case 0x73: e();			break;
	}
}
