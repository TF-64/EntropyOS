from sys import argv
from os import system, listdir
from os.path import isfile, join
from pathlib import Path


path = str(Path().resolve())

def compile_all(compile_path, build_path):
    
    for file in listdir(compile_path):
        if isfile(join(compile_path, file)):
           if (file[-2] + file[-1]) == '.c':
               system(f'i686-elf-gcc -c {join(compile_path, file)} -o {build_path}/{file[0:len(file)-2]}.o -Isrc/include -lgcc -ffreestanding -O2 -nostdlib')
        else:
            compile_all(compile_path + '/' + file, build_path)


# compile path, build path, name of .bin file

compile_all(path + '/' + argv[1], path + "/build")


#system('i686-elf-gcc -T src/kernel/arch/linker.ld -o build/Entropy.bin  -ffreestanding -O2 -nostdlib build/
#    boot.o build/kernel.o build/abort.o build/memcmp.o build/memcpy.o build/memmove.o build/memset.o build/printf.o build/putch
#   ar.o build/strlen.o build/tty.o -lgcc')






