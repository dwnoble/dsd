# DSD Test Makefile
# For testing common.c and string.c functions

# Source file path
VPATH=../src

# Add new source files to the following categories to include in the DSD build
TEST_C_SOURCES := test.c
DSD_C_SOURCES := 
DSD_ASM_SOURCES := 
COMMON_C_SOURCES := common.c string.c

# Object files
TEST_C_OBJECTS := $(TEST_C_SOURCES:%.c=../test/%.o)
DSD_C_OBJECTS := $(DSD_C_SOURCES:%.c=dsd/%.o)
DSD_ASM_OBJECTS := $(DSD_ASM_SOURCES:%.s=dsd/%.o)
COMMON_C_OBJECTS := $(COMMON_C_SOURCES:%.c=common/%.o)
ALL_OBJECTS := $(TEST_C_OBJECTS) $(DSD_C_OBJECTS) $(DSD_ASM_OBJECTS) $(COMMON_C_OBJECTS)

# Compiler and linker settings
CFLAGS= -I../inc/dsd -I../inc/common
LDFLAGS= 
CC=gcc
LD=gcc
AS=nasm

# Rules
all: test 

clean:
	rm dsd/*.o common/*.o test ../test/*.o 

test: $(ALL_OBJECTS)
	$(LD) $(LDFLAGS) -o test $(ALL_OBJECTS)

../test/%.o : ../test/%.c
	$(CC) $(CFLAGS) $< -c -o ../test/$*.o 

dsd/%.o : dsd/%.c
	$(CC) $(CFLAGS) $< -c -o dsd/$*.o

common/%.o : common/%.c
	$(CC) $(CFLAGS) $< -c -o common/$*.o


