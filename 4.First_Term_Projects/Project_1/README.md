# Pressure Detection projecte

## Introduction
The program is designed for **STM32F103C6** to monitor pressure levels and activate an alarm when the pressure exceeds a predefined threshold.

#### Features
- Monitors pressure levels using a pressure sensor connected to a GPIO pin.
- Activates an alarm actuator when the pressure exceeds a predefined threshold.
- Utilizes GPIO manipulation macros for efficient control of GPIO pins.
- Implements a basic delay function for timing purposes.



## Startup
The startup code facilitates the initialization of key components necessary for the microcontroller's operation and setting up the microcontroller's environment including initializing the stack, defining the vector table, and directing the execution flow to the main application code.

#### Vector Table
The vector table defines the initial address for the stack and contains entries for various exception handlers and interrupts. Each entry in the vector table points to a specific handler function responsible for handling the corresponding exception or interrupt.

#### Sections
The code is organized into different sections to facilitate memory management and program execution. The `.vectors` section contains the vector table entries, while the `.text` section contains the main reset handler and other functions.

#### Conclusion
The Cortex M3 Startup Code provided serves as a foundation for initializing and configuring Cortex M3 microcontrollers. By properly setting up the vector table and defining the reset handler, you can ensure that your microcontroller operates reliably and efficiently.



## Linker
The linker script defines the memory layout and output sections for the microcontroller's firmware.

#### Memory Definition
The linker script defines two memory regions:

**Flash Memory (RX)**: Starting at address 0X08000000 with a length of 128K, this region is used for storing the program code.
**SRAM (RWX)**       : Starting at address 0X20000000 with a length of 20K, this region is used for storing initialized data, uninitialized data (BSS), and the stack.

#### Output Sections Definition
The linker script defines several output sections to organize the firmware image:

.text  : contains .vectors, .text and .rodata sections from all files, and the end is marked as _E_text. This section is located in the flash memory.
.data  : contains .data section from all files, and the start is marked as _S_data. The section is aligned to a memory address that is a multiple of 4 and the end is marked as _E_data. This section is located in sram memory, but it's loaded from the flash memory.
.bss   : contains .bss section from all files, and the start is marked as _S_bss. The section is aligned to a memory address that is a multiple of 4 and the end is marked as _E_bss. This section is located in sram memory and it doesn't load anything from the flash. A 0x1000 long empty space is added after the end of this section to maintain a safe space between the end of the program data and the stack top. The stack top is marked as _stack_top.



## Makefile
This project defines various symbols that are used in the building process of an Arm Cortex-M3 based microcontroller firmware.

#### Symbols
CC          : Defines the compiler toolchain (arm-none-eabi-).
CFLAGS      : Compiler flags include optimization for the Cortex-M3 (-mcpu=cortex-m3).
INCS        : Specifies the include directories (-I . for the current directory).
LIBS        : Specifies any additional static libraries (currently empty).
SRC         : Collects all source files ending with .c.
OBJ         : Translates .c files into object files (.o).
As          : Collects all assembly files ending with .s.
AsOBJ       : Translates assembly files into object files (.o).
Map         : Generates a map file (Map_file.map).
ProjectName : Specifies the name of the project (PressureMonitoringSystem).

#### Build Process
The build process consists of several steps:

1. startup.o: Assembles startup.s file to generate startup.o.
2. %.o: Compiles each .c file into its corresponding object file.
3. $(ProjectName).elf: Links all object files and assembly files into an ELF executable.
4. $(ProjectName).bin: Converts the ELF file into a binary file.

***To build the Pressure Monitoring System***:
Ensure that you have the appropriate toolchain (arm-none-eabi-) installed and configured.
Run make all to compile and link the project.
The resulting binary file will be named PressureMonitoringSystem.bin.
To clean the project directory, you can run make clean-all to remove all object files, ELF files, and binary files.



## Main.c

#### GPIO Macros
SET_BIT(ADDRESS, BIT)     : Sets (1) the specified bit in the memory address.
RESET_BIT(ADDRESS, BIT)   : Resets (0) the specified bit in the memory address.
TOGGLE_BIT(ADDRESS, BIT)  : Toggles the specified bit in the memory address.
READ_BIT(ADDRESS, BIT)    : Reads the value of the specified bit in the memory address.

#### GPIO Registers
GPIO_PORTA                : Base address of GPIO port A.
BASE_RCC                  : Base address of the RCC (Reset and Clock Control) register.
APB2ENR                   : APB2 peripheral clock enable register.
GPIOA_CRL, GPIOA_CRH      : Configuration registers for GPIO port A.
GPIOA_IDR                 : Input data register for GPIO port A.
GPIOA_ODR                 : Output data register for GPIO port A.

#### Functions
Delay(int nCount)         : Provides a simple delay mechanism for timing purposes.
getPressureVal()          : Reads the pressure value from the GPIO input register.
Set_Alarm_actuator(int i) : Controls the alarm actuator based on the input parameter.
Initialization
GPIO_INITIALIZATION(): Initializes GPIO pins and registers for pressure sensing and alarm actuation.



## MapFile
This map file provides a detailed overview of the memory layout and sections of the "PressureMonitoringSystem.elf" file generated by the linker. Here's a breakdown of the key sections:

#### Memory Configuration:
flash   : Starting at address 0x08000000, with a length of 0x00020000 (128 KB), and it has execute and read permissions (xr).
sram    : Starting at address 0x20000000, with a size of 0x00005000 (20 KB), and it's readable, writable, and executable (xrw).
default : Represents unspecified memory regions, spanning from address 0x00000000 to 0xffffffff.

#### Linker Script and Memory Map:
.text Section (Code and Read-Only Data):
.vectors: Vector table located at address 0x08000000.
.text: Main program code including functions like Delay, getPressureVal, Set_Alarm_actuator, GPIO_INITIALIZATION, and main.
.rodata: Contains read-only data.

**Linker Stubs**:
.glue_7, .glue_7t, .vfp11_veneer, .v4_bx: These sections are linker stubs.

**Additional Sections**:
.iplt, .rel.dyn, .rel.iplt: Sections for dynamic linking and relocation.
.data Section (Initialized Data):
.data: Initialized data section, loaded at address 0x20000000.
.igot.plt Section (Global Offset Table Entries):
.igot.plt: Contains global offset table entries.
.bss Section (Uninitialized Data):
.bss: Uninitialized data section, loaded at address 0x20000000, spanning a size of 0x1000 (4 KB).

**Stack**: Starts at 0x20000000 and ends at _stack_top.
LOAD and OUTPUT Information:
LOAD main.o, LOAD startup.o: Loading information for object files.
OUTPUT(PressureMonitoringSystem.elf elf32-littlearm): Specifies the output file format and architecture.

**Other Sections**:
.comment, .ARM.attributes: Sections for comments and ARM attributes, primarily used for debugging purposes.

This map file is crucial for understanding the memory layout, section sizes, load addresses, and ensuring proper program execution on the Cortex M3 microcontroller platform.




## Usage
- Configure the microcontroller environment and ensure compatibility with the provided code.
- Connect the pressure sensor to the designated GPIO pin for pressure input.
- Connect the alarm actuator to the GPIO pin configured for alarm actuation.
- Adjust the threshold value (threshold) in the main function to the desired pressure level.
- Compile and upload the program to the microcontroller.

#### Troubleshooting
If the alarm is continuously activated, check the pressure sensor readings and the threshold value.
Verify GPIO pin configurations and connections to ensure proper functionality.
Debug the program using print statements or debugging tools to identify any issues.
