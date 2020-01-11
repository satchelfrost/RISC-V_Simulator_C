void lui(const field f, u32 *regs)
{
	regs[f.rd] = f.imm20 << 12;
}

void auipc(const field f, u32 *regs, u32 *PC)
{
	regs[f.rd] = *PC + (f.imm20 << 12);
}

void jal(const field f, u32 *regs, u32 *PC)
{
	regs[f.rd] = *PC + 4; 
	*PC = (int) *PC + (int) f.imm20;
}

void jalr(const field f, u32 *regs, u32 *PC)
{
	regs[f.rd] = *PC + 4; 
	*PC = (int) regs[f.rs1] + (int) f.imm;
	*PC = *PC & 0xfffffffe;
}

void beq(const field f, u32 *regs, u32 *PC)
{
	if (regs[f.rs1] == regs[f.rs2])
		*PC = (int) *PC + (int) f.splitImm;
}

void bne(const field f, u32 *regs, u32 *PC)
{
	if (regs[f.rs1] != regs[f.rs2])
		*PC = (int) *PC + (int) f.splitImm;
}

void blt(const field f, u32 *regs, u32 *PC)
{
	if ((int) regs[f.rs1] < (int) regs[f.rs2])
		*PC = (int) *PC + (int) f.splitImm;
}

void bge(const field f, u32 *regs, u32 *PC)
{
	if ((int) regs[f.rs1] >= (int) regs[f.rs2])
		*PC = (int) *PC + (int) f.splitImm;
}

void bltu(const field f, u32 *regs, u32 *PC)
{
	if (regs[f.rs1] < regs[f.rs2])
		*PC = (int) *PC + (int) f.splitImm;
}

void bgeu(const field f, u32 *regs, u32 *PC)
{
	if (regs[f.rs1] >= regs[f.rs2])
		*PC = (int) *PC + (int) f.splitImm;
}

void lb(const field f, u8 *mem, u32 *regs)
{
	regs[f.rd] = (int)(signed char) mem[f.imm + regs[f.rs1]];
}

void lh(const field f, u8 *mem, u32 *regs)
{
	u8 msb     = mem[regs[f.rs1] + f.imm + 1];
	u8 lsb     = mem[regs[f.rs1] + f.imm + 0];
	u16 half   = msb << 8;
	half      |= lsb << 0;
	regs[f.rd] = (int)(signed short) half; 
}

void lw(const field f, u8 *mem, u32 *regs)
{
	u8 msb     = mem[regs[f.rs1] + f.imm + 3];
	u8 secMsb  = mem[regs[f.rs1] + f.imm + 2];
	u8 secLsb  = mem[regs[f.rs1] + f.imm + 1];
	u8 lsb     = mem[regs[f.rs1] + f.imm + 0];
	u32 word   = msb     << 24;
	word      |= secMsb  << 16;
	word      |= secLsb  <<  8;
	word      |= lsb     <<  0;
	regs[f.rd] = word; 
}

void lbu(const field f, u8 *mem, u32 *regs)
{
	regs[f.rd] = mem[f.imm + regs[f.rs1]];
}

void lhu(const field f, u8 *mem, u32 *regs)
{
	u8 msb     = mem[regs[f.rs1] + f.imm + 1];
	u8 lsb     = mem[regs[f.rs1] + f.imm + 0];
	u16 half   = msb << 8;
	half      |= lsb << 0;
	regs[f.rd] = half; 
}

void sb(const field f, u8 *mem, u32 *regs)
{
	mem[f.splitImm + regs[f.rs1]] = regs[f.rs2];
}

void sh(const field f, u8 *mem, u32 *regs)
{
	u16 half = regs[f.rs2];
	u8 msb = half << 8;
	u8 lsb = half << 0;
	
	mem[f.splitImm + regs[f.rs1] + 1] = msb; 
	mem[f.splitImm + regs[f.rs1] + 0] = lsb; 
}

void sw(const field f, u8 *mem, u32 *regs)
{
	u32 word  = regs[f.rs2];
	u8 msb    = (word >> 24) & 0xff;
	u8 secMsb = (word >> 16) & 0xff;
	u8 secLsb = (word >>  8) & 0xff;
	u8 lsb    = (word >>  0) & 0xff;
	
	mem[f.splitImm + regs[f.rs1] + 3] = msb; 
	mem[f.splitImm + regs[f.rs1] + 2] = secMsb; 
	mem[f.splitImm + regs[f.rs1] + 1] = secLsb; 
	mem[f.splitImm + regs[f.rs1] + 0] = lsb; 
}

void addi(const field f, u32 *regs)
{
	regs[f.rd] = regs[f.rs1] + f.imm;
}

void slti(const field f, u32 *regs)
{
	regs[f.rd] = ((int) regs[f.rs1] < (int) f.imm) ? 1 : 0;
}

void sltiu(const field f, u32 *regs)
{
	regs[f.rd] = (regs[f.rs1] < f.imm) ? 1 : 0;
}

void xori(const field f, u32 *regs)
{
	regs[f.rd] = regs[f.rs1] ^ f.imm;
}

void ori(const field f, u32 *regs)
{
	regs[f.rd] = regs[f.rs1] | f.imm;
}

void andi(const field f, u32 *regs)
{
	regs[f.rd] = regs[f.rs1] & f.imm;
}

void slli(const field f, u32 *regs)
{
	regs[f.rd] = regs[f.rs1] << f.imm;
}

void srli(const field f, u32 *regs)
{
	regs[f.rd] = regs[f.rs1] << f.imm;
}

void srai(const field f, u32 *regs)
{
	regs[f.rd] = (int) regs[f.rs1] >> f.imm;
}

void add(const field f, u32 *regs)
{
	regs[f.rd] = (int) regs[f.rs1] + (int) regs[f.rs2];
}

void sub(const field f, u32 *regs)
{
	regs[f.rd] = (int) regs[f.rs1] - (int) regs[f.rs2];
}

void sll(const field f, u32 *regs)
{
	regs[f.rd] = regs[f.rs1] << regs[f.rs2];
}

void slt(const field f, u32 *regs)
{
	regs[f.rd] = ((int) regs[f.rs1] < (int) regs[f.rs2]) ? 1 : 0;
}

void sltu(const field f, u32 *regs)
{
	regs[f.rd] = (regs[f.rs1] < regs[f.rs2]) ? 1 : 0;
}

void xOr(const field f, u32 *regs)
{
	regs[f.rd] = regs[f.rs1] ^ regs[f.rs2];
}

void srl(const field f, u32 *regs)
{
	regs[f.rd] = regs[f.rs1] >> regs[f.rs2];
}

void sra(const field f, u32 *regs)
{
	regs[f.rd] = (int) regs[f.rs1] >> regs[f.rs2];
}

void Or(const field f, u32 *regs)
{
	regs[f.rd] = regs[f.rs1] | regs[f.rs2];
}

void And(const field f, u32 *regs)
{
	regs[f.rd] = regs[f.rs1] & regs[f.rs2];
}

void fence()
{
}
