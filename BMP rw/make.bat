nasm -f win64 test.asm -o test.obj
g++ .\imagen.cpp .\imagen.h .\main.cpp .\test.obj -o asmtest.exe -no-pie
