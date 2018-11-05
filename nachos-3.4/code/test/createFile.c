#include "syscall.h"
#define MAX_LENGTH 32
int main()
{
	int stdin;
	char fileName[MAX_LENGTH];
	PrintString("\n\t\t\t-----Chuong trinh createfile-----\n\n");
	PrintString("Nhap ten file tu stdin (Open(stdin)): ");
	//ReadString(fileName, MAX_LENGTH);//Doc ten file nhap tu consile <stdin> save vo fileName
	stdin = Open("stdin", 2); // Goi ham Open mo file stdin nhap vao ten file, 2<=>stdin
	if(stdin != -1)//Thanh cong
	{
		int len = Read(fileName, MAX_LENGTH, stdin); // Goi ham Read doc ten file vua nhap <tu stdin>
		if (len != -1 && len != -2) //Kiem tra co bi loi, hay co EOF hay khong
		{
			if (CreateFile(fileName)==0) // Goi ham CreateFile
			{
				PrintString("Create file thanh cong.\n\n");
			}

		}
		else
			PrintString("Ten file khong hop le!!!\n\n");
	Close(stdin); // Goi ham Close de dong stdin
	}
	return 0;
}
