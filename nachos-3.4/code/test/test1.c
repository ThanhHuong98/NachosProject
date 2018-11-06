#include"syscall.h"
#include"copyright.h"
int main()
{
	char buffer[255];
	char str[256];
	int f;
	int len;

	PrintString("file name = ");
	ReadString(str,256);
	f=Open(str,1);

	if(f==-1)
	{
		PrintString("Fail..\n");
	}
	else
	{
		 len = Read(buffer, 255, f);
		if(len==-1 | len ==-2)
		{
			PrintString("Fail..\n");	
		}
		else
		{
			int stdout = Open("stdout",3);
			int a = Write(buffer,len,stdout);
			Close(stdout);
		}
		Close(f);
	}

	return 0;
}
