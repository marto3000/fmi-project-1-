#include <iostream>
#include <fstream>
#include "header.h"
using namespace std;
//file location: "C:/Users/ACER/source/repos/fmi project (1)/file.txt" !!!REPLACE EVERYWHERE WHEN USING FILE WITH DIFFERENT PATH!!!

int main()
{
	User user;
	//user.writeUser();
	char* temp1 = new char[14];
	strcpy_s(temp1, 14, "default emai2");
	char* temp2 = new char[17];
	strcpy_s(temp2, 17, "default passwor2");
	user.giveUser(temp1, temp2);
	delete[] temp1;
}