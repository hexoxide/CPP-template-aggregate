#ifndef BAR_H_
#define BAR_H_

namespace Bar {
	unsigned long base() {
	    unsigned long a = 0; // a will be stored at base pointer -8 (64 bits is 8 bytes)
	    asm("movq    %rbp, -8(%rbp)"); // move the stack pointer into a
	    return a; // return the stack pointer
	    // we can now deduce the location of the foo function in stack memory
	}
	unsigned long stack() {
	    unsigned long a = 0; // a will be stored at base pointer -8 (64 bits is 8 bytes)
	    asm("movq    %rsp, -8(%rbp)"); // move the stack pointer into a
	    return a; // return the stack pointer
	    // we can now deduce the location of the foo function in stack memory
	}
	unsigned long rsi() {
	    unsigned long a = 0; // a will be stored at base pointer -8 (64 bits is 8 bytes)
	    asm("movq    %rsi, -8(%rbp)"); // move the stack pointer into a
	    return a; // return the stack pointer
	    // we can now deduce the location of the foo function in stack memory
	}
	unsigned long rdi() {
	    unsigned long a = 0; // a will be stored at base pointer -8 (64 bits is 8 bytes)
	    asm("movq    %rdi, -8(%rbp)"); // move the stack pointer into a
	    return a; // return the stack pointer
	    // we can now deduce the location of the foo function in stack memory
	}
}

#endif //  BAR_H_
