﻿#include "syscall.h"
#define MAX 255

int main()

{
	int stdin;
	int stdout;
	char buf[MAX];
	int length;
	
	stdin = Open("stdin", 2); //mở stdin, type quy định ban đầu là 2
	if(stdin == -1) //mở khong thành công
	{
		PrintString("\nLoi mo file dang stdin!");
	}
	else
	{
		PrintString("\nMo file dang stdin thanh cong!");

		length = Read(buf, MAX, stdin); //gọi hàm Read để đọc nội dung người dùng nhập vào tư console

		//Nếu đọc thành công thì length sẽ chứa độ dài là số byte đọc được

		if(length ==-1 || length==-2) //kiểm tra xem đọc file có bị lỗi hoặc đã đến cuối file chưa?

		{
			PrintString("\nLoi doc file hoac da den cuoi file!");
		}
		else
		{
			PrintString("\nDoc file thanh cong!");

			stdout = Open("stdout", 3); //mở stdout, type quy định ban đầu là 3

			if(stdout == -1) //mở khong thành công

			{
				PrintString("\nLoi mo file dang stdin!");
			}
			else
			{

				Write(buf, length, stdout);
				Close(stdout);
			}

		}
		Close(stdin);

	}

	

}
