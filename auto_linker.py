#$(GCC) -T $(SRC)/kernel/arch/linker.ld -o $(BUILD)/$(NAME).bin  -ffreestanding -O2 -nostdlib $(BUILD)/boot.o $(BUILD)/kernel.o -lgcc


from sys import argv
from os import system, listdir
from os.path import isfile, join
from pathlib import Path


path = str(Path().resolve())

base_command = f"i686-elf-gcc -T {path}/src/kernel/arch/linker.ld -o {path}/build/{argv[1]}.bin -ffreestanding -O2 -nostdlib "


for file in listdir(f"{path}/build"):
    if file[-2] + file[-1] == '.o':
        base_command +='build/' + file + ' '


system(base_command)






