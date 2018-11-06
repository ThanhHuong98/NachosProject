#include "syscall.h"
#define TRUE 1

int main(int argc, char const *argv[])
{
    char buf[255];
    int size = 255;
    int srcFile;
    int desFile;

    CreateFile("newww.txt");
    srcFile = Open("myFile.txt", 0);
    desFile = Open("newww.txt", 0);
    
    Read(buf, size, srcFile);
    PrintString(buf);
    Write(buf, size, desFile);
    
    Close(srcFile);
    Close(desFile);
    PrintString("Finish!");
    //Halt();

    return 0;
}
