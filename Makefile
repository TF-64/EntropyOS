
SRC=src
BUILD=build
BOOT=boot

SYSROOT=src/sysroot
INCLUDE=src/include


GCC=i686-elf-gcc
ASM=i686-elf-as
QEMU=qemu-system-i386

NAME=Entropy










# MAIN COMPILATION

# - - note - -
#	libc_cv_forced_unwind=yes libc_cv_c_cleanup=yes
#
#
#



all:
	$(ASM) $(SRC)/kernel/arch/boot.s -o $(BUILD)/boot.o
	$(GCC) -c $(SRC)/kernel/kernel/kernel.c -o $(BUILD)/kernel.o -I$(INCLUDE) --no-sysroot-suffix  -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	$(GCC) -T $(SRC)/kernel/arch/linker.ld -o $(BUILD)/$(NAME).bin  -ffreestanding -O2 -nostdlib $(BUILD)/boot.o $(BUILD)/kernel.o -lgcc
	


# RUNNING

cdrom:
	cp $(BUILD)/$(NAME).bin $(BOOT)/$(NAME).bin
	cp grub.cfg $(BOOT)/grub/grub.cfg
	grub-mkrescue -o $(BUILD)/$(NAME).iso
	$(QEMU) -cdrom $(NAME).iso

kernel:
	$(QEMU) -kernel $(BUILD)/$(NAME).bin






