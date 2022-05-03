#include <iostream>
#include <fstream>
#include "header.h"
using namespace std;
//file location: "C:/Users/ACER/source/repos/fmi project (1)/file.txt" !!!REPLACE EVERYWHERE WHEN USING FILE WITH DIFFERENT PATH!!!

User::User()//not logged default user
{
	username = new char[13];//name length
	strcpy_s(username, 13, "default nam1");

	password = new char[17];//password length
	strcpy_s(password, 17, "default passwor1");
	
	email = new char[14];//email length;
	strcpy_s(email, 14, "default emai1");

	//cout << username << "\n";
	//cout << password << "\n";
	//cout << email << "\n";
	//not needed stuff \/ \/ \/
	//ofstream first("C:/Users/ACER/source/repos/fmi project (1)/file.txt", ios::out);
	//int temp = 0;
	//first.write((char*)&temp, sizeof(temp));
}
void User::writeUser()//for saving new users in the end of the file (after the last user)
{
	ofstream writeNewUser("C:/Users/ACER/source/repos/fmi project (1)/file.txt", ios::app);
	int maxLeng = strlen(username) + 1 + strlen(password) + 1 + strlen(email) + 1 + (3 * 4) + (3 * 2);//each char array + "\0" from each array + every number telling the array size + every "\n"
	writeNewUser.write((char*)&maxLeng, sizeof(maxLeng));
	//writing username
	int leng = strlen(username) + 1;
	writeNewUser.write((char*)&leng, sizeof(leng));
	writeNewUser.write(username, leng).write("\n", 1);
	//writing password
	leng = strlen(password) + 1;
	writeNewUser.write((char*)&leng, sizeof(leng));
	writeNewUser.write(password, leng).write("\n", 1);
	//writing email
	leng = strlen(email) + 1;
	writeNewUser.write((char*)&leng, sizeof(leng));
	writeNewUser.write(email, leng).write("\n", 1);
	writeNewUser.close();
}
void User::giveUser(int position)//from the file
{
	while (position < 0)
	{
		//write validation later
	}
	ifstream giveUser("C:/Users/ACER/source/repos/fmi project (1)/file.txt", ios::in);
	for (int i = 0; i < position; i++)//this starts to skip users from the first one
	{
		int tempLen = 0;
		giveUser.read((char*)&tempLen, sizeof(tempLen));
		int tempTellg = giveUser.tellg();
		giveUser.seekg(tempLen + tempTellg);

		//giveUser.seekg(66);
	}
	//skipping the maxLen variable
	int skipMaxLen = giveUser.tellg();
	skipMaxLen += 4;
	giveUser.seekg(skipMaxLen);
	//giving username
	int leng = 0;
	giveUser.read((char*)&leng, sizeof(leng));
	char* give1 = new char[leng];
	giveUser.read(give1, leng);
	cout << give1 << "\n";
	//giving password
	int pos = giveUser.tellg();
	pos += 2;
	giveUser.seekg(pos);
	giveUser.read((char*)&leng, sizeof(leng));
	char* give2 = new char[leng];
	giveUser.read(give2, leng);
	cout << give2 << "\n";
	//giving email
	pos = giveUser.tellg();
	pos += 2;
	giveUser.seekg(pos);
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