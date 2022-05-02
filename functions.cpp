#include <iostream>
#include <fstream>
#include "header.h"
using namespace std;
//file location: "C:/Users/ACER/source/repos/fmi project (1)/file.txt" !!!REPLACE EVERYWHERE WHEN USING FILE WITH DIFFERENT PATH!!!

User::User()
{
	ofstream writeNewUser("C:/Users/ACER/source/repos/fmi project (1)/file.txt", ios::out);
	int leng = 13;//name length
	username = new char[leng];
	strcpy_s(username, leng, "default name");
	writeNewUser.write((char*)&leng, sizeof(leng));
	writeNewUser.write(username, leng).write("\n", 1);

	leng = 17;//password length
	password = new char[leng];
	strcpy_s(password, leng, "default password");
	writeNewUser.write((char*)&leng, sizeof(leng));
	writeNewUser.write(password,leng).write("\n", 1);

	leng = 14;//email length;
	email = new char[leng];
	strcpy_s(email, leng, "default email");
	writeNewUser.write((char*)&leng, sizeof(leng));
	writeNewUser.write(email, leng).write("\n", 1);

	//cout << username << "\n";
	//cout << password << "\n";
	//cout << email << "\n";
}
User::~User()
{
	delete[] username;
}