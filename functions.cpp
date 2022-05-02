#include <iostream>
#include <fstream>
#include "header.h"
using namespace std;
//file location: "C:/Users/ACER/source/repos/fmi project (1)/file.txt" !!!REPLACE EVERYWHERE WHEN USING FILE WITH DIFFERENT PATH!!!

User::User()//not logged default user
{
	username = new char[13];//name length
	strcpy_s(username, 13, "default name");

	password = new char[17];//password length
	strcpy_s(password, 17, "default password");
	
	email = new char[14];//email length;
	strcpy_s(email, 14, "default email");

	//cout << username << "\n";
	//cout << password << "\n";
	//cout << email << "\n";
	//not needed stuff \/ \/ \/
	//ofstream first("C:/Users/ACER/source/repos/fmi project (1)/file.txt", ios::out);
	//int temp = 0;
	//first.write((char*)&temp, sizeof(temp));
}
void User::writeUser()//for saving new users in the file
{
	ifstream getCtrlNum("C:/Users/ACER/source/repos/fmi project (1)/file.txt", ios::in);
	int ctrlNum;
	getCtrlNum.read((char*)&ctrlNum, sizeof(ctrlNum));
	ctrlNum = ctrlNum + strlen(email) + 5;
	
	//cout << ctrlNum;

	getCtrlNum.close();

	ofstream writeNewUser("C:/Users/ACER/source/repos/fmi project (1)/file.txt", ios::out);
	writeNewUser.write((char*)&ctrlNum, sizeof(ctrlNum));
	writeNewUser.seekp(5);
	writeNewUser.write("1", 1);
	//int leng = strlen(username) + 1;
	//writeNewUser.write((char*)&leng, sizeof(leng));
	//writeNewUser.write(username, leng).write("\n", 1);
	//
	//leng = strlen(password) + 1;
	//writeNewUser.write((char*)&leng, sizeof(leng));
	//writeNewUser.write(password, leng).write("\n", 1);
	//
	//leng = strlen(email) + 1;
	//writeNewUser.write((char*)&leng, sizeof(leng));
	//writeNewUser.write(email, leng).write("\n", 1);
	//writeNewUser.close();
}
void User::giveUser()//from the file
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