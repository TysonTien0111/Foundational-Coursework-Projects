FILE_ASSEMBLY = editDist
FILE_ASSEMBLY_OUT = editDistAssemblyOut
FILE_ASSEMBLY_O = editDistAssemblyO

FILE_C = editDist
FILE_C_OUT = editDistCOut
FILE_C_O = editDistCO

CC = gcc
CFLAGS = -Wall -Werror -g

AS = as
ASFLAGS = --gstabs --32
LD = ld
LDFLAGS = -m elf_i386

all: $(FILE_C_OUT).out $(FILE_ASSEMBLY_OUT).out

$(FILE_C_OUT).out: $(FILE_C_O).o
	$(CC) $(CFLAGS) -o "$@" "$<"

$(FILE_C_O).o: $(FILE_C).c
	$(CC) $(CFLAGS) -c "$<" -o "$@"

$(FILE_ASSEMBLY_OUT).out: $(FILE_ASSEMBLY_O).o
	$(LD) $(LDFLAGS) -o $@ $<

$(FILE_ASSEMBLY_O).o: $(FILE_ASSEMBLY).s
	$(AS) $(ASFLAGS) -o $@ $<

clean:
	rm -f "$(FILE_C_OUT).out" "$(FILE_C_O).o" "$(FILE_ASSEMBLY_OUT).out" "$(FILE_ASSEMBLY_O).o"

.PHONY: all clean
