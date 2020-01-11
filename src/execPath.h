void load(field f, u8 *mem, u32 *regs)
{
	switch (f.funct3) {
	case 0:  lb(f, mem, regs);	break;
	case 1:  lh(f, mem, regs);	break;
	case 2:  lw(f, mem, regs);	break;
	case 4: lbu(f, mem, regs);	break;
	case 5: lhu(f, mem, regs);	break;
	default:
	printf("funct3 not recognized for load! (%d)", f.funct3);
	}
}

void sr_R(const field f, u32 *regs)
{
	switch (f.funct7) {
	case 0x00: srl(f, regs);	break;
	case 0x20: sra(f, regs);	break;
	default: printf("funct7 not recognized! (%d)", f.funct7);
	}
}

void sr_I(const field f, u32 *regs)
{
	switch (f.funct7) {
	case 0x00: srli(f, regs);	break;
	case 0x20: srai(f, regs);	break;
	default: printf("funct7 not recognized! (%d)", f.funct7);
	}
}

void addSub(const field f, u32 *regs)
{
	switch (f.funct7) {
	case 0x00: add(f, regs);	break;
	case 0x20: sub(f, regs);	break;
	default: printf("funct7 not recognized! (%d)", f.funct7);
	}
}

void immediate(field f, u32 *regs)
{
	switch (f.funct3) {
	case 0:  addi(f, regs);	break;
	case 1:  slli(f, regs);	break;
	case 2:  slti(f, regs);	break;
	case 3: sltiu(f, regs);	break;
	case 4:  xori(f, regs);	break;
	case 5:  sr_I(f, regs);	break;
	case 6:   ori(f, regs);	break;
	case 7:  andi(f, regs);	break;
	default:
	printf("funct3 not recognized for immediate! (%d)", f.funct3);
	}
}

void store(field f, u8 *mem, u32 *regs)
{
	switch (f.funct3) {
	case 0: sb(f, mem, regs);	break;
	case 1: sh(f, mem, regs);	break;
	case 2: sw(f, mem, regs);	break;
	default:
	printf("funct3 not recognized for store! (%d)", f.funct3);
	}
	
}

void rFormat(field f, u32 *regs)
{
	switch (f.funct3) {
	case 0:  addSub(f, regs);	break;
	case 1:     sll(f, regs);	break;
	case 2:     slt(f, regs);	break;
	case 3:    sltu(f, regs);	break;
	case 4:     xOr(f, regs);	break;
	case 5:    sr_R(f, regs);	break;
	case 6:      Or(f, regs);	break;
	case 7:     And(f, regs);	break;
	default:
	printf("funct3 not recognized for r-format! (%d)", f.funct3);
	}
}

void branch(field f, u32 *regs, u32 *PC)
{
	switch (f.funct3) {
	case 0:   beq(f, regs, PC);	break;
	case 1:   bne(f, regs, PC);	break;
	case 4:   blt(f, regs, PC);	break;
	case 5:   bge(f, regs, PC);	break;
	case 6:  bltu(f, regs, PC);	break;
	case 7:  bgeu(f, regs, PC);	break;
	default:
	printf("funct3 not recognized for branch! (%d)", f.funct3);
	}
}

void e()
{
}
