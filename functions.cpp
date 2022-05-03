#include <iostream>
#include <fstream>
#include "header.h"
using namespace std;
//file location: "C:/Users/ACER/source/repos/fmi project (1)/file.txt" !!!REPLACE EVERYWHERE WHEN USING FILE WITH DIFFERENT PATH!!!

User::User()//not logged default user
{
	username = new char[13];//name length
	strcpy_s(username, 13, "default nam3");

	password = new char[17];//password length
	strcpy_s(password, 17, "default passwor3");
	
	email = new char[14];//email length;
	strcpy_s(email, 14, "default emai3");

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
	ofstream writeNewUser("C:/Users/ACER/source/repos/fmi project (1)/file.txt", ios::app);
	int maxLeng = strlen(username) + strlen(password) + strlen(email) + 15;
	writeNewUser.write((char*)&maxLeng, sizeof(maxLeng));

	int leng = strlen(username) + 1;
	writeNewUser.write((char*)&leng, sizeof(leng));
	writeNewUser.write(username, leng).write("\n", 1);
	
	leng = strlen(password) + 1;
	writeNewUser.write((char*)&leng, sizeof(leng));
	writeNewUser.write(password, leng).write("\n", 1);
	
	leng = strlen(email) + 1;
	writeNewUser.write((char*)&leng, sizeof(leng));
	writeNewUser.write(email, leng).write("\n", 1);
	writeNewUser.close();
}
void User::giveUser(int position)//from the file
{
	//while (position < 1)
	//{
	//	//write validation later
	//}
	ifstream giveUser("C:/Users/ACER/source/repos/fmi project (1)/file.txt", ios::in);
	//for (int i = 0; i < position; i++)//this starts to skip users from the first one
	//{
	//	int tempTellg = giveUser.tellg();
	//	int tempLen = 0;
	//	giveUser.read((char*)&tempLen, sizeof(tempLen));
	//	giveUser.seekg(tempLen + tempTellg);
	//}

	//int tempLen = 0;
	//giveUser.read((char*)&tempLen, sizeof(tempLen));
	//cout << giveUser.tellg();
	//int tempTellg = giveUser.tellg();
	//tempLen += tempTellg;
	//giveUser.seekg(tempLen);
	giveUser.seekg(66);

	//
	//cout << giveUser.tellg() << "\n";

	int skipMaxLen = giveUser.tellg();
	skipMaxLen += 4;
	giveUser.seekg(skipMaxLen);
	//
	//cout << giveUser.tellg() << "\n";

	int leng = 0;
	giveUser.read((char*)&leng, sizeof(leng));
	//
	//cout << leng << "\n";
	char* give1 = new char[leng];
	giveUser.read(give1, leng);
	cout << give1 << "\n";
	//
	//cout << giveUser.tellg() << "\n";

	int pos = giveUser.tellg();
	pos += 2;
	giveUser.seekg(pos);
	giveUser.read((char*)&leng, sizeof(leng));
	//
	//cout << leng << "\n";
	char* give2 = new char[leng];
	giveUser.read(give2, leng);
	cout << give2 << "\n";
	//
	//cout << giveUser.tellg() << "\n";

	pos = giveUser.tellg();
	pos += 2;
	giveUser.seekg(pos);
	giveUser.read((char*)&leng, sizeof(leng));
	//
	//cout << leng << "\n";
	char* give3 = new char[leng];
	giveUser.read(give3, leng);
	cout << give3 << "\n";
	//
	//cout << giveUser.tellg() << "\n";
	//cout << strlen("\n");

	delete[] give1;
	delete[] give2;
	delete[] give3;
}
User::~User()
{
	delete[] username;
}