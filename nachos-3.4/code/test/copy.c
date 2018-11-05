#include "syscall.h"
#define TRUE 1

int main(int argc, char const *argv[])
{
    char* buf;
    int size = 255;
    int srcFile = Open("myFile.txt", 0);
    int desFile = CreateFile("newww.txt");
    PrintChar('m');
    Read(buf, size, srcFile);
    Halt();

    return 0;
}
