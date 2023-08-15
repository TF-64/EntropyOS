
SRC=src
BUILD=build
BOOT=boot

SYSROOT=src/sysroot
INCLUDE=src/include


GCC=i686-elf-gcc
ASM=i686-elf-as
QEMU=qemu-system-i386
PYTHON=python3


NAME=Entropy










# MAIN COMPILATION



all:
	$(ASM) $(SRC)/kernel/arch/boot.s -o $(BUILD)/boot.o
	$(GCC) -c $(SRC)/kernel/kernel/kernel.c -o $(BUILD)/kernel.o -I$(INCLUDE) --no-sysroot-suffix  -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	$(PYTHON) auto_compiler.py
	$(PYTHON) auto_linker.py $(NAME)


# RUNNING

isorun:
	cp $(BUILD)/$(NAME).bin $(BOOT)/$(NAME).bin
	cp grub.cfg $(BOOT)/grub/grub.cfg
	grub-mkrescue -o $(BUILD)/$(NAME).iso
	$(QEMU) -cdrom $(NAME).iso

run:
	$(QEMU) -kernel $(BUILD)/$(NAME).bin


clear:
	rm -rf build
	mkdir build
	rm $(NAME).iso


