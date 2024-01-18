/*
Startup Cortex M3
Eng.Emad.Hajaj
*/

/* ============ MEMORY DEFINITION ============ */
MEMORY
{
flash(RX) : ORIGIN = 0X08000000, LENGTH = 128K
sram(RWX) : ORIGIN = 0X20000000, LENGTH = 20K
}

/* ============ OUTPUT SECTIONS DEFINITION ============ */
SECTIONS
{
	.text : {
		*(.vectors)    /*from all files take .vectors sections*/
		*(.text)       /*from all files take .text sections*/
		*(.rodata)     /*from all files take .rodata sections*/
		_E_text = . ;  /*text end*/
	}> flash

	.data : {
		_S_data = . ;  /*data start*/
		*(.data)
		. = ALIGN(4);
		_E_data = . ;  /*data end*/
	}> sram AT> flash

	.bss : {
		_S_bss = . ;  /*bss start*/
		*(.bss)
		_E_bss = . ;  /*bss end*/
		. = ALIGN(4);
		. = . + 0x1000;
		_stack_top = .;
	}> sram
}