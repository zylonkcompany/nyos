CC=gcc
AS=as
LD=ld
CFLAGS=-ffreestanding -m32 -fno-pic -fno-pie -Iinc/
ASFLAGS=-32
LDFLAGS=-m elf_i386 -T linker.ld

all:
	$(CC) $(CFLAGS) -c kernel.c -o Obj/myos.o
	$(CC) $(CFLAGS) -c hal.c -o Obj/hal.o
	$(AS) $(ASFLAGS) boot.s -o Obj/boot.o
	$(LD) $(LDFLAGS) Obj/* -o nyoskrnl.bin
	cp nyoskrnl.bin isodir/boot/
	grub-mkrescue -o myos.iso isodir --directory=/usr/lib/grub/i386-pc --modules="biosdisk part_msdos multiboot"
	qemu-system-i386 -cdrom myos.iso


clean:
	rm Obj/*



