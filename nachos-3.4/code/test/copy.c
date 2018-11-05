#include "syscall.h"
#define TRUE 1

int main(int argc, char const *argv[])
{
    char* buf;
    int size;
    int srcFile = Open("myFile.txt", 1);
    int desFile = CreateFile("neww.txt");
   do {
       size = Read(buf, 255, srcFile);
       if (size = -1) break;
       Write(buf, size, desFile);
   } while (TRUE);
    PrintString(buf);
    return 0;
}
