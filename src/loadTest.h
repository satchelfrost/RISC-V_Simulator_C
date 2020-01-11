void loadTestInstr(int test, u8 *mem, u32 *regs)
{
	switch (test) {
	case 0:
		// lb x5, 13(x3)
		mem[0]  = 0x83; // 0b10000011;
		mem[1]  = 0x82; // 0b10000010;
		mem[2]  = 0xd1; // 0b11010001;
		mem[3]  = 0x00; // 0b00000000;
		regs[3] =    9;
		mem[22] = -125;
		break;
	case 1:
		// lh x5, 13(x3)
		mem[0]  = 0x83; // 0b10000011;
		mem[1]  = 0x92; // 0b10010010;
		mem[2]  = 0xd1; // 0b11010001;
		mem[3]  = 0x0 ; // 0b00000000;
		regs[3] =    9;
		mem[22] =   42;   
		mem[23] = -124;
		break;
	case 2:
		// lw x5, 13(x3)
		mem[0]  = 0x83; // 0b10000011;
		mem[1]  = 0xa2; // 0b10100010;
		mem[2]  = 0xd1; // 0b11010001;
		mem[3]  = 0x0 ; // 0b00000000;
		regs[3] =    9;
		mem[22] =         42;
		mem[23] =         43;
		mem[24] =         44;
		mem[25] =       -123;
		break;
	case 3:
		// lb x5, 13(x3)
		mem[0]  = 0x83; // 0b10000011;
		mem[1]  = 0xc2; // 0b11000010;
		mem[2]  = 0xd1; // 0b11010001;
		mem[3]  = 0x0 ; // 0b00000000;
		regs[3]    =          9;
		mem[22] =       -125;
		break;
	case 4:
		// lh x5, 13(x3)
		mem[0]  = 0x83; // 0b10000011;
		mem[1]  = 0xd2; // 0b11010010;
		mem[2]  = 0xd1; // 0b11010001;
		mem[3]  = 0x0 ; // 0b00000000;
		regs[3]    =          9;
		mem[22] =         42;
		mem[23] =       -124;
		break;
	case 5:
		// lw x5, 13(x3)
		mem[0]  = 0x83; // 0b10000011;
		mem[1]  = 0xe2; // 0b11100010;
		mem[2]  = 0xd1; // 0b11010001;
		mem[3]  = 0x0 ; // 0b00000000;
		regs[3]    =          9;
		mem[22] =         42;
		mem[23] =         43;
		mem[24] =         44;
		mem[25] =       -123;
		break;
	case 6:
		// sb x5, 173(x3)
		mem[0]  = 0xa3; // 0b10100011;
		mem[1]  = 0x86; // 0b10000110;
		mem[2]  = 0x51; // 0b01010001;
		mem[3]  = 0xa ; // 0b00001010;
		regs[3]     =          9;
		regs[5]     =       1234;
		mem[182] =         -1;
		break;
	case 7:
		// sh x5, 173(x3)
		mem[0]  = 0xa3; // 0b10100011;
		mem[1]  = 0x96; // 0b10010110;
		mem[2]  = 0x51; // 0b01010001;
		mem[3]  = 0xa ; // 0b00001010;
		regs[3]     =          9;
		regs[5]     =       1234;
		mem[182] =         -1;
		mem[183] =         -2;
		break;
	case 8:
		// sw x5, 173(x3)
		mem[0]   = 0xa3; // 0b10100011;
		mem[1]   = 0xa6; // 0b10100110;
		mem[2]   = 0x51; // 0b01010001;
		mem[3]   = 0xa ; // 0b00001010;
		regs[3]     =          9;
		regs[5]     =       1234;
		mem[182] =         -1;
		mem[183] =         -2;
		mem[184] =         -3;
		mem[185] =         -4;
		break;
	case 9: 
		// addi x5, x3, 13
		mem[0]  = 0x93; // 0b10010011;
		mem[1]  = 0x82; // 0b10000010;
		mem[2]  = 0xd1; // 0b11010001;
		mem[3]  = 0x0 ; // 0b00000000;
		regs[3]    =          9;
		break;
	case 10:
		// stli x5, x3, 13
		mem[0]  = 0x93; // 0b10010011;
		mem[1]  = 0xa2; // 0b10100010;
		mem[2]  = 0xd1; // 0b11010001;
		mem[3]  = 0x0 ; // 0b00000000;
		regs[3]    =        -13;
		break;
	case 11:
		// stliu x5, x3, 13
		mem[0] = 0x93; // 0b10010011;
		mem[1] = 0xb2; // 0b10110010;
		mem[2] = 0xd1; // 0b11010001;
		mem[3] = 0x0 ; // 0b00000000;
		regs[3]    =        -13;
		break;
	case 12:
		// xori x5, x3, 13
		mem[0] = 0x93; // 0b10010011;
		mem[1] = 0xc2; // 0b11000010;
		mem[2] = 0xd1; // 0b11010001;
		mem[3] = 0x0 ; // 0b00000000;
		regs[3]    =         65;
		break;
	case 13:
		// ori x5, x3, 13
		mem[0] = 0x93; // 0b10010011;
		mem[1] = 0xe2; // 0b11100010;
		mem[2] = 0xd1; // 0b11010001;
		mem[3] = 0x0 ; // 0b00000000;
		regs[3]    =         65;
		break;
	case 14:
		// andi x5, x3, 13
		mem[0] = 0x93; // 0b10010011;
		mem[1] = 0xf2; // 0b11110010;
		mem[2] = 0xd1; // 0b11010001;
		mem[3] = 0x0 ; // 0b00000000;
		regs[3]    =         4;
		break;
	case 15:
		// slli x5, x3, 4
		mem[0] = 0x93; // 0b10010011;
		mem[1] = 0x92; // 0b10010010;
		mem[2] = 0x41; // 0b01000001;
		mem[3] = 0x0 ; // 0b00000000;
		regs[3]    =         17;
		break;
	case 16:
		// srli x5, x3, 4
		mem[0] = 0x93; // 0b10010011;
		mem[1] = 0xd2; // 0b11010010;
		mem[2] = 0x41; // 0b01000001;
		mem[3] = 0x0 ; // 0b00000000;
		regs[3]    =       -128;
		break;
	case 17:
		// srai x5, x3, 4
		mem[0] = 0x93; // 0b10010011;
		mem[1] = 0xd2; // 0b11010010;
		mem[2] = 0x41; // 0b01000001;
		mem[3] = 0x40; // 0b01000000;
		regs[3]    =       -128;
		break;
	case 18:
		// add x5, x3, x4
		mem[0] = 0xb3; // 0b10110011;
		mem[1] = 0x82; // 0b10000010;
		mem[2] = 0x41; // 0b01000001;
		mem[3] = 0x0 ; // 0b00000000;
		regs[3]    =       -128;
		regs[4]    =        130;
		break;
	case 19:
		// sub x5, x3, x4
		mem[0] = 0xb3; // 0b10110011;
		mem[1] = 0x82; // 0b10000010;
		mem[2] = 0x41; // 0b01000001;
		mem[3] = 0x40; // 0b01000000;
		regs[3]    =       -128;
		regs[4]    =        130;
		break;
	case 20:
		// sll x5, x3, x4
		mem[0] = 0xb3; // 0b10110011;
		mem[1] = 0x92; // 0b10010010;
		mem[2] = 0x41; // 0b01000001;
		mem[3] = 0x0 ; // 0b00000000;
		regs[3]    =       -128;
		regs[4]    =          2;
		break;
	case 21:
		// slt x5, x3, x4
		mem[0] = 0xb3; // 0b10110011;
		mem[1] = 0xa2; // 0b10100010;
		mem[2] = 0x41; // 0b01000001;
		mem[3] = 0x0 ; // 0b00000000;
		regs[3]    =       -128;
		regs[4]    =          2;
		break;
	case 22:
		// sltu x5, x3, x4
		mem[0] = 0xb3; // 0b10110011;
		mem[1] = 0xb2; // 0b10110010;
		mem[2] = 0x41; // 0b01000001;
		mem[3] = 0x0 ; // 0b00000000;
		regs[3]    =       -128;
		regs[4]    =          2;
		break;
	case 23:
		// xor x5, x3, x4
		mem[0] = 0xb3; // 0b10110011;
		mem[1] = 0xc2; // 0b11000010;
		mem[2] = 0x41; // 0b01000001;
		mem[3] = 0x0 ; // 0b00000000;
		regs[3]    =          5;
		regs[4]    =          4;
		break;
	case 24:
		// srl x5, x3, x4
		mem[0] = 0xb3; // 0b10110011;
		mem[1] = 0xd2; // 0b11010010;
		mem[2] = 0x41; // 0b01000001;
		mem[3] = 0x0 ; // 0b00000000;
		regs[3]    =       -128;
		regs[4]    =          2;
		break;
	case 25:
		// sra x5, x3, x4
		mem[0] = 0xb3; // 0b10110011;
		mem[1] = 0xd2; // 0b11010010;
		mem[2] = 0x41; // 0b01000001;
		mem[3] = 0x40; // 0b01000000;
		regs[3]    =       -128;
		regs[4]    =          2;
		break;
	case 26:
		// or x5, x3, x4
		mem[0] = 0xb3; // 0b10110011;
		mem[1] = 0xe2; // 0b11100010;
		mem[2] = 0x41; // 0b01000001;
		mem[3] = 0x0 ; // 0b00000000;
		regs[3]    =          5;
		regs[4]    =          4;
		break;
	case 27:
		// and x5, x3, x4
		mem[0] = 0xb3; // 0b10110011;
		mem[1] = 0xf2; // 0b11110010;
		mem[2] = 0x41; // 0b01000001;
		mem[3] = 0x0 ; // 0b00000000;
		regs[3]    =          5;
		regs[4]    =          4;
		break;
	case 28:
		// lui x5, 786439 
		mem[0] = 0xb7; // 0b10110111;
		mem[1] = 0x72; // 0b01110010;
		mem[2] = 0x0 ; // 0b00000000;
		mem[3] = 0xc0; // 0b11000000;
		break;
	case 29:
		// auipc x5, 786439 
		mem[0] = 0x97; // 0b10010111;
		mem[1] = 0x72; // 0b01110010;
		mem[2] = 0x0 ; // 0b00000000;
		mem[3] = 0xc0; // 0b11000000;
		break;
	case 30:
		// jal x5, 786439 
		mem[0] = 0xef; // 0b11101111;
		mem[1] = 0x72; // 0b01110010;
		mem[2] = 0x0 ; // 0b00000000;
		mem[3] = 0xc0; // 0b11000000;
		break;
	case 31:
		// jalr x5, -1024 
		mem[0] = 0xe7; // 0b11100111;
		mem[1] = 0x82; // 0b10000010;
		mem[2] = 0x1 ; // 0b00000001;
		mem[3] = 0xc0; // 0b11000000;
		regs[3]    = 3;
		break;
	case 32:
		// beq x3, x4, 5 
		mem[0] = 0xe3; // 0b11100011;
		mem[1] = 0x82; // 0b10000010;
		mem[2] = 0x71; // 0b01110001;
		mem[3] = 0x0 ; // 0b00000000;
		regs[3]    = 6;
		regs[7]    = 6;
		break;
	case 33:
		// bne x3, x4, 5 
		mem[0] = 0xe3; // 0b11100011;
		mem[1] = 0x92; // 0b10010010;
		mem[2] = 0x71; // 0b01110001;
		mem[3] = 0x0 ; // 0b00000000;
		regs[3]    = 6;
		regs[7]    = 6;
		break;
	case 34:
		// blt x3, x4, 5 
		mem[0] = 0xe3; // 0b11100011;
		mem[1] = 0xc2; // 0b11000010;
		mem[2] = 0x71; // 0b01110001;
		mem[3] = 0x0 ; // 0b00000000;
		regs[3]    = -6;
		regs[7]    = 6;
		break;
	case 35:
		// bge x3, x4, 5 
		mem[0] = 0xe3; // 0b11100011;
		mem[1] = 0xd2; // 0b11010010;
		mem[2] = 0x71; // 0b01110001;
		mem[3] = 0x0 ; // 0b00000000;
		regs[3]    = 6;
		regs[7]    = -6;
		break;
	case 36:
		// bltu x3, x4, 5 
		mem[0] = 0xe3; // 0b11100011;
		mem[1] = 0xe2; // 0b11100010;
		mem[2] = 0x71; // 0b01110001;
		mem[3] = 0x0 ; // 0b00000000;
		regs[3]    = -6;
		regs[7]    = 6;
		break;
	case 37:
		// bgeu x3, x4, 5 
		mem[0] = 0xe3; // 0b11100011;
		mem[1] = 0xf2; // 0b11110010;
		mem[2] = 0x71; // 0b01110001;
		mem[3] = 0x0 ; // 0b00000000;
		regs[3]    = 6;
		regs[7]    = -6;
		break;
	default:
		puts("No such test instruction");
	}

}
