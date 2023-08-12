from sys import argv
from os import system, listdir
from os.path import isfile, join


def compile_all(compile_path, build_path):
    
    for file in listdir(compile_path):
        if isfile(join(compile_path, file)):
           if (file[-2] + file[-1]) != '.h' and file != '.DS_Store':
                system(f'i686-elf-gcc -c {join(compile_path, file)} -o {build_path}/{file.split()[0]}.o -lgcc')
        
        else:
            compile_all(compile_path + '/' + file, build_path)


compile_all(argv[1], argv[2])





