# DSD Makefile

# Based off of makefile for JamesM's kernel tutorials.

SOURCES=boot.o main.o common.o monitor.o
SRCDIR=../src

CFLAGS=-nostdlib -nostdinc -fno-builtin -fno-stack-protector -m32 -I../inc
LDFLAGS=-T $(SRCDIR)/Tlink.ld -melf_i386
ASFLAGS=-felf
CC=gcc

AS=nasm

all: $(SOURCES) link 

clean:
	rm *.o kernel

link:
	ld $(LDFLAGS) -o kernel $(SOURCES)

boot.o:
	$(AS) $(ASFLAGS) $(SRCDIR)/boot.s -o boot.o

main.o:
	$(CC) $(CFLAGS) $(SRCDIR)/main.c -c -o main.o

common.o:
	$(CC) $(CFLAGS) $(SRCDIR)/common.c -c -o common.o

monitor.o:
	$(CC) $(CFLAGS) $(SRCDIR)/monitor.c -c -o monitor.o
