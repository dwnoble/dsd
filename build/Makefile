# DSD Makefile

# Source file path
VPATH=../src

# Add new source files to the following categories to include in the DSD build
DSD_C_SOURCES := main.c monitor.c isr.c descriptor_tables.c timer.c kheap.c paging.c ordered_array.c
DSD_ASM_SOURCES := boot.s gdt.s interrupt.s video.s
COMMON_C_SOURCES := common.c string.c

# Object files
DSD_C_OBJECTS := $(DSD_C_SOURCES:%.c=dsd/%.o)
DSD_ASM_OBJECTS := $(DSD_ASM_SOURCES:%.s=dsd/%.o)
COMMON_C_OBJECTS := $(COMMON_C_SOURCES:%.c=common/%.o)
ALL_OBJECTS := $(DSD_ASM_OBJECTS) $(DSD_C_OBJECTS) $(COMMON_C_OBJECTS)

# Compiler and linker settings
CFLAGS=-nostdlib -nostdinc -fno-builtin -fno-stack-protector -m32 -I../inc/dsd -I../inc/common
LDFLAGS=-T Link.ld -melf_i386
ASFLAGS=-felf
CC=gcc
AS=nasm

# Rules
all: kernel 

clean:
	rm dsd/*.o common/*.o kernel

kernel: $(ALL_OBJECTS)
	ld $(LDFLAGS) -o kernel $(ALL_OBJECTS)

dsd/%.o : dsd/%.s
	$(AS) $(ASFLAGS) $< -o dsd/$*.o

dsd/%.o : dsd/%.c
	$(CC) $(CFLAGS) $< -c -o dsd/$*.o

common/%.o : common/%.c
	$(CC) $(CFLAGS) $< -c -o common/$*.o


