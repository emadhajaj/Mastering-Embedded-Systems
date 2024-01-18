# SYMBOLS

CC     = arm-none-eabi-# ToolChain
CFLAGS = -g -mcpu=arm926ej-s #-g (Debug Info)  -O0 (Optimization) -mcpu (MC name)
INCS   = -I. # include header
LIBS   = # Created static Lib
SRC    = $(wildcard *.c) #Collect all files .c
OBJ    = $(SRC:.c=.o) #replace the names from .c to .o 
As     = $(wildcard *.s) #Collect all files .c
AsOBJ  = $(As:.s=.o) #replace the names from .c to .o 

all: learn-in-depth.bin
	@echo "============build is done============"

# $< is replaced with the dependencies
# $@ is replaced with the target
# % means all files

startup.o: startup.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

learn-in-depth.elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@

learn-in-depth.bin: binary learn-in-depth.elf
	$(CC)objcopy.exe -O binary $<  $@

clean-all:
	rm *.o *.elf *.bin

clean:
	rm *.elf *.bin