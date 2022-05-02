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

	writeNewUser.close();

	//cout << username << "\n";
	//cout << password << "\n";
	//cout << email << "\n";
}
void User::giveUser()
{
	ifstream giveUser("C:/Users/ACER/source/repos/fmi project (1)/file.txt", ios::in);
	int leng = 0;
	giveUser.read((char*)&leng, sizeof(leng));
	char* give1 = new char[leng];
	giveUser.read(give1, leng);
	cout << give1 << "\n";

	int pos = giveUser.tellg();
	giveUser.seekg(pos += 2);
	giveUser.read((char*)&leng, sizeof(leng));
	char* give2 = new char[leng];
	giveUser.read(give2, leng);
	cout << give2 << "\n";

	pos = giveUser.tellg();
	giveUser.seekg(pos += 2);
	giveUser.read((char*)&leng, sizeof(leng));
	char* give3 = new char[leng];
	giveUser.read(give3, leng);
	cout << give3 << "\n";

	delete[] give1;
	delete[] give2;
	delete[] give3;
}
User::~User()
{
	delete[] username;
}