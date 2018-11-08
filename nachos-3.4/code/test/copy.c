#include "syscall.h"
#define TRUE 1

int main(int argc, char const *argv[])
{
    char buf[255];
    char filename_in[32];
    char filename_out[32];
    int size = 255;
    int stdin;
    int srcFile;
    int desFile;

    stdin = Open("stdin", 2);
    PrintString("\nFile input:");
    Read(filename_in, 32, stdin);
    srcFile = Open(filename_in, 1);

    PrintString("\nFile output:");
    Read(filename_out, 32, stdin);
    CreateFile(filename_out);
   
    desFile = Open(filename_out, 0);

    size = Read(buf, size, srcFile);
    PrintString(buf);
    Write(buf, size, desFile);
    
    Close(srcFile);
    Close(desFile);
    PrintString("Finish!");
    Halt();

    return 0;
}
