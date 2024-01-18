/*
Startup Cortex M3
Eng.Emad.Hajaj
*/

/* ======== VECTOR TABLE ======== */
.section .vectors /*put the below code in vectors section (in debugging)*/

.word 0x20001000  /*Stack Top address (in this MC you don't set the SP at reset section, instead the MC save the first thing in the flash at SP)*/
.word _reset
.word vector_handler            /*_NMI*/
.word vector_handler            /*_Hard_Fault*/
.word vector_handler            /*_MM_Fault*/
.word vector_handler            /*_Bus_Fault*/
.word vector_handler            /*_Usage_Fault*/
.word vector_handler            /*_RESERVED*/
.word vector_handler            /*_RESERVED*/
.word vector_handler            /*_RESERVED*/
.word vector_handler            /*_RESERVED*/
.word vector_handler            /*_SV_call*/
.word vector_handler            /*_Debug_reserved*/
.word vector_handler            /*_RESERVED*/
.word vector_handler            /*_Pendsv*/
.word vector_handler            /*_SysTick*/
.word vector_handler            /*_IRQ0*/
.word vector_handler            /*_IRQ1*/
.word vector_handler            /*_IRQ2*/
/*you are supposed to define each section, but for the sake of this example lets redirect them to reset section*/

/* ======== SECTIONS ======== */
.section .text /*put the below code in text section (in debugging)*/

_reset:           /*to avoid the conflict between reset section and variables called reset in .c files we use _*/
	bl main       /*Jump to main(), we can change the name of the main() from here*/
	b .           /*Loop over yourself if you exit main()*/

.thumb_func       /*this MC has combination of 32 and 16 bit instructions, this func handels them*/

vector_handler:
	b _reset