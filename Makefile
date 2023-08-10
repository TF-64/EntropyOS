
SRC=src
BUILD=build
BOOT=boot

GCC=i686-elf-gcc
ASM=i686-elf-as
QEMU=qemu-system-i386

NAME=Entropy

all:
	$(ASM) $(SRC)/boot.s -o $(BUILD)/boot.o
	$(GCC) -c $(SRC)/kernel.c -o $(BUILD)/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	$(GCC) -T $(SRC)/linker.ld -o $(BUILD)/$(NAME).bin -ffreestanding -O2 -nostdlib $(BUILD)/boot.o $(BUILD)/kernel.o -lgcc

cdrom:
	cp $(BUILD)/$(NAME).bin $(BOOT)/$(NAME).bin
	cp grub.cfg $(BOOT)/grub/grub.cfg
	grub-mkrescue -o $(BUILD)/$(NAME).iso
	$(QEMU) -cdrom $(NAME).iso

kernel:
	$(QEMU) -kernel $(BUILD)/$(NAME).bin

