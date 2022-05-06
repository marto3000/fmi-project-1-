#include <iostream>
#include <fstream>
#include "header.h"
using namespace std;
//file location: "C:/Users/ACER/source/repos/fmi project (1)/file.txt" !!!REPLACE EVERYWHERE WHEN USING FILE WITH DIFFERENT PATH!!!

int main()
{
	User user;
	//user.writeUser();
	char* temp = new char[14];
	strcpy_s(temp, 14, "default emai2");
	user.giveUser(temp);
	delete[] temp;
}