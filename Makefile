CC=gcc
AS=as
LD=ld
CFLAGS=-ffreestanding -m32 -fno-pic -fno-pie -Iinc/
ASFLAGS=-32
LDFLAGS=-m elf_i386 -T linker.ld

all: link

compile:
	mkdir -p Obj
	$(CC) $(CFLAGS) -c kernel.c -o Obj/myos.o
	$(CC) $(CFLAGS) -c hal.c -o Obj/hal.o
	$(AS) $(ASFLAGS) boot.s -o Obj/boot.o

link: compile
	mkdir -p Bin
	$(LD) $(LDFLAGS) Obj/* -o Bin/nyoskrnl.bin

clean:
	rm -rf Obj Bin



