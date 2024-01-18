#include <stdint.h>
#define STACK_Start_SP 0x20001000 
extern int main(void);


// ============= VECTOR TABLE =============

// Weak: allow other functions to override the function for example the IRS
// Alias: make multiple interrupts point at same position till the customer overrides them with (makes all unused point at same place)

void Rest_Handler (void);

void Default_Handler(){Rest_Handler();}

void NMI_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));;
void H_fault_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));;

// booking 1024 bit located by .bss
static unsigned long stackTop[256];

// __attribute__ talks to the compiler directly and set them in .vectors section
void (* const g_p_fn_Vectors[])() __attribute__((section(".vectors"))) = {
	(void (*)()) ((unsigned long) stackTop + sizeof(stackTop)),
	&Rest_Handler,
	&NMI_Handler,
	&H_fault_Handler,
};

extern unsigned int _E_text;
extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;

void Rest_Handler(){
	// copy data from flash to ram
	unsigned int dataSize = (unsigned char*)&_E_data - (unsigned char*)&_S_data;
	unsigned char* P_src = (unsigned char*)&_E_text;
	unsigned char* P_dst = (unsigned char*)&_S_data;
	int i;
	for(i=0; i< dataSize; i++){
		*((unsigned char*) P_dst++) = *((unsigned char*) P_src++);
	}

	// init bss section in sram = 0
	unsigned int bssSize = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
	P_src = (unsigned char*)&_S_bss;
	for(i=0; i< bssSize; i++){
		*((unsigned char*) P_dst++) = (unsigned char)0;
	}

	// jump to main
	main();
}