#include <iostream>
#include <fstream>
#include "header.h"
using namespace std;
//file location: "C:/Users/ACER/source/repos/fmi project (1)/file.txt" !!!REPLACE EVERYWHERE WHEN USING FILE WITH DIFFERENT PATH!!!

User::User()
{
	ofstream writeNewUser("C:/Users/ACER/source/repos/fmi project (1)/file.txt", ios::out);
	username = new char[13];
	strcpy_s(username, 13, "default name");
}