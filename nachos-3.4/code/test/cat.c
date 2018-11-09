#include "syscall.h"
#define MAX_LENGTH 32

int main()
{
	int openFileId;//Save idFile
	int fileSize;//LengthFIle
	int stdin;//doc tu consoloe
	char * buffer;
	char c; //Ky tu de in ra
	int i; //Index for loop

	PrintString("Input FileName to read: ");
        ReadString(buffer, 225);//Doc chuoi vua nhap luu vao buffer

	openFileId = Open(buffer, 1); // Goi ham Open de mo file do, 1<=> only read
	if (openFileId != -1) //Kiem tra Open co loi khong
	{
		//Seek den cuoi file de lay duoc do dai noi dung (fileSize)
		fileSize = Seek(-1, openFileId);
		i = 0;
		// Seek den dau tap tin de tien hanh Read
		Seek(0, openFileId);
		
		PrintString("Content of FileName:\n");
		for ( ; i < fileSize; i++) // Cho vong lap chay tu 0 - fileSize
		{
			Read(&c, 1, openFileId); // Goi ham Read de doc tung ki tu noi dung file
			PrintChar(c); // Goi ham PrintChar de in tung ki tu ra man hinh
		}
		Close(openFileId); // Goi ham Close de dong file
	}
	else
	{
		PrintString("Not Open File to read...\n\n");
	}
	return 0;
}

